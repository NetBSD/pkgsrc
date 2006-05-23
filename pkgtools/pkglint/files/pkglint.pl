#! @PERL@
# $NetBSD: pkglint.pl,v 1.590 2006/05/23 09:12:35 rillig Exp $
#

# pkglint - static analyzer and checker for pkgsrc packages
#
# Written by:
#	Roland Illig <rillig@NetBSD.org>
#
# Based on work by:
#	Hubert Feyrer <hubertf@NetBSD.org>
#	Thorsten Frueauf <frueauf@NetBSD.org>
#	Thomas Klausner <wiz@NetBSD.org>
#	and others.
#
# Based on FreeBSD's portlint by:
#	Jun-ichiro itojun Hagino <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
#
#	FreeBSD Id: portlint.pl,v 1.64 1998/02/28 02:34:05 itojun Exp
#	Copyright(c) 1997 by Jun-ichiro Hagino <itojun@itojun.org>.
#	All rights reserved.
#	Freely redistributable.  Absolutely no warranty.

#==========================================================================
# Note: The @EXPORT clauses in the packages must be in a BEGIN block,
# because otherwise the names starting with an uppercase letter are not
# recognized as subroutines but as file handles.
#==========================================================================

use strict;
use warnings;

package PkgLint::Util;
#==========================================================================
# This package is a catch-all for subroutines that are not application-spe-
# cific. Currently it contains the boolean constants C<false> and C<true>,
# as well as a function to print text in a table format, and a function
# that converts an array into a hash. The latter is just for convenience
# because I don't know of a Perl operator similar to qw() that can be used
# for creating a hash.
#==========================================================================
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		assert
		false true
		min max
		array_to_hash print_table
	);
}

use constant false	=> 0;
use constant true	=> 1;

sub assert($) {
	my ($cond) = @_;
	my (@callers, $n);

	if (!$cond) {
		print STDERR ("FATAL: Assertion failed.\n");

		for ($n = 0; my @info = caller($n); $n++) {
			push(@callers, [$info[2], $info[3]]);
		}

		for (my $i = $#callers; $i >= 0; $i--) {
			my $info = $callers[$i];
			printf STDERR ("  at line %4d in %s\n", $info->[0], $info->[1]);
		}
		exit(1);
	}
}

sub min($$) {
	my ($a, $b) = @_;

	return ($a < $b) ? $a : $b;
}

sub max($$) {
	my ($a, $b) = @_;

	return ($a > $b) ? $a : $b;
}

# Prints the C<$table> on the C<$out> stream. The C<$table> shall be an
# array of rows, each row shall be an array of cells, and each cell shall
# be a string.
sub print_table($$) {
	my ($out, $table) = @_;
	my (@width) = ();
	foreach my $row (@{$table}) {
		foreach my $i (0..$#{$row}) {
			if (!defined($width[$i]) || length($row->[$i]) > $width[$i]) {
				$width[$i] = length($row->[$i]);
			}
		}
	}
	foreach my $row (@{$table}) {
		my ($max) = ($#{$row});
		foreach my $i (0..$max) {
			if ($i != 0) {
				print $out ("  ");
			}
			print $out ($row->[$i]);
			if ($i != $max) {
				print $out (" " x ($width[$i] - length($row->[$i])));
			}
		}
		print $out ("\n");
	}
}

sub array_to_hash(@) {
	my ($result) = {};

	foreach my $arg (@_) {
		$result->{$arg} = 1;
	}
	return $result;
}

#== End of PkgLint::Util ==================================================

package PkgLint::Logging;
#==========================================================================
# This package provides subroutines for printing messages to the user in a
# common format. The subroutines all have the parameters C<$fname>,
# C<$lineno> and C<$message>. In case there's no appropriate filename for
# the message, NO_FILE may be passed, likewise for C<$lineno> and
# NO_LINES. Before printing, the filename is normalized, that is,
# "/foo/bar/../../" components are removed, as well as "." components.
# At the end of the program, the subroutine print_summary_and_exit should
# be called.
#
# Examples:
#   log_error(NO_FILE, NO_LINES, "Invalid command line.");
#   log_warning($fname, NO_LINES, "Not found.");
#   log_info($fname, $lineno, sprintf("invalid character (0x%02x).", $c));
#==========================================================================

use strict;
use warnings;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		NO_FILE NO_LINE_NUMBER NO_LINES
		log_fatal log_error log_warning log_note log_info log_debug
		explain_error explain_warning explain_info
		print_summary_and_exit set_verbosity get_verbosity
		set_explain set_gcc_output_format
		get_show_source_flag set_show_source_flag
		get_klickibunti_flag set_klickibunti_flag
	);
	import PkgLint::Util qw(
		false true
	);
}

use constant NO_FILE		=> undef;
use constant NO_LINE_NUMBER	=> undef;
use constant NO_LINES		=> undef;

use constant LL_FATAL		=> 0;
use constant LL_ERROR		=> 1;
use constant LL_WARNING		=> 2;
use constant LL_INFO		=> 3;
use constant LL_NOTE		=> 4;
use constant LL_DEBUG		=> 5;

use constant traditional_type	=> ["FATAL", "ERROR", "WARN", "OK", "NOTE", "DEBUG"];
use constant gcc_type		=> ["fatal", "error", "warning", "info", "note", "debug"];

my $errors		= 0;
my $warnings		= 0;
my $verbosity		= 0;
my $gcc_output_format	= false;
my $klickibunti_flag	= false;
my $explain_flag	= false;
my $show_source_flag	= false;
my $frequency		= {};	# Frequencies of the messages.

sub strxvis($) {
	my ($s) = @_;

	$s =~ s/([^\x09\x20-\x7e])/"\\x" . unpack("H*", $1)/eg;
	return $s;
}

sub log_message($$$$) {
	my ($level, $fname, $lineno, $message) = @_;
	my ($text, $sep);

	if (defined($fname)) {
		# strip "." path components
		$fname =~ s,^(?:\./)+,,;
		$fname =~ s,/(?:\./)+,/,g;
		$fname =~ s,/+,/,g;

		# strip intermediate "../.." path components
		while ($fname =~ s,/[^.][^/]*/[^.][^/]*/\.\./\.\./,/,) {
		}
	}

	$text = "";
	$sep = "";
	if (!$gcc_output_format) {
		$text .= "${sep}" . traditional_type->[$level] . ":";
		$sep = " ";
	}
	if (defined($fname)) {
		$text .= defined($lineno)
		    ? "${sep}${fname}:${lineno}"
		    : "${sep}${fname}";
		$sep = ": ";
	}
	if ($gcc_output_format) {
		$text .= "${sep}" . gcc_type->[$level] . ":";
		$sep = " ";
	}
	if (defined($message)) {
		$text .= $sep . strxvis($message);
		$sep = "";

		if ($level == LL_ERROR || $level == LL_WARNING) {
			$frequency->{$message}++;
		}
	}

	if ($level == LL_FATAL) {
		print STDERR ("${text}\n");
	} else {
		print STDOUT ("${text}\n");
	}
}

sub log_fatal($$$) {
	my ($fname, $lineno, $msg) = @_;
	log_message(LL_FATAL, $fname, $lineno, $msg);
	exit(1);
}

sub log_error($$$) {
	my ($fname, $lineno, $msg) = @_;
	log_message(LL_ERROR, $fname, $lineno, $msg);
	$errors++;
}
sub log_warning($$$) {
	my ($fname, $lineno, $msg) = @_;
	log_message(LL_WARNING, $fname, $lineno, $msg);
	$warnings++;
}
sub log_note($$$) {
	my ($fname, $lineno, $msg) = @_;
	log_message(LL_NOTE, $fname, $lineno, $msg);
}
sub log_info($$$) {
	my ($fname, $lineno, $msg) = @_;
	if ($verbosity >= 1) {
		log_message(LL_INFO, $fname, $lineno, $msg);
	}
}
sub log_debug($$$) {
	my ($fname, $lineno, $msg) = @_;
	if ($verbosity >= 2) {
		log_message(LL_DEBUG, $fname, $lineno, $msg);
	}
}

sub explain($$@) {
	my ($loglevel, $fname, $lines, @texts) = @_;
	my $out = ($loglevel == LL_FATAL) ? *STDERR : *STDOUT;

	if ($explain_flag) {
		foreach my $text (@texts) {
			print $out ("\t${text}\n");
		}
	}
}
sub explain_error($$@) {
	my ($fname, $lines, @texts) = @_;
	explain(LL_ERROR, $fname, $lines, @texts);
}
sub explain_warning($$@) {
	my ($fname, $lines, @texts) = @_;
	explain(LL_WARNING, $fname, $lines, @texts);
}
sub explain_note($$@) {
	my ($fname, $lines, @texts) = @_;
	explain(LL_NOTE, $fname, $lines, @texts);
}
sub explain_info($$@) {
	my ($fname, $lines, @texts) = @_;
	if ($verbosity >= 1) {
		explain(LL_INFO, $fname, $lines, @texts);
	}
}

sub print_summary_and_exit($) {
	my ($quiet) = @_;

	if (!$quiet) {
		if ($errors != 0 || $warnings != 0) {
			if ($verbosity >= 1) {
				print("Statistics of issued diagnostics:\n");
				foreach my $msg (sort { $frequency->{$b} <=> $frequency->{$a} } (keys(%{$frequency}))) {
					printf("%8d: %s\n", $frequency->{$msg}, $msg);
				}
			}

			print("$errors errors and $warnings warnings found.\n");
		} else {
			print "looks fine.\n";
		}
	}
	exit($errors != 0);
}

sub get_verbosity()		{ return $verbosity; }
sub set_verbosity($)		{ ($verbosity) = @_; }
sub set_explain()		{ $explain_flag = true; }
sub set_gcc_output_format()	{ $gcc_output_format = true; }
sub get_klickibunti_flag()	{ return $klickibunti_flag; }
sub set_klickibunti_flag()	{ $klickibunti_flag = true; }
sub get_show_source_flag()	{ return $show_source_flag; }
sub set_show_source_flag()	{ $show_source_flag = true; }

#== End of PkgLint::Logging ===============================================

#==========================================================================
# A File is a structure containing the contents of a file:
#	name:	string			The name of the file.
#	lines:	array of string		The physical lines in the file.
#==========================================================================
package PkgLint::File;

use constant NAME	=> 0;
use constant LINES	=> 1;

sub new($$$) {
	my ($class, $name, $lines) = @_;
	my $self = [$name, $lines];
	bless($self, $class);
	return $self;
}

sub name($)		{ return shift(@_)->[NAME]; }
sub lines($)		{ return shift(@_)->[LINES]; }

sub load($$) {
	my ($self, $fname) = @_;
	my ($lines);

	$lines = [];
	open(F, "<", $fname) or return undef;
	while (defined(my $line = <F>)) {
		push(@{$lines}, $line);
	}
	close(F) or return undef;

	$self->[NAME] = $fname;
	$self->[LINES] = $lines;
	return $self;
}

#==========================================================================
# A Location is a structure containing a location in a file:
#	lineno:	int			The line number in the file
#	colno:	int			The column number in the file
#==========================================================================
package PkgLint::Location;

use constant LINENO	=> 0;
use constant COLNO	=> 1;

sub new($$$$) {
	my ($class, $lineno, $colno) = @_;
	my ($self) = ([$lineno, $colno]);
	bless($self, $class);
	return $self;
}

sub lineno($)		{ return shift(@_)->[LINENO]; }
sub colno($)		{ return shift(@_)->[COLNO]; }

#==========================================================================
# A SimpleMatch is the result of applying a regular expression to a Perl
# scalar value. It can return the range and the text of the captured
# groups.
#==========================================================================
package PkgLint::SimpleMatch;

use constant STRING	=> 0;
use constant STARTS	=> 1;
use constant ENDS	=> 2;
use constant N		=> 3;

sub new($$) {
	my ($class, $string, $starts, $ends) = @_;
	my ($self) = ([$string, [@{$starts}], [@{$ends}], $#{$ends}]);
	bless($self, $class);
	return $self;
}

sub string($)		{ return shift(@_)->[STRING]; }
sub n($)		{ return shift(@_)->[N]; }

sub has($$) {
	my ($self, $n) = @_;

	return 0 <= $n && $n <= $self->n
	    && defined($self->[STARTS]->[$n])
	    && defined($self->[ENDS]->[$n]);
}

sub text($$) {
	my ($self, $n) = @_;

	my $start = $self->[STARTS]->[$n];
	my $end = $self->[ENDS]->[$n];
	return substr($self->string, $start, $end - $start);
}

sub range($$) {
	my ($self, $n) = @_;

	return ($self->[STARTS]->[$n], $self->[ENDS]->[$n]);
}

#==========================================================================
# A StringMatch is the result of applying a regular expression to a String.
# It can return the range and the text of the captured groups.
#==========================================================================
package PkgLint::StringMatch;

use constant STRING	=> 0;
use constant STARTS	=> 1;
use constant ENDS	=> 2;

sub new($$) {
	my ($class, $string, $starts, $ends) = @_;
	my ($self) = ([$string, [@{$starts}], [@{$ends}]]);
	bless($self, $class);
	return $self;
}

sub string($)		{ return shift(@_)->[STRING]; }

sub text($$) {
	my ($self, $n) = @_;

	my $start = $self->[STARTS]->[$n];
	my $end = $self->[ENDS]->[$n];
	return $self->string->substring($start, $end - $start)->text;
}

sub range($$) {
	my ($self, $n) = @_;

	return ($self->[STARTS]->[$n], $self->[ENDS]->[$n]);
}

sub highlight($$) {
	my ($self, $n) = @_;

	$self->string->highlight(0, $self->[STARTS]->[$n], $self->[ENDS]->[$n]);
}

#==========================================================================
# When files are read in by pkglint, they are interpreted in terms of
# lines. For Makefiles, line continuations are handled properly, allowing
# multiple physical lines to end in a single logical line. For other files
# there is a 1:1 translation.
#
# A difference between the physical and the logical lines is that the
# physical lines include the line end sequence, whereas the logical lines
# do not.
#
# A logical line is a class having the read-only fields C<file>,
# C<lines>, C<text>, C<physlines> and C<is_changed>, as well as some
# methods for printing diagnostics easily.
#
# Some other methods allow modification of the physical lines, but leave
# the logical line (the C<text>) untouched. These methods are used in the
# --autofix mode.
#==========================================================================
package PkgLint::Line;

BEGIN {
	import PkgLint::Util qw(
		false true
	);
}

use constant FNAME	=> 0;
use constant LINES	=> 1;
use constant TEXT	=> 2;
use constant PHYSLINES	=> 3;
use constant CHANGED	=> 4;
use constant BEFORE	=> 5;
use constant AFTER	=> 6;

sub new($$$$) {
	my ($class, $fname, $lines, $text, $physlines) = @_;
	my ($self) = ([$fname, $lines, $text, $physlines, false, [], []]);
	bless($self, $class);
	return $self;
}

sub fname($)		{ return shift(@_)->[FNAME]; }
sub lines($)		{ return shift(@_)->[LINES]; }
sub text($)		{ return shift(@_)->[TEXT]; }
# Note: physlines is _not_ a usual getter method.
sub is_changed($)	{ return shift(@_)->[CHANGED]; }

sub physlines($) {
	my ($self) = @_;
	return [@{$self->[BEFORE]}, @{$self->[PHYSLINES]}, @{$self->[AFTER]}];
}

# Only for PkgLint::String support
sub substring($$$$) {
	my ($self, $line, $start, $end) = @_;
	my ($text, $physlines);

	return substr($self->[PHYSLINES]->[$line]->[1], $start, $end);
}

sub show_source($$) {
	my ($self, $out) = @_;

	if (PkgLint::Logging::get_show_source_flag()) {
		foreach my $line (@{$self->physlines}) {
			print $out ("> " . $line->[1]);
		}
	}
}

sub log_fatal($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDERR);
	PkgLint::Logging::log_fatal($self->fname, $self->[LINES], $text);
}
sub log_error($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_error($self->fname, $self->[LINES], $text);
}
sub log_warning($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_warning($self->fname, $self->[LINES], $text);
}
sub log_note($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_note($self->fname, $self->[LINES], $text);
}
sub log_info($$) {
	my ($self, $text) = @_;
	if (PkgLint::Logging::get_verbosity() >= 1) {
		$self->show_source(*STDOUT);
	}
	PkgLint::Logging::log_info($self->fname, $self->[LINES], $text);
}
sub log_debug($$) {
	my ($self, $text) = @_;
	if (PkgLint::Logging::get_verbosity() >= 2) {
		$self->show_source(*STDOUT);
	}
	PkgLint::Logging::log_debug($self->fname, $self->[LINES], $text);
}
sub explain_error($@) {
	my ($self, @texts) = @_;
	PkgLint::Logging::explain_error($self->fname, $self->[LINES], @texts);
}
sub explain_warning($@) {
	my ($self, @texts) = @_;
	PkgLint::Logging::explain_warning($self->fname, $self->[LINES], @texts);
}
sub explain_note($@) {
	my ($self, @texts) = @_;
	PkgLint::Logging::explain_note($self->fname, $self->[LINES], @texts);
}
sub explain_info($@) {
	my ($self, @texts) = @_;
	PkgLint::Logging::explain_info($self->fname, $self->[LINES], @texts);
}

sub to_string($) {
	my ($self) = @_;
	return $self->fname . ":" . $self->[LINES] . ": " . $self->[TEXT];
}

sub prepend_before($$) {
	my ($self, $text) = @_;
	unshift(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_before($$) {
	my ($self, $text) = @_;
	push(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub prepend_after($$) {
	my ($self, $text) = @_;
	unshift(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_after($$) {
	my ($self, $text) = @_;
	push(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub delete($) {
	my ($self) = @_;
	$self->[PHYSLINES] = [];
	$self->[CHANGED] = true;
}
sub replace($$$) {
	my ($self, $from, $to) = @_;
	my $phys = $self->[PHYSLINES];
	foreach my $i (0..$#{$phys}) {
		if ($phys->[$i]->[0] != 0 && $phys->[$i]->[1] =~ s/\Q$from\E/$to/g) {
			$self->[CHANGED] = true;
		}
	}
}
sub replace_regex($$$) {
	my ($self, $from_re, $to) = @_;
	my $phys = $self->[PHYSLINES];

	foreach my $i (0..$#{$phys}) {
		if ($phys->[$i]->[0] != 0 && $phys->[$i]->[1] =~ s/$from_re/$to/) {
			$self->[CHANGED] = true;
		}
	}
}
sub set_text($$) {
	my ($self, $text) = @_;
	$self->[PHYSLINES] = [[0, "$text\n"]];
	$self->[CHANGED] = true;
}

#== End of PkgLint::Line ==================================================

package PkgLint::String;
#==========================================================================
# In pkglint, a String is a part of a Line that contains exact references
# to the locations of its substrings in the physical lines of the file from
# which it has been read. This makes it possible for diagnostics to be
# marked at character level instead of logical line level.
#
# Implementation notes:
#
# A String consists of three components:
# * a reference to a logical line,
# * a list of Parts, which, when concatenated, form the text of the String.
#   A Part is either a literal string or an array of the form [$lineno,
#   $startcol, $endcol], which is used as a reference into the physical
#   lines array (without and local additions) of the logical line.
# * a list of highlighting intervals, which are used in the
#   show_highlighted() method to mark up certain parts of the string.
#==========================================================================

BEGIN {
	import PkgLint::Util qw(
		false true
		min max
	);
}

use constant LINE	=> 0;
use constant PARTS	=> 1;
use constant MARKUPS	=> 2;

# The structure fields of a Part of a String
use constant P_LINENO	=> 0;
use constant P_STARTCOL	=> 1;
use constant P_ENDCOL	=> 2;

# The structure fields of a MarkupPoint of a String
use constant MP_LINENO	=> 0;
use constant MP_COLNO	=> 1;
use constant MP_TEXT	=> 2;

sub new($$@) {
	my ($class, $line, @parts) = @_;
	my ($self) = ([$line, \@parts]);
	bless($self, $class);
	$self->compress();
	return $self;
}

sub line($)		{ return shift(@_)->[LINE]; }
sub parts($)		{ return shift(@_)->[PARTS]; }

sub text($) {
	my ($self) = @_;
	my ($text);

	$text = "";
	foreach my $part (@{$self->[PARTS]}) {
		if (ref($part) eq "") {
			$text .= $part;
		} else {
			$text .= $self->line->substring($part->[P_LINENO], $part->[P_STARTCOL], $part->[P_ENDCOL] - $part->[P_STARTCOL]);
		}
	}
	return $text;
}

sub substring($$$) {
	my ($self, $from, $len) = @_;
	my (@nparts, $skip, $take, $physlines);

	# XXX: This code is slow, but simple.

	$physlines = $self->[LINE]->[PkgLint::Line::PHYSLINES];

	$skip = $from;
	$take = defined($len) ? $len : 0x7fff_ffff;
	foreach my $part (@{$self->[PARTS]}) {
		if (ref($part) eq "") {
			my $p = "";

			my $nskipped = min($skip, strlen($part));
			$skip -= $nskipped;
			$part = substr($part, $nskipped);

			my $ntaken = min($take, strlen($part));
			$take -= $ntaken;
			$p .= substr($part, 0, $ntaken);
			$part = substr($part, $ntaken);

			push(@nparts, $p);
		} else {
			my $line = $part->[P_LINENO];
			my $col = $part->[P_STARTCOL];
			my $tocol = $part->[P_ENDCOL];
			my $linelen = length($physlines->[$line]->[1]);

			my $nskipped = max(0, min($skip, min($tocol - $col, $linelen - $col)));
			$skip -= $nskipped;
			$col += $nskipped;

			my $start = $col;

			my $ntaken = max(0, min($take, min($tocol - $col, $linelen - $col)));
			$take -= $ntaken;
			$col += $ntaken;

			my $end = $col;
			push(@nparts, [$line, $start, $end]);
		}
	}
	return PkgLint::String->new($self->[LINE], @nparts);
}

sub match($$) {
	my ($self, $re) = @_;
	my ($m);

	if ($self->text !~ $re) {
		return false;
	}

	# @- and @+ are very special arrays, so we better copy them
	# before doing anything with them.
	my @starts = @-;
	my @ends = @+;
	return PkgLint::StringMatch->new($self, \@starts, \@ends);
}

sub match_all($$) {
	my ($self, $re) = @_;
	my ($mm, $rest, $lastpos);

	$mm = [];
	$rest = $self->text;
	$lastpos = 0;
	pos(undef);
	while ($rest =~ m/$re/gc) {
		my @starts = @-;
		my @ends = @+;

		$lastpos = $ends[0];

		push(@{$mm}, PkgLint::StringMatch->new($self, \@starts, \@ends));
	}
	return ($mm, substr($rest, $lastpos));
}

sub compress($) {
	my ($self) = @_;
	my ($parts, @nparts);

	$parts = $self->[PARTS];

	# Copy all but empty parts into nparts.
	foreach my $part (@{$parts}) {
		if (ref($part) eq "") {
			if ($part ne "") {
				push(@nparts, $part);
			}
		} else {
			if ($part->[P_STARTCOL] != $part->[P_ENDCOL]) {
				push(@nparts, $part);
			}
		}
	}
	$self->[PARTS] = \@nparts;

	# TODO: Merge adjacent parts
}

# FIXME: lineno should not be needed here.
sub highlight($$$$) {
	my ($self, $lineno, $startcol, $endcol) = @_;

	push(@{$self->[MARKUPS]}, [$lineno, $startcol, $endcol]);
}

sub show_highlighted($$) {
	my ($self) = @_;
	my ($physlines, @points, $curpoint, $maxpoint, $text, $physline, $col);

	return unless (PkgLint::Logging::get_show_source_flag() && PkgLint::Logging::get_klickibunti_flag());

	foreach my $m (@{$self->[MARKUPS]}) {
		push(@points, [$m->[P_LINENO], $m->[P_STARTCOL], "\x1B[33m\x1B[1m"]);
		push(@points, [$m->[P_LINENO], $m->[P_ENDCOL], "\x1B[0m"]);
	}

	@points = sort {
		$a->[MP_LINENO] <=> $b->[MP_LINENO]
		|| $a->[MP_COLNO] <=> $b->[MP_COLNO];
	} (@points);

	$physlines = $self->line->[PkgLint::Line::PHYSLINES];
	$curpoint = 0;
	$maxpoint = $#points + 1;
	foreach my $lineno (0..$#{$physlines}) {
		while ($curpoint < $maxpoint && $points[$curpoint]->[MP_LINENO] < $lineno) {
			$curpoint++;
		}

		$text = "";
		$col = 0;
		$physline = $physlines->[$lineno];
		while ($curpoint < $maxpoint && $points[$curpoint]->[MP_LINENO] == $lineno) {
			$text .= substr($physline->[1], $col, $points[$curpoint]->[MP_COLNO] - $col);
			$text .= $points[$curpoint]->[MP_TEXT];
			$col = $points[$curpoint]->[MP_COLNO];
			$curpoint++;
		}
		$text .= substr($physline->[1], $col);
		print("> $text");
	}
}

# TODO: Rewrite the code of log_warning to be shorter. After that is
# done, add the other log_* methods.

sub log_warning($$) {
	my ($self, $msg) = @_;

	if (PkgLint::Logging::get_show_source_flag()) {
		if (PkgLint::Logging::get_klickibunti_flag()) {
			$self->show_highlighted();
		} else {
			$self->line->show_source(*STDOUT);
		}
	}
	PkgLint::Logging::log_warning($self->line->fname, $self->line->lines, $msg);
}

#== End of PkgLint::String ================================================

package PkgLint::FileUtil;
#==========================================================================
# This package provides subroutines for loading and saving line-oriented
# files. The load_file() subroutine loads a file completely into memory,
# optionally handling continuation line folding. The load_lines() subrou-
# tine is an abbreviation for the common case of loading files without
# continuation lines. The save_autofix_changes() subroutine examines an
# array of lines if some of them have changed. It then saves the modified
# files.
#==========================================================================
use strict;
use warnings;

BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		load_file load_lines
		save_autofix_changes
	);

	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		NO_LINE_NUMBER
		log_error log_note
	);
}

sub load_physical_lines($) {
	my ($fname) = @_;
	my ($physlines, $line, $lineno);

	$physlines = [];
	open(F, "< $fname") or return undef;
	$lineno = 0;
	while (defined($line = <F>)) {
		$lineno++;
		push(@{$physlines}, [$lineno, $line]);
	}
	close(F) or return undef;
	return $physlines;
}

sub get_logical_line($$$) {
	my ($fname, $lines, $ref_lineno) = @_;
	my ($value, $lineno, $first, $firstlineno, $lastlineno, $physlines);

	$value = "";
	$first = true;
	$lineno = ${$ref_lineno};
	$firstlineno = $lines->[$lineno]->[0];
	$physlines = [];

	for (; $lineno <= $#{$lines}; $lineno++) {
		if ($lines->[$lineno]->[1] =~ qr"^([ \t]*)(.*?)([ \t]*)(\\?)\n?$") {
			my ($indent, $text, $outdent, $cont) = ($1, $2, $3, $4);

			if ($first) {
				$value .= $indent;
				$first = false;
			}

			$value .= $text;
			push(@{$physlines}, $lines->[$lineno]);

			if ($cont eq "\\") {
				$value .= " ";
			} else {
				$value .= $outdent;
				last;
			}
		}
	}

	if ($lineno > $#{$lines}) {
		# The last line in the file is a continuation line
		$lineno--;
	}
	$lastlineno = $lines->[$lineno]->[0];
	${$ref_lineno} = $lineno + 1;

	return PkgLint::Line->new($fname,
	    $firstlineno == $lastlineno
		? $firstlineno
		: "$firstlineno--$lastlineno",
	    $value,
	    $physlines);
}

sub load_lines($$) {
	my ($fname, $fold_backslash_lines) = @_;
	my ($physlines, $seen_newline, $loglines) = @_;

	$physlines = load_physical_lines($fname);
	if (!$physlines) {
		return false;
	}

	$seen_newline = true;
	$loglines = [];
	if ($fold_backslash_lines) {
		for (my $lineno = 0; $lineno <= $#{$physlines}; ) {
			push(@{$loglines}, get_logical_line($fname, $physlines, \$lineno));
		}
	} else {
		foreach my $physline (@{$physlines}) {
			my $text = $physline->[1];

			$text =~ s/\n$//;
			push(@{$loglines}, PkgLint::Line->new($fname, $physline->[0], $text, [$physline]));
		}
	}

	if (0 <= $#{$physlines} && $physlines->[-1]->[1] !~ qr"\n$") {
		log_error($fname, $physlines->[-1]->[0], "File must end with a newline.");
	}

	return $loglines;
}

sub load_file($) {
	my ($fname) = @_;

	return load_lines($fname, false);
}

sub get_folded_string($$$) {
	my ($fname, $lines, $ref_lineno) = @_;
	my ($value, $lineno, $first, $firstlineno, $lastlineno, $physline, $physlines, @parts);

	$value = "";
	$first = true;
	$lineno = ${$ref_lineno};
	$firstlineno = $lines->[$lineno]->[0];
	$physlines = [];
	$physline = 0;

	for (; $lineno <= $#{$lines}; $lineno++) {
		if ($lines->[$lineno]->[1] =~ qr"^([ \t]*)(.*?)([ \t]*)(\\?)\n?$") {
			my ($indent, $text, $outdent, $cont) = ($1, $2, $3, $4);
			my (@start) = (@-);
			my (@end) = (@+);

			if ($first) {
				$value .= $indent;
				push(@parts, [$physline, $start[1], $end[1]]);
				$first = false;
			}

			$value .= $text;
			push(@parts, [$physline, $start[2], $end[2]]);

			push(@{$physlines}, $lines->[$lineno]);
			$physline++;

			if ($cont eq "\\") {
				$value .= " ";
				push(@parts, " ");
			} else {
				$value .= $outdent;
				push(@parts, [$physline, $start[3], $end[3]]);
				last;
			}
		}
	}

	if ($lineno > $#{$lines}) {
		# The last line in the file is a continuation line
		$lineno--;
	}
	$lastlineno = $lines->[$lineno]->[0];
	${$ref_lineno} = $lineno + 1;

	my $line = PkgLint::Line->new($fname,
	    $firstlineno == $lastlineno
		? $firstlineno
		: "$firstlineno--$lastlineno",
	    $value,
	    $physlines);
	return PkgLint::String->new($line, @parts);
}

sub load_strings($$) {
	my ($fname, $fold_backslash_lines) = @_;
	my ($physlines, $seen_newline, $strings) = @_;

	$physlines = load_physical_lines($fname);
	if (!$physlines) {
		return false;
	}

	$seen_newline = true;
	$strings = [];
	if ($fold_backslash_lines) {
		for (my $lineno = 0; $lineno <= $#{$physlines}; ) {
			push(@{$strings}, get_folded_string($fname, $physlines, \$lineno));
		}
	} else {
		foreach my $physline (@{$physlines}) {
			my ($text, $line);

			($text = $physline->[1]) =~ s/\n$//;
			$line = PkgLint::Line->new($fname, $physline->[0], $text, [$physline]);
			push(@{$strings}, PkgLint::String->new($line, [0, 0, length($text)]));
		}
	}

	if (0 <= $#{$physlines} && $physlines->[-1]->[1] !~ qr"\n$") {
		log_error($fname, $physlines->[-1]->[0], "File must end with a newline.");
	}

	return $strings;
}

sub save_autofix_changes($) {
	my ($lines) = @_;

	my (%changed, %physlines);

	foreach my $line (@{$lines}) {
		if ($line->is_changed) {
			$changed{$line->fname}++;
		}
		push(@{$physlines{$line->fname}}, @{$line->physlines});
	}

	foreach my $fname (sort(keys(%changed))) {
		my $new = "${fname}.pkglint.tmp";

		if (!open(F, ">", $new)) {
			log_error($new, NO_LINE_NUMBER, "$!");
			next;
		}
		foreach my $physline (@{$physlines{$fname}}) {
			print F ($physline->[1]);
		}
		if (!close(F)) {
			log_error($new, NO_LINE_NUMBER, "$!");
			next;
		}

		if (!rename($new, $fname)) {
			log_error($fname, NO_LINE_NUMBER, "$!");
			next;
		}
		log_note($fname, NO_LINE_NUMBER, "Has been autofixed. Please re-run pkglint.");
	}
}

#== End of PkgLint::FileUtil ==============================================

package PkgLint::Type;

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		log_warning NO_LINES
	);
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		LK_NONE LK_INTERNAL LK_EXTERNAL
	);
}

use constant KIND_OF_LIST	=> 0;
use constant   LK_NONE		=> 0;
use constant   LK_INTERNAL	=> 1;
use constant   LK_EXTERNAL	=> 2;
use constant BASIC_TYPE		=> 1;
use constant ACLS		=> 2; # Array of ACL entries
use constant   ACL_SUBJECT_RE	=> 0;
use constant   ACL_PERMS	=> 1;

sub new($$$) {
	my ($class, $kind_of_list, $basic_type, $acls) = @_;
	my ($self) = ([$kind_of_list, $basic_type, $acls]);
	bless($self, $class);
	return $self;
}

sub kind_of_list($)	{ return shift(@_)->[KIND_OF_LIST]; }
sub basic_type($)	{ return shift(@_)->[BASIC_TYPE]; }

sub perms($$) {
	my ($self, $fname, $varcanon) = @_;
	my ($perms);

	foreach my $acl_entry (@{$self->[ACLS]}) {
		if ($fname =~ $acl_entry->[0]) {
			return $acl_entry->[1];
		}
	}
	return undef;
}

#== End of PkgLint::Type ==================================================

package main;
#==========================================================================
# This package contains the application-specific code of pkglint.
# Most subroutines in this package follow a strict naming convention:
#
# The get_*() functions provide easy access to important non-trivial data
# structures that are loaded from external files and are therefore cached.
#
# The is_*() functions return a boolean value and have no side effects.
#
# The checkline_*() procedures check a single line for compliance with some
# rules.
#
# The checklines_*() procedures check an array of lines for compliance.
# Usually they make use of several checkline_*() procedures.
#
# The checkfile_*() procedures load a file and check the lines of that
# file. Usually they make use of several checklines_*() and checkline_*()
# procedures.
#
# The checkdir_*() procedures check the files of a directory and call
# checkfile_*() on them.
#
# Note: I have tried to order the subroutines so that there are no
# back-references, that is, if you start reading the code from the top to
# the bottom you should not find a call to a subroutine you haven't yet
# seen.
#==========================================================================
use strict;
use warnings;

use Digest::SHA1;
use Getopt::Long qw(:config no_ignore_case bundling require_order);
use Fcntl qw(:mode);
use File::Basename;
use File::stat;
use Cwd;
use pkgsrc::Dewey;

BEGIN {
	import PkgLint::Util qw(
		array_to_hash assert false true
	);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER NO_LINES
		log_fatal log_error log_warning log_note log_info log_debug
		explain_error explain_warning explain_info
	);
	import PkgLint::FileUtil qw(
		load_file load_lines
		save_autofix_changes
	);
	import PkgLint::Type qw(
		LK_NONE LK_INTERNAL LK_EXTERNAL
	);
}

#
# Buildtime configuration
#

use constant conf_distver	=> '@DISTVER@';
use constant conf_make		=> '@MAKE@';
use constant conf_datadir	=> '@DATADIR@';

#
# Command Line Options
#

my $opt_check_ALTERNATIVES = true;
my $opt_check_bl3	= true;
my $opt_check_DESCR	= true;
my $opt_check_distinfo	= true;
my $opt_check_extra	= false;
my $opt_check_INSTALL	= true;
my $opt_check_Makefile	= true;
my $opt_check_MESSAGE	= true;
my $opt_check_mk	= true;
my $opt_check_patches	= true;
my $opt_check_PLIST	= true;
my (%checks) = (
	"ALTERNATIVES"	=> [\$opt_check_ALTERNATIVES, "check ALTERNATIVES files"],
	"bl3"		=> [\$opt_check_bl3, "check buildlink3 files"],
	"DESCR"		=> [\$opt_check_DESCR, "check DESCR file"],
	"distinfo"	=> [\$opt_check_distinfo, "check distinfo file"],
	"extra"		=> [\$opt_check_extra, "check various additional files"],
	"INSTALL"	=> [\$opt_check_INSTALL, "check INSTALL and DEINSTALL scripts"],
	"Makefile"	=> [\$opt_check_Makefile, "check Makefiles"],
	"MESSAGE"	=> [\$opt_check_MESSAGE, "check MESSAGE files"],
	"mk"		=> [\$opt_check_mk, "check other .mk files"],
	"patches"	=> [\$opt_check_patches, "check patches"],
	"PLIST"		=> [\$opt_check_PLIST, "check PLIST files"],
);

my $opt_warn_absname	= true;
my $opt_warn_directcmd	= true;
my $opt_warn_extra	= false;
my $opt_warn_order	= true;
my $opt_warn_perm	= false;
my $opt_warn_plist_depr	= false;
my $opt_warn_plist_sort	= false;
my $opt_warn_quoting	= false;
my $opt_warn_space	= false;
my $opt_warn_style	= false;
my $opt_warn_types	= true;
my $opt_warn_varorder	= false;
my (%warnings) = (
	"absname"	=> [\$opt_warn_absname, "warn about use of absolute file names"],
	"directcmd"	=> [\$opt_warn_directcmd, "warn about use of direct command names instead of Make variables"],
	"extra"		=> [\$opt_warn_extra, "enable some extra warnings"],
	"order"		=> [\$opt_warn_order, "warn if Makefile entries are unordered"],
	"perm"		=> [\$opt_warn_perm, "warn about unforeseen variable definition and use"],
	"plist-depr"	=> [\$opt_warn_plist_depr, "warn about deprecated paths in PLISTs"],
	"plist-sort"	=> [\$opt_warn_plist_sort, "warn about unsorted entries in PLISTs"],
	"quoting"	=> [\$opt_warn_quoting, "warn about quoting issues"],
	"space"		=> [\$opt_warn_space, "warn about inconsistent use of white-space"],
	"style"		=> [\$opt_warn_style, "warn about stylistic issues"],
	"types"		=> [\$opt_warn_types, "do some simple type checking in Makefiles"],
	"varorder"	=> [\$opt_warn_varorder, "warn about the ordering of variables"],
);

my $opt_autofix		= false;
my $opt_debug		= false;
my $opt_dumpmakefile	= false;
my $opt_import		= false;
my $opt_klickibunti	= false;	# experimental
my $opt_quiet		= false;
my $opt_recursive	= false;
my $opt_rcsidstring	= "NetBSD";
my (@options) = (
	# [ usage-opt, usage-message, getopt-opt, getopt-action ]
	[ "-C{check,...}", "Enable or disable specific checks",
	  "check|C=s",
	  sub {
		my ($opt, $val) = @_;
		parse_multioption($val, \%checks);
	  } ],
	[ "-F|--autofix", "Try to automatically fix some errors (experimental)",
	  "autofix|F", \$opt_autofix ],
	[ "-I|--dumpmakefile", "Dump the Makefile after parsing",
	  "dumpmakefile|I", \$opt_dumpmakefile ],
	[ "-R|--rcsidstring", "Set the allowed RCS Id strings",
	  "rcsidstring|R=s", \$opt_rcsidstring ],
	[ "-V|--version", "print the version number of pkglint",
	  "version|V",
	  sub {
		print(conf_distver . "\n");
		exit(0);
	  } ],
	[ "-W{warn,...}", "enable or disable specific warnings",
	  "warning|W=s",
	  sub {
		my ($opt, $val) = @_;
		parse_multioption($val, \%warnings);
	  } ],
	[ "-d|--debug", "Print additional warnings that are mostly of use to pkglint's author",
	  "debug|d", \$opt_debug ],
	[ "-e|--explain", "Explain the diagnostics or give further help",
	  "explain|e", sub {
		PkgLint::Logging::set_explain();
	  } ],
	[ "-g|--gcc-output-format", "Mimic the gcc output format",
	  "gcc-output-format|g",
	  sub {
		PkgLint::Logging::set_gcc_output_format();
	  } ],
	[ "-h|--help", "print a detailed help message",
	  "help|h",
	  sub {
		help(*STDOUT, 0, 1);
	  } ],
	[ "-i|--import", "Prepare the import of a wip package",
	  "import|i", \$opt_import ],
	[ "-q|--quiet", "Don't print a summary line when finishing",
	  "quiet|q", \$opt_quiet ],
	[ "-r|--recursive", "Recursive---check subdirectories, too",
	  "recursive|r", \$opt_recursive ],
	[ "-s|--source", "Show the source lines together with diagnostics",
	  "source|s",
	  sub {
		PkgLint::Logging::set_show_source_flag();
	  } ],
	[ "-v|--verbose", "print progress messages",
	  "verbose|v",
	  sub {
		PkgLint::Logging::set_verbosity(PkgLint::Logging::get_verbosity() + 1);
	  } ],
	[ "--klickibunti", "Enable colored and precise diagnostics",
	  "klickibunti",
	  sub {
		PkgLint::Logging::set_klickibunti_flag();
	  } ],
);

#
# Commonly used regular expressions.
#

use constant regex_gnu_configure_volatile_vars
				=> qr"^(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$";
use constant regex_mk_cond	=> qr"^\.(\s*)(if|ifdef|ifndef|else|elif|endif|for|endfor|undef)(?:\s+([^\s#][^#]*?))?\s*(?:#.*)?$";
use constant regex_mk_dependency=> qr"^([^\s:]+(?:\s*[^\s:]+)*):\s*([^#]*?)(?:\s*#.*)?$";
use constant regex_mk_include	=> qr"^\.\s*s?include\s+\"([^\"]+)\"(?:\s*#.*)?$";
use constant regex_pkgname	=> qr"^((?:[\w.+]|-[^\d])+)-(\d(?:\w|\.\d)*)$";
use constant regex_shellcmd	=> qr"^\t(.*)$";
use constant regex_unresolved	=> qr"\$\{";
use constant regex_validchars	=> qr"[\011\040-\176]";
use constant regex_varassign	=> qr"^([-*+A-Z_a-z0-9.\${}\[]+?)\s*(=|\?=|\+=|:=|!=)\s*((?:\\#|[^#])*?)(?:\s*(#.*))?$";
use constant regex_sh_varassign	=> qr"^([A-Z_a-z][0-9A-Z_a-z]*)=";

# This "constant" is often used in contexts where interpolation comes
# handy, so it is a variable. Nevertheless it is not modified. Of course
# it cannot parse all kinds of shell programs, but this pattern will
# catch all shell programs that are portable enough to be used in pkgsrc.
my $regex_shellword		=  qr"\s*(
	(?:	'[^']*'			# single quoted string
	|	\"(?:\\.|[^\"\\])*\"	# double quoted string
	|	\`[^\`]*\`		# backticks string
	|	\\.			# any escaped character
	|	\$\{[^{}]+\}		# make(1) variable
	|	\$\([^()]+\)		# make(1) variable, $(...)
	|	\$\$[0-9A-Z_a-z]+	# shell variable
	|	\$\$\{[0-9A-Z_a-z]+\}	# shell variable in braces
	|	\$\$\(			# POSIX-style backticks replacement
	|	[^\(\)'\"\\\s;&\|<>\#\`\$] # non-special character
	|	\$\{[^\s\"'`]+		# HACK: nested make(1) variables
	)+ | ;;? | &&? | \|\|? | \( | \) | <<? | >>? | \#.*)"sx;
my $regex_varname		= qr"[-*+.0-9A-Z_a-z{}\[]+";

#
# Commonly used explanations for diagnostics.
#

use constant expl_relative_dirs	=> (
	"Directories in the form \"../../category/package\" make it easier to",
	"move a package around in pkgsrc, for example from pkgsrc-wip to the",
	"main pkgsrc repository.");

#
# Global variables.
#

my $current_dir;		# The currently checked directory.
my $is_wip;			# Is the current directory from pkgsrc-wip?
my $is_internal;		# Is the current item from the infrastructure?

my $pkgsrcdir;			# The pkgsrc root directory, relative to
				# current_dir

# Context of the package that is currently checked.
my $pkgdir;			# PKGDIR from the package Makefile
my $filesdir;			# FILESDIR from the package Makefile
my $patchdir;			# PATCHDIR from the package Makefile
my $distinfo_file;		# DISTINFO_FILE from the package Makefile
my $effective_pkgname;		# PKGNAME or DISTNAME from the package Makefile
my $effective_pkgname_line;	# The line of the definition in the Makefile
my $effective_pkgbase;		# The effective PKGNAME without the version
my $effective_pkgversion;	# The version part of the effective PKGNAME
my $hack_php_patches;		# Ignore non-existing patches in distinfo
my $seen_bsd_prefs_mk;		# Has bsd.prefs.mk already been included?

my $makevar;			# Table of variables and values
my $varuse;			# Table of used variables
my $seen_Makefile_common;	# Does the package have any .includes?

# Context in the Makefile that is currently checked.
my $mkctx_indentations;		# Indentation depth of preprocessing directives
my $mkctx_target;		# Current make(1) target

my @todo_items;			# The list of directory entries that still need
				# to be checked. Mostly relevant with
				# --recursive.

#
# Command line parsing and handling.
#

sub help($$$) {
	my ($out, $exitval, $show_all) = @_;
	my ($prog) = (basename($0));
	print $out ("usage: $prog [options] [package_directory]\n\n");

	my (@option_table) = ();
	foreach my $opt (@options) {
		push(@option_table, ["  ", $opt->[0], $opt->[1]]);
	}
	print $out ("options:\n");
	PkgLint::Util::print_table($out, \@option_table);
	print $out ("\n");

	if (!$show_all) {
		exit($exitval);
	}

	my (@checks_table) = (
		["  ", "all", "", "enable all checks"],
		["  ", "none", "", "disable all checks"],
	);
	foreach my $check (sort keys %checks) {
		push(@checks_table, [ "  ", $check,
			(${$checks{$check}->[0]} ? "(enabled)" : "(disabled)"),
			$checks{$check}->[1]]);
	}
	print $out ("checks: (use \"check\" to enable, \"no-check\" to disable)\n");
	PkgLint::Util::print_table($out, \@checks_table);
	print $out ("\n");

	my (@warnings_table) = (
		["  ", "all", "", "enable all warnings"],
		["  ", "none", "", "disable all warnings"],
	);
	foreach my $warning (sort keys %warnings) {
		push(@warnings_table, [ "  ", $warning,
			(${$warnings{$warning}->[0]} ? "(enabled)" : "(disabled)"),
			$warnings{$warning}->[1]]);
	}
	print $out ("warnings: (use \"warn\" to enable, \"no-warn\" to disable)\n");
	PkgLint::Util::print_table($out, \@warnings_table);
	print $out ("\n");

	exit($exitval);
}

sub parse_multioption($$) {
	my ($value, $optdefs) = @_;
	foreach my $opt (split(qr",", $value)) {
		if ($opt eq "none") {
			foreach my $key (keys %{$optdefs}) {
				${$optdefs->{$key}->[0]} = false;
			}

		} elsif ($opt eq "all") {
			foreach my $key (keys %{$optdefs}) {
				${$optdefs->{$key}->[0]} = true;
			}

		} else {
			my ($value) = (($opt =~ s/^no-//) ? false : true);
			if (exists($optdefs->{$opt})) {
				${$optdefs->{$opt}->[0]} = $value;
			} else {
				print STDERR ("Invalid option: ${opt}\n");
				help(*STDERR, 1, 0);
			}
		}
	}
}

sub parse_command_line() {
	my (%options);

	foreach my $opt (@options) {
		$options{$opt->[2]} = $opt->[3];
	}
	{
		local $SIG{__WARN__} = sub {};
		if (!GetOptions(%options)) {
			help(*STDERR, 1, false);
		}
	}
}

#
# Caching subroutines.
#

# The get_regex_plurals() function returns a regular expression that
# matches for all make(1) variable names that are considered lists
# of something.
#
# Rationale:
#
# The pkglint author thinks that variables containing lists of things
# should have a name indicating some plural form. Sadly, there are other
# reasons like backwards compatibility and other developer's
# expectations that make changes to most of the following variables
# highly unlikely.
my $get_regex_plurals_value = undef;
sub get_regex_plurals() {

	if (defined($get_regex_plurals_value)) {
		return $get_regex_plurals_value;
	}

	my @plurals_ok = qw(
		.*S
		.*LIST
		.*_AWK
		.*_ENV
		.*_REQD
		.*_SED
		.*_SKIP
		BUILDLINK_LDADD
		COMMENT
		EXTRACT_ONLY
		FETCH_MESSAGE
		GENERATE_PLIST
		PLIST_CAT
		PLIST_PRE
		PREPEND_PATH
	);
	my @plurals_missing_an_s = qw(
		.*_OVERRIDE
		.*_PREREQ
		.*_SRC
		.*_SUBST
		.*_TARGET
		.*_TMPL
		BUILDLINK_DEPMETHOD
		BUILDLINK_TRANSFORM
		EVAL_PREFIX
		INTERACTIVE_STAGE
		LICENSE
		MASTER_SITE_.*
		MASTER_SORT_REGEX
		NOT_FOR_COMPILER
		NOT_FOR_PLATFORM
		ONLY_FOR_COMPILER
		ONLY_FOR_PLATFORM
		PERL5_PACKLIST
		PKG_FAIL_REASON
		PKG_SKIP_REASON
	);
	my @plurals_reluctantly_accepted = qw(
		CRYPTO
		DEINSTALL_TEMPLATE
		FIX_RPATH
		INSTALL_TEMPLATE
		PYTHON_VERSIONS_INCOMPATIBLE
		REPLACE_INTERPRETER
		REPLACE_PERL
		REPLACE_RUBY
		RESTRICTED
		SITES_.*
		TOOLS_ALIASES\.*
		TOOLS_BROKEN
		TOOLS_CREATE
		TOOLS_GNU_MISSING
		TOOLS_NOOP
	);
	my $plurals = join("|",
		@plurals_ok,
		@plurals_missing_an_s,
		@plurals_reluctantly_accepted
	);

	$get_regex_plurals_value = qr"^(?:${plurals})$";
	return $get_regex_plurals_value;
}

#
# Loading pkglint-specific data from files.
#

my $get_vartypes_map_result = undef;
sub get_vartypes_map() {
	my ($fname, $vartypes);

	if (defined($get_vartypes_map_result)) {
		return $get_vartypes_map_result;
	}

	use constant re_vartypedef => qr"^
		([\w\d_.]+?)				# variable name
		(\*|\.\*|) \s+				# parameterized?
		(?:(InternalList|List) \s+ of \s+)?	# kind of list
		(?:([\w\d_]+) | \{\s*([\w\d_.+\-\s]+?)\s*\}) # basic type
		(?:\s+ \[ ([^\]]*) \])?			# optional ACL
		(?:\s*\#.*)?				# optional comment
		$"x;

	$fname = conf_datadir."/makevars.map";
	$vartypes = {};

	if ((my $lines = load_lines($fname, true))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^(?:#.*|\s*)$") {
				# ignore empty and comment lines

			} elsif ($line->text =~ re_vartypedef) {
				my ($varname, $par, $kind_of_list_text, $typename, $enums, $acltext) = ($1, $2, $3, $4, $5, $6);
				my $kind_of_list = !defined($kind_of_list_text) ? LK_NONE
				    : ($kind_of_list_text eq "List") ? LK_EXTERNAL
				    : LK_INTERNAL;
				my $acls = [];
				my $basic_type;

				if (!defined($acltext)) {
					$acltext = "";
					$acls = undef;
				}

				while ($acltext =~ s,^([\w.*]+|_):([adpsu]*)(?:\,\s*|$),,) {
					my ($subject, $perms) = ($1, $2);

					use constant ACL_shortcuts => {
						"b" => qr"(?:^|/)buildlink3\.mk$",
						"c" => qr"(?:^|/)Makefile\.common$",
						"h" => qr"(?:^|/)hacks\.mk$",
						"m" => qr"(?:^|/)Makefile$",
						"o" => qr"(?:^|/)options\.mk$",
					};

					# Transform $subject to a regular expression.
					$subject =~ s/\./[.]/g;
					$subject =~ s/\*/.*/g;

					push(@{$acls}, [exists(ACL_shortcuts->{$subject}) ? ACL_shortcuts->{$subject} : qr"(?:^|/)${subject}$", $perms]);
				}
				if ($acltext ne "") {
					$line->log_fatal("Invalid ACL: ${acltext}.");
				}
				$basic_type = defined($enums)
				    ? array_to_hash(split(qr"\s+", $enums))
				    : $typename;
				my $type = PkgLint::Type->new($kind_of_list, $basic_type, $acls);
				if ($par eq "" || $par eq "*") {
					$vartypes->{$varname} = $type;
				}
				if ($par eq "*" || $par eq ".*") {
					$vartypes->{"${varname}.*"} = $type;
				}

			} else {
				$line->log_fatal("Unknown line format.");
			}
		}
	} else {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

# TODO: Enable when the time is ripe.
if (false) {
	# Additionally, scan mk/defaults/mk.conf for variable
	# definitions. All these variables are reserved for the user and
	# must not be set within packages.
	$fname = "${current_dir}/${pkgsrcdir}/mk/defaults/mk.conf";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^#?([\w_]+)\?=") {
				my ($varname) = ($1);
				$line->log_info("Found user-definable variable ${varname}.");
				$vartypes->{$varname} = "Userdefined";
			}
		}
	} else {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}
}

	return ($get_vartypes_map_result = $vartypes);
}

my $get_deprecated_map_result = undef;
sub get_deprecated_map() {
	my ($fname, $lines, $vars);

	if (defined($get_deprecated_map_result)) {
		return $get_deprecated_map_result;
	}

	$fname = conf_datadir."/deprecated.map";
	if (!($lines = load_file($fname))) {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

	$vars = {};
	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^#" || $line->text =~ qr"^\s*$") {
			# Ignore empty and comment lines.

		} elsif ($line->text =~ qr"^(\S+)\s+(.*)$") {
			$vars->{$1} = $2;

		} else {
			$line->log_fatal("Unknown line format.");
		}
	}
	return ($get_deprecated_map_result = $vars);
}

my $load_dist_sites_url2name = undef;
my $load_dist_sites_names = undef;
sub load_dist_sites() {
	my ($fname) = ("${current_dir}/${pkgsrcdir}/mk/bsd.sites.mk");
	my ($lines) = load_file($fname);
	my ($varname) = undef;
	my ($ignoring) = false;
	my ($url2name) = {};
	my ($names) = {};

	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		$load_dist_sites_url2name = $url2name;
		$load_dist_sites_names = $names;
		return;
	}
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"^(MASTER_SITE_\w+)\+=\s*\\$"o) {
			$varname = $1;
			$names->{$varname} = true;
			$ignoring = false;

		} elsif ($text eq "MASTER_SITE_BACKUP?=\t\\") {
			$ignoring = true;

		} elsif ($text =~ qr"^\t((?:http://|ftp://)\S+/)(?:|\s*\\)$"o) {
			if (!$ignoring) {
				if (defined($varname)) {
					$url2name->{$1} = $varname;
				} else {
					$line->log_error("Lonely URL found.");
				}
			}

		} elsif ($text =~ qr"^(?:#.*|\s*)$") {
			# ignore empty and comment lines

		} elsif ($text =~ qr"BSD_SITES_MK") {
			# ignore multiple inclusion guards

		} else {
			$line->log_error("Unknown line type.");
		}
	}

	# Explicitly allowed, although not defined in mk/bsd.sites.mk.
	$names->{"MASTER_SITE_SUSE_UPD"} = true;
	$names->{"MASTER_SITE_LOCAL"} = true;

	log_info($fname, NO_LINE_NUMBER, "Loaded " . scalar(keys(%{$url2name})) . " MASTER_SITE_* definitions.");
	$load_dist_sites_url2name = $url2name;
	$load_dist_sites_names = $names;
}

sub get_dist_sites() {
	if (!defined($load_dist_sites_url2name)) {
		load_dist_sites();
	}
	return $load_dist_sites_url2name;
}

sub get_dist_sites_names() {
	if (!defined($load_dist_sites_names)) {
		load_dist_sites();
	}
	return $load_dist_sites_names;
}

my $get_pkg_options_result = undef;
sub get_pkg_options() {

	if (defined($get_pkg_options_result)) {
		return $get_pkg_options_result;
	}

	my ($fname) = ("${current_dir}/${pkgsrcdir}/mk/defaults/options.description");
	my ($lines, $options);

	if (!($lines = load_file($fname))) {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

	$options = {};
	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^([-0-9a-z_]+)(?:\s+(.*))?$") {
			my ($optname, $optdescr) = ($1, $2);

			$options->{$optname} = defined($optdescr)
			    ? $optdescr
			    : "";
		} else {
			$line->log_error("Unknown line format.");
		}
	}

	return ($get_pkg_options_result = $options);
}

my $load_tool_names_tools = undef;
my $load_tool_names_vartools = undef;
my $load_tool_names_varname_to_toolname = undef;
my $load_tool_names_predefined_vartools = undef;
sub load_tool_names() {
	my ($tools, $vartools, $predefined_vartools, $varname_to_toolname, @tool_files);

	#
	# Get the list of files that define the tools from bsd.tools.mk.
	#

	@tool_files = ("defaults.mk");
	{
		my $fname = "${current_dir}/${pkgsrcdir}/mk/tools/bsd.tools.mk";
		my $lines = load_lines($fname, true);
		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_mk_include) {
				my ($includefile) = ($1);
				if ($includefile =~ qr"^\.\./\.\./mk/tools/(.*)$") {
					push(@tool_files, $1);
				}
			}
		}
	}

	#
	# Scan the tool files for the actual definitions of the tools.
	#

	$tools = {};
	$vartools = {};
	$predefined_vartools = {};
	$varname_to_toolname = {};
	foreach my $basename (@tool_files) {
		my $fname = "${current_dir}/${pkgsrcdir}/mk/tools/${basename}";
		my $lines = load_lines($fname, true);

		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);
				if ($varname eq "TOOLS_CREATE" && $value =~ qr"^([-\w.]+)$") {
					$tools->{$value} = true;

				} elsif ($varname =~ qr"^(?:_TOOLS_VARNAME)\.([-\w.]+)$") {
					$tools->{$1} = true;
					$vartools->{$1} = $value;
					$varname_to_toolname->{$value} = $1;

				} elsif ($varname =~ qr"^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;

				} elsif ($varname =~ qr"^_TOOLS\.") {
					foreach my $tool (split(qr"\s+", $value)) {
						$tools->{$tool} = true;
					}
				}
			}
		}
	}

	foreach my $basename ("bsd.pkg.mk") {
		my $fname = "${current_dir}/${pkgsrcdir}/mk/${basename}";
		my $lines = load_lines($fname, true);
		my $cond_depth = 0;

		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
		}

		foreach my $line (@{$lines}) {
			my $text = $line->text;

			if ($text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);

				if ($varname eq "USE_TOOLS") {
					$line->log_debug("[cond_depth=${cond_depth}] $value");
					if ($cond_depth == 0) {
						foreach my $tool (split(qr"\s+", $value)) {
							if ($tool !~ regex_unresolved && exists($vartools->{$tool})) {
								$predefined_vartools->{$tool} = true;
							}
						}
					}
				}

			} elsif ($text =~ regex_mk_cond) {
				my ($indent, $cond, $args, $comment) = ($1, $2, $3, $4);

				if ($cond =~ qr"^(?:if|ifdef|ifndef|for)$") {
					$cond_depth++;
				} elsif ($cond =~ qr"^(?:endif|endfor)$") {
					$cond_depth--;
				}
			}
		}
	}

	log_debug(NO_FILE, NO_LINE_NUMBER, "Known tools: ".join(" ", sort(keys(%{$tools}))));
	log_debug(NO_FILE, NO_LINE_NUMBER, "Known vartools: ".join(" ", sort(keys(%{$vartools}))));
	log_debug(NO_FILE, NO_LINE_NUMBER, "Predefined vartools: " . join(" ", sort(keys(%{$predefined_vartools}))));
	log_debug(NO_FILE, NO_LINE_NUMBER, "Known varnames: " . join(" ", sort(keys(%{$varname_to_toolname}))));

	$load_tool_names_tools = $tools;
	$load_tool_names_vartools = $vartools;
	$load_tool_names_predefined_vartools = $predefined_vartools;
	$load_tool_names_varname_to_toolname = $varname_to_toolname;
}

sub get_tool_names() {

	if (!defined($load_tool_names_tools)) {
		load_tool_names();
	}
	return $load_tool_names_tools;
}

sub get_vartool_names() {

	if (!defined($load_tool_names_vartools)) {
		load_tool_names();
	}
	return $load_tool_names_vartools;
}

sub get_predefined_vartool_names() {
	if (!defined($load_tool_names_predefined_vartools)) {
		load_tool_names();
	}
	return $load_tool_names_predefined_vartools;
}

sub get_varname_to_toolname() {
	if (!defined($load_tool_names_varname_to_toolname)) {
		load_tool_names();
	}
	return $load_tool_names_varname_to_toolname;
}

sub load_doc_TODO_updates($) {
	my ($fname) = @_;
	my ($lines, $updates, $state, $re_suggested_update);

	if (!($lines = load_file($fname))) {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

	$updates = [];
	$state = 0;
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($state == 0 && $text eq "Suggested package updates") {
			$state = 1;
		} elsif ($state == 1 && $text eq "") {
			$state = 2;
		} elsif ($state == 2) {
			$state = 3;
		} elsif ($state == 3 && $text eq "") {
			$state = 4;
		}

		if ($state == 3) {
			if ($text =~ qr"^\to\s(\S+)(?:\s*(.+))?$") {
				my ($spuname, $comment) = ($1, $2);
				if ($spuname =~ regex_pkgname) {
					push(@{$updates}, [$line, $1, $2, $comment]);
				} else {
					$line->log_warning("Invalid package name $spuname");
				}
			} else {
				$line->log_warning("Invalid line format $text");
			}
		}
	}

	return $updates;
}

my $get_doc_TODO_updates_result = undef;
sub get_doc_TODO_updates() {

	if (!defined($get_doc_TODO_updates_result)) {
		$get_doc_TODO_updates_result = load_doc_TODO_updates("${current_dir}/${pkgsrcdir}/doc/TODO");
	}
	return $get_doc_TODO_updates_result;
}

my $get_wip_TODO_updates_result = undef;
sub get_wip_TODO_updates() {

	if (!defined($get_wip_TODO_updates_result)) {
		$get_wip_TODO_updates_result = load_doc_TODO_updates("${current_dir}/${pkgsrcdir}/wip/TODO");
	}
	return $get_wip_TODO_updates_result;
}

sub get_suggested_package_updates() {

	return ($is_wip)
	    ? get_wip_TODO_updates()
	    : get_doc_TODO_updates();
}

#
# Miscellaneous functions
#

sub autofix($) {
	my ($lines) = @_;

	if ($opt_autofix) {
		save_autofix_changes($lines);
	}
}

sub is_committed($) {
	my ($fname) = @_;
	my ($basename, $entries);

	$basename = basename($fname);
	$entries = load_file(dirname($fname) . "/CVS/Entries");
	if (!$entries) {
		return false;
	}
	foreach my $entry (@{$entries}) {
		if ($entry->text =~ qr"^/\Q${basename}\E/") {
			return true;
		}
	}
	return false;
}

# - A directory that has no entries except ".", ".." and "CVS" is empty.
# - A directory whose entries besides ".", ".." and "CVS" are all empty is empty.
# - No other directories are empty.
sub is_emptydir($);
sub is_emptydir($) {
	my ($dir) = @_;
	my ($rv);

	if (!opendir(DIR, $dir)) {
		return true;
	}

	$rv = true;
	foreach my $subdir (readdir(DIR)) {
		next if $subdir eq "." || $subdir eq ".." || $subdir eq "CVS";
		next if -d "${dir}/${subdir}" && is_emptydir("${dir}/${subdir}");

		$rv = false;
		last;
	}

	closedir(DIR);
	return $rv;
}

sub get_subdirs($) {
	my ($dir) = @_;
	my (@result) = ();

	if (opendir(DIR, $dir)) {
		foreach my $subdir (readdir(DIR)) {
			if ($subdir ne "." && $subdir ne ".." && $subdir ne "CVS" && -d "${dir}/${subdir}" && !is_emptydir("${dir}/${subdir}")) {
				push(@result, $subdir);
			}
		}
		closedir(DIR);
	}
	return @result;
}

sub checkperms($) {
	my ($fname) = @_;

	if (-f $fname && -x $fname && !is_committed($fname)) {
		log_warning($fname, NO_LINE_NUMBER, "Should not be executable.");
	}
}

sub resolve_relative_path($$) {
	my ($relpath, $adjust_depth) = @_;

	$relpath =~ s,\$\{PKGSRCDIR\},$pkgsrcdir,;
	$relpath =~ s,\$\{\.CURDIR\},.,;
	$relpath =~ s,\$\{PHPPKGSRCDIR\},../../lang/php5,;
	$relpath =~ s,\$\{SUSE_DIR_PREFIX\},suse91,;
	$relpath =~ s,\$\{PYPKGSRCDIR\},../../lang/python23,;
	if ($adjust_depth) {
		$relpath =~ s,\.\./\.\.,$pkgsrcdir,;
	}
	if (defined($pkgdir)) {
		$relpath =~ s,\$\{PKGDIR\},$pkgdir,g;
	}

	return $relpath;
}

sub expand_variable($$) {
	my ($whole, $varname) = @_;
	my ($value, $re);

	$re = qr"\n\Q${varname}\E([+:?]?)=[ \t]*([^\n#]*)";
	$value = undef;
	while ($whole =~ m/$re/g) {
		my ($op, $val) = ($1, $2);
		if ($op ne "?" || !defined($value)) {
			$value = $val;
		}
	}
	if (!defined($value)) {
		return undef;
	}

	$value = resolve_relative_path($value, true);
	if ($value =~ regex_unresolved) {
		log_info(NO_FILE, NO_LINE_NUMBER, "[expand_variable] The variable ${varname} could not be resolved completely. Its value is \"${value}\".");
	}
	return $value;
}

sub set_default_value($$) {
	my ($varref, $value) = @_;

	if (!defined(${$varref}) || ${$varref} =~ regex_unresolved) {
		${$varref} = $value;
	}
}

sub strip_mk_comment($) {
	my ($text) = @_;

	$text =~ s/(^|[^\\])#.*/$1/;
	$text =~ s/\\#/#/g;
	return $text;
}

sub strings_to_lines($) {
	my ($strings) = @_;
	my ($retval);

	$retval = [];
	foreach my $s (@{$strings}) {
		push(@{$retval}, $s->line);
	}
	return $retval;
}

sub backtrace() {
	my (@callers);

	return unless $opt_debug;

	my $n = 0;
	while (my @info = caller($n)) {
		push(@callers, [$info[2], $info[3]]);
		$n++;
	}

	for (my $i = $#callers; $i >= 0; $i--) {
		my $info = $callers[$i];
		log_debug(NO_FILE, NO_LINE_NUMBER,
		    sprintf("%sline %4d in %s", ("  " x ($n - 1 - $i)),
		        $info->[0], $info->[1]));
	}
}

sub tablen($) {
	my ($s) = @_;
	my ($len);

	$len = 0;
	foreach my $c (split(qr"", $s)) {
		if ($c eq "\t") {
			$len = ($len + 7) & ~7;
		} else {
			$len++;
		}
	}
	return $len;
}

sub shell_split($) {
	my ($text) = @_;
	my ($words);

	$words = [];
	while ($text =~ s/^$regex_shellword//) {
		push(@{$words}, $1);
	}
	return (($text =~ qr"^\s*$") ? $words : false);
}

sub varname_base($) {
	my ($varname) = @_;

	return ($varname =~ qr"^(.*?)\..*$") ? $1 : $varname;
}

sub varname_canon($) {
	my ($varname) = @_;

	return ($varname =~ qr"^(.*?)\..*$") ? "$1.*" : $varname;
}

sub type_should_be_quoted($) {
	my ($type) = @_;

	if ($type->kind_of_list == PkgLint::Type::LK_INTERNAL) {
		return true;
	}
	if ($type->kind_of_list == LK_EXTERNAL) {
		return false;
	}
	if ($type->basic_type =~ qr"^(?:ShellCommand|SedCommands)$") {
		return false;
	}
	return true;
}

sub variable_needs_quoting($) {
	my ($varname) = @_;

	return !($varname =~ qr"^(?:.*DIR|.*_GROUP|.*_HOME|(?:BIN|LIB|MAN|GAMES|SHARE)(?:GRP|OWN|MODE)|.*_USER|BUILDLINK_PREFIX\..*|DISTNAME|EXTRACT_SUFX|LOCALBASE|PKGNAME|PREFIX|VARBASE|WRKSRC)$");
}

sub determine_used_variables($) {
	my ($lines) = @_;
	my ($rest);

	foreach my $line (@{$lines}) {
		$rest = $line->text;
		while ($rest =~ s/(?:\$\{|defined\(|empty\()([0-9+.A-Z_a-z]+)[:})]//) {
			my ($varname) = ($1);
			$varuse->{$varname} = $line;
			$varuse->{varname_canon($varname)} = $line;
			$line->log_debug("Variable ${varname} is used.");
		}
	}
}

my $check_pkglint_version_done = false;
sub check_pkglint_version() {

	return if $check_pkglint_version_done;
	$check_pkglint_version_done = true;

	my $lines = load_lines("${current_dir}/${pkgsrcdir}/pkgtools/pkglint/Makefile", true);
	return unless $lines;

	my $pkglint_version = undef;
	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_varassign) {
			my ($varname, undef, $value, undef) = ($1, $2, $3, $4);

			if ($varname eq "DISTNAME" || $varname eq "PKGNAME") {
				if ($value =~ regex_pkgname) {
					$pkglint_version = $2;
				}
			}
		}
	}
	return unless defined($pkglint_version);

	if (dewey_cmp($pkglint_version, ">", conf_distver)) {
		log_note(NO_FILE, NO_LINE_NUMBER, "A newer version of pkglint is available.");
	} elsif (dewey_cmp($pkglint_version, "<", conf_distver)) {
		log_error(NO_FILE, NO_LINE_NUMBER, "The pkglint version is newer than the tree to check.");
	}
}

sub expect($$$) {
	my ($lines, $lineno_ref, $regex) = @_;
	my $lineno = ${$lineno_ref};
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ $regex) {
		${$lineno_ref}++;
		return new PkgLint::SimpleMatch($lines->[$lineno]->text, \@-, \@+);
	} else {
		return false;
	}
}

sub expect_empty_line($$) {
	my ($lines, $lineno_ref) = @_;

	if (expect($lines, $lineno_ref, qr"^$")) {
		return true;
	} else {
		$opt_warn_space and $lines->[${$lineno_ref}]->log_note("Empty line expected.");
		return false;
	}
}

sub expect_text($$$) {
	my ($lines, $lineno_ref, $text) = @_;

	if (expect($lines, $lineno_ref, qr"^\Q${text}\E$")) {
		return true;
	} else {
		$lines->[${$lineno_ref}]->log_warning("Expected \"${text}\".");
		return false;
	}
}

sub get_variable_type($$) {
	my ($line, $varname) = @_;

	if (exists(get_vartypes_map()->{$varname})) {
		return get_vartypes_map()->{$varname};
	}

	my $varcanon = varname_canon($varname);
	if (exists(get_vartypes_map()->{$varcanon})) {
		return get_vartypes_map()->{$varcanon};
	}

	$opt_debug and $line->log_warning("No type definition found for ${varcanon}.");
	return undef;
}

sub get_variable_perms($$) {
	my ($line, $varname) = @_;

	my $type = get_variable_type($line, $varname);
	if (!defined($type)) {
		$opt_debug and $line->log_warning("No type definition found for ${varname}.");
		return "adpsu";
	}

	my $perms = $type->perms($line->fname, $varname);
	if (!defined($perms)) {
		$opt_debug and $line->log_warning("No permissions specified for ${varname}.");
		return "?";
	}
	return $perms;
}

#
# Loading package-specific data from files.
#

sub readmakefile($$$$);
sub readmakefile($$$$) {
	my ($fname, $main_lines, $all_lines, $seen_Makefile_include) = @_;
	my $contents = "";
	my ($includefile, $dirname, $lines, $is_main_Makefile);

	$lines = load_lines($fname, true);
	if (!$lines) {
		return false;
	}

	$is_main_Makefile = (@{$main_lines} == 0);

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($is_main_Makefile) {
			push(@{$main_lines}, $line);
		}
		push(@{$all_lines}, $line);

		# try to get any included file
		my $is_include_line = false;
		if ($text =~ qr"^\.\s*include\s+\"(.*)\"$") {
			$includefile = resolve_relative_path($1, true);
			if ($includefile =~ regex_unresolved) {
				if ($fname !~ qr"/mk/") {
					$line->log_note("Skipping include file \"${includefile}\". This may result in false warnings.");
				}

			} elsif (exists($seen_Makefile_include->{$includefile})) {
				# Don't include any file twice

			} else {
				$is_include_line = true;
				$seen_Makefile_include->{$includefile} = true;
			}
		}

		if ($is_include_line) {
			if ($includefile =~ qr"^\.\./[^./][^/]*/[^/]+") {
				$line->log_warning("Relative directories should look like \"../../category/package\", not \"../package\".");
				$line->explain_warning(expl_relative_dirs);
			}
			if ($includefile =~ qr"(?:^|/)Makefile.common$"
			    || ($includefile =~ qr"^(?:\.\./(\.\./[^/]+/)?[^/]+/)?([^/]+)$"
				&& (!defined($1) || $1 ne "../mk")
				&& $2 ne "buildlink3.mk"
				&& $2 ne "options.mk")) {
				$line->log_debug("including ${includefile} sets seen_Makefile_common.");
				$seen_Makefile_common = true;
			}
			if ($includefile =~ qr"/mk/") {
				# skip these files
				$contents .= $text . "\n";
			} else {
				$dirname = dirname($fname);
				# Only look in the directory relative to the
				# current file and in the current working directory.
				# We don't have an include dir list, like make(1) does.
				if (!-f "$dirname/$includefile") {
					$dirname = $current_dir;
				}
				if (!-f "$dirname/$includefile") {
					$line->log_error("Cannot read $dirname/$includefile.");
				} else {
					$line->log_info("Including \"$dirname/$includefile\".");
					$contents .= readmakefile("$dirname/$includefile", $main_lines, $all_lines, $seen_Makefile_include);
				}
			}
		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			if ($op ne "?=" || !exists($makevar->{$varname})) {
				$opt_debug and $line->log_debug("varassign(${varname}, ${op}, ${value})");
				$makevar->{$varname} = $line;
			}
			$contents .= $text . "\n";

		} else {
			$contents .= $text . "\n";
		}
	}
	return $contents;
}

sub load_package_Makefile($$$) {
	my ($subr) = "load_package_Makefile";
	my ($fname, $ref_whole, $ref_lines) = @_;
	my ($whole, $lines, $all_lines);

	log_info($fname, NO_LINE_NUMBER, "Checking package Makefile.");

	$whole = readmakefile($fname, $lines = [], $all_lines = [], {});
	if (!$whole) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	if ($opt_dumpmakefile) {
		print("OK: whole Makefile (with all included files) follows:\n");
		foreach my $line (@{$all_lines}) {
			print($line->to_string() . "\n");
		}
	}

	determine_used_variables($all_lines);

	# HACK
	if ($whole =~ qr"\nPHPEXT_MK" && $whole !~ qr"\nUSE_PHP_EXT_PATCHES") {
		log_info($fname, NO_LINE_NUMBER, "[hack] USE_PHP_EXT_PATCHES");
		$whole =~ s,\nPATCHDIR=.*PHPPKGSRCDIR.*,,;
		$hack_php_patches = true;
	}
	# HACK
	if ($whole =~ qr"\nPECL_VERSION") {
		log_info($fname, NO_LINE_NUMBER, "[hack] PECL_VERSION");
		$whole =~ s,\nDISTINFO_FILE=.*PHPPKGSRCDIR.*,,;
	}

	$pkgdir = expand_variable($whole, "PKGDIR");
	set_default_value(\$pkgdir, ".");
	$distinfo_file = expand_variable($whole, "DISTINFO_FILE");
	set_default_value(\$distinfo_file, "distinfo");
	$filesdir = expand_variable($whole, "FILESDIR");
	set_default_value(\$filesdir, "files");
	$patchdir = expand_variable($whole, "PATCHDIR");
	set_default_value(\$patchdir, "patches");

	log_info(NO_FILE, NO_LINE_NUMBER, "[${subr}] DISTINFO_FILE=$distinfo_file");
	log_info(NO_FILE, NO_LINE_NUMBER, "[${subr}] FILESDIR=$filesdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[${subr}] PATCHDIR=$patchdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[${subr}] PKGDIR=$pkgdir");

	${$ref_whole} = $whole;
	${$ref_lines} = $lines;
	return true;
}

#
# Subroutines to check a single line.
#

sub checkline_length($$) {
	my ($line, $maxlength) = @_;

	if (length($line->text) > $maxlength) {
		$line->log_warning("Line too long (should be no more than $maxlength characters).");
		$line->explain_warning(
			"Back in the old time, terminals with 80x25 characters were common.",
			"And this is still the default size of many terminal emulators.",
			"Moderately short lines also make reading easier.");
	}
}

sub checkline_valid_characters($$) {
	my ($line, $re_validchars) = @_;
	my ($rest);

	($rest = $line->text) =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning("Line contains invalid characters (" . join(", ", @chars) . ").");
	}
}

sub checkline_valid_characters_in_variable($$) {
	my ($line, $re_validchars) = @_;
	my ($varname, $rest);

	$rest = $line->text;
	if ($rest =~ regex_varassign) {
		($varname, undef, $rest) = ($1, $2, $3);
	} else {
		return;
	}

	$rest =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning("${varname} contains invalid characters (" . join(", ", @chars) . ").");
	}
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;

	if ($line->text =~ /\s+$/) {
		$line->log_note("Trailing white-space.");
		$line->replace_regex(qr"\s+\n$", "\n");
	}
}

sub checkline_rcsid_regex($$$) {
	my ($line, $prefix_regex, $prefix) = @_;
	my ($id) = ($opt_rcsidstring . ($is_wip ? "|Id" : ""));

	if ($line->text !~ qr"^${prefix_regex}\$(${id})(?::[^\$]*|)\$$") {
		$line->log_error("\"${prefix}\$${opt_rcsidstring}\$\" expected.");
		return false;
	}
	return true;
}

sub checkline_rcsid($$) {
	my ($line, $prefix) = @_;
	checkline_rcsid_regex($line, quotemeta($prefix), $prefix);
}

sub checkline_relative_path($$) {
	my ($line, $path) = @_;
	my ($res_path);

	if (!$is_wip && $path =~ qr"/wip/") {
		$line->log_error("A pkgsrc package must not depend on any outside package.");
	}
	$res_path = resolve_relative_path($path, true);
	if ($res_path =~ regex_unresolved) {
		$line->log_info("Unresolved path: \"${path}\".");
	} elsif (!-e ((($res_path =~ qr"^/") ? "" : "${current_dir}/") . $res_path)) {
		$line->log_error("\"${res_path}\" does not exist.");
	} elsif ($path =~ qr"^\.\./\.\./([^/]+)/([^/]+)(.*)") {
		my ($cat, $pkg, $rest) = ($1, $2, $3);
	} elsif ($path =~ qr"^\.\./\.\./mk/") {
		# There need not be two directory levels for mk/ files.
	} elsif ($path =~ qr"^\.\.") {
		$line->log_warning("Invalid relative path \"${path}\".");
	}
}

sub checkline_relative_pkgdir($$) {
	my ($line, $path) = @_;

	checkline_relative_path($line, $path);
	$path = resolve_relative_path($path, false);

	if ($path !~ qr"^(?:\./)?\.\./\.\./[^/]+/[^/]+$") {
		$line->log_warning("\"${path}\" is not a valid relative package directory.");
		$line->explain_warning(
			"A relative pathname always starts with \"../../\", followed",
			"by a category, a slash and a the directory name of the package.",
			"For example, \"../../misc/screen\" is a valid relative pathname.");
	}
}

sub checkline_spellcheck($) {
	my ($line) = @_;

	if ($line->text =~ qr"existant") {
		$line->log_warning("The word \"existant\" is nonexistent in the m-w dictionary.");
		$line->explain_warning("Please use \"existent\" instead.");
	}
}

sub checkline_cpp_macro_names($$) {
	my ($line, $text) = @_;
	my ($rest);

	use constant good_macros => PkgLint::Util::array_to_hash(qw(
		__STDC__

		__GNUC__ __GNUC_MINOR__
		__SUNPRO_C

		__i386
		__mips
		__sparc

		__APPLE__
		__bsdi__
		__CYGWIN__
		__DragonFly__
		__FreeBSD__ __FreeBSD_version
		__INTERIX
		__linux__
		__MINGW32__
		__NetBSD__ __NetBSD_Version__
		__OpenBSD__
		__SVR4
		__sun

		__GLIBC__
	));
	use constant bad_macros  => {
		"__sparc__" => "__sparc",
		"__sun__" => "__sun",
		"__svr4__" => "__SVR4",
	};

	$rest = $text;
	while ($rest =~ s/defined\((__[\w_]+)\)//) {
		my ($macro) = ($1);

		if (exists(good_macros->{$macro})) {
			$line->log_debug("Found good macro \"${macro}\".");
		} elsif (exists(bad_macros->{$macro})) {
			$line->log_warning("The macro \"${macro}\" is not portable enough. Please use \"".bad_macros->{$macro}."\" instead.");
			$line->explain_warning("See the pkgsrc guide, section \"CPP defines\" for details.");
		} else {
			$line->log_info("Found unknown macro \"${macro}\".");
		}
	}
}

sub checkline_mk_text($$) {
	my ($line, $text) = @_;
	my ($rest, $state, $vartools, $depr_map);

	if ($text =~ qr"^(?:[^#]*[^\$])?\$(\w+)") {
		my ($varname) = ($1);
		$line->log_warning("\$$varname is ambiguous. Use \${$varname} if you mean a Makefile variable or \$\$$varname if you mean a shell variable.");
	}

	if ($line->lines eq "1") {
		checkline_rcsid_regex($line, qr"#\s+", "# ");
	}

	if ($text =~ qr"\$\{WRKSRC\}/\.\./") {
		$line->log_warning("Using \"\${WRKSRC}/..\" is conceptually wrong. Please use a combination of WRKSRC, CONFIGURE_DIRS and BUILD_DIRS instead.");
	}

	if ($text =~ qr"\b(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R)\b") {
		$line->log_warning("Please use \${COMPILER_RPATH_FLAG} instead of $1.");
	}
	# Note: A simple -R is not detected, as the rate of false
	# positives is too high.

	$rest = $text;
	$depr_map = get_deprecated_map();
	while ($rest =~ s/(?:^|[^\$])\$\{([-A-Z0-9a-z_]+)(\.[\-0-9A-Z_a-z]+)?(?::[^\}]+)?\}//) {
		my ($varbase, $varext) = ($1, $2);
		my $varname = $varbase . (defined($varext) ? $varext : "");
		my $varcanon = varname_canon($varname);
		my $instead =
		      (exists($depr_map->{$varname})) ? $depr_map->{$varname}
		    : (exists($depr_map->{$varcanon})) ? $depr_map->{$varcanon}
		    : undef;

		if (defined($instead)) {
			$line->log_warning("Use of ${varname} is deprecated. ${instead}");
		}
	}

	$rest = $text;
	while ($rest =~ s/(?:^|[^\$])\$\(([-A-Z0-9a-z_]+)(?::[^\}]+)?\)//) {
		my ($varname) = ($1);

		$line->log_warning("Please use \${${varname}\} instead of \$(${varname}).");
	}

}

sub checkline_mk_shellword($$$) {
	my ($line, $shellword, $check_quoting) = @_;
	my ($rest, $state);

	if ($opt_warn_quoting && $shellword =~ qr"^\$\{(${regex_varname})(:[^}]+)?\}$") {
		my ($varname, $mod) = ($1, $2);

		if (exists(get_vartypes_map()->{$varname}) && !(defined($mod) && $mod =~ qr":Q$")) {
			my $vartype = get_vartypes_map()->{$varname};

			if (variable_needs_quoting($varname) && type_should_be_quoted($vartype)) {
				$line->log_warning("[experimental] Please use \${${varname}:Q} instead of \${${varname}}.");
			}
		} elsif (exists(get_varname_to_toolname()->{$varname})) {
			if (defined($mod) && $mod =~ qr":Q$") {
				$line->log_warning("The :Q operator should not be used for tools.");
			}

		} else {
			$opt_debug and $line->log_warning("Not sure whether the variable ${varname} needs quoting.");
		}
		return;
	}

	if ($shellword =~ qr"^([\w_\-]+)=(([\"']?)\$\{([\w_]+)\}\3)$") {
		my ($key, $vexpr, undef, $vname) = ($1, $2, $3, $4);
		
		if (variable_needs_quoting($vname)) {
			my $mod = ($vname =~ regex_gnu_configure_volatile_vars) ? ":M*:Q" : ":Q";
			my $fixed_vexpr = "\${${vname}${mod}}";
			$line->log_warning("Please use ${fixed_vexpr} instead of ${vexpr}.");
			$line->explain_warning("See the pkgsrc guide, section \"quoting guideline\", for details.");
			$line->replace($shellword, "${key}=${fixed_vexpr}");
		}

	} elsif ($shellword =~ qr"^([\w_\-]+)=(\$\{([\w_]+):Q\})$") {
		my ($key, $vexpr, $vname) = ($1, $2, $3);
		my $fixed_vexpr = "\${${vname}:M*:Q}";
		if ($vname =~ regex_gnu_configure_volatile_vars) {
			$line->log_warning("Please use ${fixed_vexpr} instead of ${vexpr}.");
			$line->explain_warning("See the pkgsrc guide, section \"quoting guideline\", for details.");
			$line->replace($shellword, "${key}=${fixed_vexpr}");
		}

	} elsif ($shellword ne "" && $shellword !~ qr"^${regex_shellword}$") {
		$line->log_warning("Invalid shell word \"${shellword}\".");
	}

	# Note: SWST means [S]hell[W]ord [ST]ate
	use constant SWST_PLAIN		=> 0;
	use constant SWST_SQUOT		=> 1;
	use constant SWST_DQUOT		=> 2;
	use constant SWST_DQUOT_BACKT	=> 3;
	use constant SWST_BACKT		=> 4;
	use constant SWST_BACKT_DQUOT	=> 5;
	use constant SWST_BACKT_SQUOT	=> 6;
	use constant statename		=> [
		"SWST_PLAIN", "SWST_SQUOT", "SWST_DQUOT",
		"SWST_DQUOT_BACKT", "SWST_BACKT",
		"SWST_BACKT_DQUOT", "SWST_BACKT_SQUOT"
	];
	use constant user_statename	=> [
		"unquoted string", "single quoted string",
		"double quoted string", "backticks inside double quoted string",
		"backticks", "double quoted string inside backticks",
		"single quoted string inside backticks"
	];

	$rest = ($shellword =~ qr"^#") ? "" : $shellword;
	$state = SWST_PLAIN;
	while ($rest ne "") {

		$opt_debug and $line->log_debug("[checkline_mk_shellword] " . statename->[$state] . " ${rest}");

		# make variables have the same syntax, no matter in which
		# state we are currently.
		if ($rest =~ s/^\$\{(${regex_varname})(:[^\{]+)?\}//
		||  $rest =~ s/^\$\((${regex_varname})(:[^\)]+)?\)//) {
			my ($varname, $mod) = ($1, $2);

			if ($state == SWST_PLAIN && defined($mod) && $mod =~ qr":Q$") {
				# Fine.

			} elsif ($state == SWST_BACKT) {
				# Don't check here, to avoid false positives
				# for tool names.

			} elsif (($state == SWST_SQUOT || $state == SWST_DQUOT) && $varname =~ qr"^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$") {
				# This is ok if we don't allow these
				# variables to have embedded [\$\\\"\'\`].

			} elsif ($state == SWST_DQUOT && defined($mod) && $mod =~ qr":Q$") {
				$line->log_warning("Please don't use the :Q operator in double quotes.");
				$line->explain_warning(
					"Either remove the :Q or the double quotes. In most cases, it is more",
					"appropriate to remove the double quotes.");

			} elsif ($opt_warn_quoting) {
				if (!variable_needs_quoting($varname)) {
					# These variables don't need to be quoted.

				} elsif ($state == SWST_PLAIN) {
					$line->log_warning("Please use \${${varname}:Q} instead of \${${varname}}.");
					$line->replace("\${${varname}}", "\${${varname}:Q}");
				} else {
					$line->log_warning("Please use \${${varname}:Q} instead of \${${varname}} and make sure the variable appears outside of any quoting characters.");
				}
			}

		} elsif ($state == SWST_PLAIN) {
			if ($rest =~ s/^[!\%&\(\)*+,\-.\/0-9:;<=>?\@A-Z\[\]^_a-z{|}~]+//) {
			} elsif ($rest =~ s/^\'//) {
				$state = SWST_SQUOT;
			} elsif ($rest =~ s/^\"//) {
				$state = SWST_DQUOT;
			} elsif ($rest =~ s/^\`//) {
				$state = SWST_BACKT;
			} elsif ($rest =~ s/^\\[ !"#'\(\)*;\\^{}]//) {
			} elsif ($rest =~ s/^\$\$([0-9A-Z_a-z]+)//
			    || $rest =~ s/^\$\$\{([0-9A-Z_a-z]+)\}//) {
				my ($shvarname) = ($1);
				if ($opt_warn_quoting && $check_quoting) {
					$line->log_warning("Unquoted shell variable \"${shvarname}\".");
				}
			} elsif ($rest =~ s/\$\$\(/(/) {
				$line->log_warning("Invoking subshells via \$(...) is not portable enough.");
				$line->explain_warning(
					"The Solaris /bin/sh does not know this way to execute a command in a",
					"subshell. Please use backticks (\`...\`) as a replacement.");

			} else {
				last;
			}

		} elsif ($state == SWST_SQUOT) {
			if ($rest =~ s/^\'//) {
				$state = SWST_PLAIN;
			} elsif ($rest =~ s/^[^\$\']+//) {
			} elsif ($rest =~ s/^\$\$//) {
			} else {
				last;
			}

		} elsif ($state == SWST_DQUOT) {
			if ($rest =~ s/^\"//) {
				$state = SWST_PLAIN;
			} elsif ($rest =~ s/^[^\$"\\\`]+//) {
			} elsif ($rest =~ s/^\\(?:[\\\"\`]|\$\$)//) {
			} elsif ($rest =~ s/^\$\$\{([0-9A-Za-z_]+)\}//
			    || $rest =~ s/^\$\$([0-9A-Z_a-z]+|[\$!#?\@])//) {
				my ($varname) = ($1);
				$line->log_debug("[checkline_mk_shellword] Found double-quoted variable ${varname}.");
			} elsif ($rest =~ s/^\$\$//) {
				$line->log_warning("Unquoted \$ or strange shell variable found.");
			} elsif ($rest =~ s/^\\([\(\)*\-.0-9n])//) {
				my ($char) = ($1);
				$line->log_warning("Please use \"\\\\${char}\" instead of \"\\${char}\".");
				$line->explain_warning(
					"Although the current code may work, it is not good style to rely on",
					"the shell passing \"\\${char}\" exactly as is, and not discarding the",
					"backslash. Alternatively you can use single quotes instead of double",
					"quotes.");
			} else {
				last;
			}

		} elsif ($state == SWST_BACKT) {
			if ($rest =~ s/^\`//) {
				$state = SWST_PLAIN;
			} elsif ($rest =~ s/^[^\\\"\'\`\$]+//) {
			} elsif ($rest =~ s/^'//) {
				$state = SWST_BACKT_SQUOT;
			} elsif ($rest =~ s/^"//) {
				$state = SWST_BACKT_DQUOT;
			} elsif ($rest =~ s/^\\[\\\$\`]//) {
			} elsif ($rest =~ s/^\\//) {
				$line->log_warning("Backslashes should be doubled inside backticks.");
			} elsif ($rest =~ s/^\$\$\{([0-9A-Za-z_]+)\}//
			    || $rest =~ s/^\$\$([0-9A-Za-z_]+)//) {
				my ($shvarname) = ($1);
				if ($opt_warn_quoting && $check_quoting) {
					$line->log_warning("Unquoted shell variable \$${shvarname}.");
				}

			} else {
				last;
			}

		} elsif ($state == SWST_BACKT_SQUOT) {
			if ($rest =~ s/^'//) {
				$state = SWST_BACKT;
			} elsif ($rest =~ s/^\\[\\\`\$]//) {
			} elsif ($rest =~ s/^[^\\]+//) {
			} else {
				last;
			}

		} elsif ($state == SWST_BACKT_DQUOT) {
			if ($rest =~ s/^"//) {
				$state = SWST_BACKT;
			} elsif ($rest =~ s/^[^\\\"\'\`\$]+//) {
			} else {
				last;
			}

		} else {
			last;
		}
	}
	if ($rest ne "") {
		$opt_debug && $line->log_error("[checkline_mk_shellword] " . statename->[$state] . ": rest=${rest}");
	}
}

sub checkline_mk_shelltext($$) {
	my ($line, $text) = @_;
	my ($vartools, $state, $rest, $set_e_mode);

	# Note: SCST is the abbreviation for [S]hell [C]ommand [ST]ate.
	use constant SCST_START		=>  0;
	use constant SCST_CONT		=>  1;
	use constant SCST_INSTALL	=>  2;
	use constant SCST_INSTALL_D	=>  3;
	use constant SCST_MKDIR		=>  4;
	use constant SCST_PAX		=>  5;
	use constant SCST_PAX_S		=>  6;
	use constant SCST_SED		=>  7;
	use constant SCST_SED_E		=>  8;
	use constant SCST_SET		=>  9;
	use constant SCST_COND_CONT	=> 10;
	use constant SCST_CASE		=> 11;
	use constant SCST_CASE_IN	=> 12;
	use constant SCST_CASE_LABEL	=> 13;
	use constant SCST_CASE_LABEL_CONT => 14;
	use constant SCST_CASE_PAREN	=> 15;
	use constant SCST_FOR		=> 16;
	use constant SCST_FOR_IN	=> 17;
	use constant SCST_FOR_CONT	=> 18;
	use constant SCST_SET_CONT	=> 19;
	use constant SCST_COND		=> 20;

	use constant scst_statename => [
		"SCST_START", "SCST_CONT", "SCST_INSTALL", "SCST_INSTALL_D",
		"SCST_MKDIR", "SCST_PAX", "SCST_PAX_S", "SCST_SED",
		"SCST_SED_E", "SCST_SET", "SCST_COND_CONT", "SCST_CASE",
		"SCST_CASE_IN", "SCST_CASE_LABEL", "SCST_CASE_LABEL_CONT",
		"SCST_CASE_PAREN", "SCST_FOR", "SCST_FOR_IN",
		"SCST_FOR_CONT", "SCST_SET_CONT", "SCST_COND",
	];

	use constant forbidden_commands => array_to_hash(qw(
		ktrace
		strace
		truss
	));

	if ($text =~ qr"\$\{SED\}" && $text =~ qr"\$\{MV\}") {
		$line->log_note("Please use the SUBST framework instead of \${SED} and \${MV}.");
	}

	if ($text =~ qr"^\@*-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)") {
		my ($mkdir_cmd) = ($1);

		$line->log_note("You don't need to use \"-\" before ${mkdir_cmd}.");
	}

	$vartools = get_vartool_names();
	$rest = $text;

	use constant hidden_shell_commands => array_to_hash(qw(
		${DO_NADA}
		${ECHO} ${ECHO_MSG} ${ECHO_N}
	));

	if ($rest =~ s/^([-@]*)(?:\$\{_PKG_SILENT\}\$\{_PKG_DEBUG\})?//) {
		my ($hidden) = ($1);

		if ($hidden !~ qr"\@") {
			# Nothing is hidden at all.

		} elsif (defined($mkctx_target) && $mkctx_target =~ qr"^(?:show-.*|.*-message)$") {
			# In some targets commands may be hidden.

		} elsif ($rest =~ $regex_shellword) {
			my ($cmd) = ($1);

			if (!exists(hidden_shell_commands->{$cmd})) {
				$line->log_warning("The shell command \"${cmd}\" should not be hidden.");
			}
		}
	}

	$state = SCST_START;
	$set_e_mode = false;
	while ($rest =~ s/^$regex_shellword//) {
		my ($shellword) = ($1);

		$line->log_debug("[" . scst_statename->[$state] . "] shellword=${shellword}");

		checkline_mk_shellword($line, $shellword, !(
		       $state == SCST_CASE
		    || $state == SCST_FOR_CONT
		    || $state == SCST_SET_CONT
		    || ($state == SCST_START && $shellword =~ regex_sh_varassign)));

		#
		# Actions associated with the current state
		# and the symbol on the "input tape".
		#

		if ($state == SCST_START && exists($vartools->{$shellword})) {
			my $addition = "";

			if (!exists(get_predefined_vartool_names->{$shellword})) {
				my $toolvarname = get_vartool_names->{$shellword};
				my $toolname = get_varname_to_toolname->{$toolvarname};
				$addition = " and add USE_TOOLS+=${toolname} before this line";
			}
			$line->log_warning("Direct use of tool \"${shellword}\". Please use \$\{$vartools->{$shellword}\} instead${addition}.");
		}

		if ($state == SCST_START && exists(forbidden_commands->{$shellword})) {
			$line->log_error("${shellword} is forbidden and must not be used.");
		}

		if ($state == SCST_COND && $shellword eq "cd") {
			$line->log_error("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.");
		}

		if (($state != SCST_PAX_S && $state != SCST_SED_E && $state != SCST_CASE_LABEL) && $shellword =~ qr"^/" && $shellword ne "/dev/null") {
			$line->log_warning("Found absolute pathname: ${shellword}");
			$line->explain_warning(
				"Absolute pathnames are often an indicator for unportable code. As",
				"pkgsrc aims to be a portable system, absolute pathnames should be",
				"avoided whenever possible.");
		}

		if (($state == SCST_INSTALL_D || $state == SCST_MKDIR) && $shellword =~ qr"^\$\{PREFIX\}/") {
			$line->log_warning("Please use one of the INSTALL_*_DIR commands instead of "
				. (($state == SCST_MKDIR) ? "\${MKDIR}" : "\${INSTALL} -d")
				. ".");
			$line->explain_warning(
				"Choose one of INSTALL_PROGRAM_DIR, INSTALL_SCRIPT_DIR, INSTALL_LIB_DIR,",
				"INSTALL_MAN_DIR, INSTALL_DATA_DIR.");
		}

		if ($state == SCST_PAX_S || $state == SCST_SED_E) {
			if (false && $shellword !~ qr"^[\"\'].*[\"\']$") {
				$line->log_warning("Substitution commands like \"${shellword}\" should always be quoted.");
				$line->explain_warning(
					"Usually these substitution commands contain characters like '*' or",
					"other shell metacharacters that might lead to lookup of matching",
					"filenames and then expand to more than one word.");
			}
		}

		if ($opt_warn_extra && $shellword eq "|") {
			$line->log_warning("The exitcode of the left-hand-side command of the pipe operator is ignored.");
			$line->explain_warning(
				"If you need to detect the failure of the left-hand-side command, use",
				"temporary files to save the output of the command.");
		}

		if ($opt_warn_extra && $shellword eq ";" && $state != SCST_COND_CONT && $state != SCST_FOR_CONT && !$set_e_mode) {
			$line->log_warning("A semicolon should only be used to separate commands after switching to \"set -e\" mode.");
			$line->explain_warning(
				"Older versions of the NetBSD make(1) had run the shell commands using",
				"the \"-e\" option of /bin/sh. In 2004, this behavior has been changed to",
				"follow the POSIX conventions, which is to not use the \"-e\" option.",
				"The consequence of this change is that shell programs don't terminate",
				"as soon as an error occurs, but try to continue with the next command.",
				"Imagine what would happen for these commands:",
				"    cd \"\$HOME\"; cd /nonexistent; rm -rf *",
				"To fix this warning, either insert \"set -e\" at the beginning of this",
				"line or use the \"&&\" operator instead of the semicolon.");
		}

		#
		# State transition.
		#

		if ($state == SCST_SET && $shellword =~ qr"^-.*e") {
			$set_e_mode = true;
		}

		$state =  ($shellword eq ";;") ? SCST_CASE_LABEL
			: ($shellword =~ qr"^[;&\|]+$") ? SCST_START
			: ($state == SCST_START) ? (
				  ($shellword eq "\${INSTALL}") ? SCST_INSTALL
				: ($shellword eq "\${MKDIR}") ? SCST_MKDIR
				: ($shellword eq "\${PAX}") ? SCST_PAX
				: ($shellword eq "\${SED}") ? SCST_SED
				: ($shellword eq "set") ? SCST_SET
				: ($shellword =~ qr"^(?:if|elif|while)$") ? SCST_COND
				: ($shellword =~ qr"^(?:then|else|do)$") ? SCST_START
				: ($shellword eq "case") ? SCST_CASE
				: ($shellword eq "for") ? SCST_FOR
				: ($shellword eq "(") ? SCST_START
				: ($shellword =~ regex_sh_varassign) ? SCST_START
				: SCST_CONT)
			: ($state == SCST_MKDIR) ? SCST_MKDIR
			: ($state == SCST_INSTALL && $shellword eq "-d") ? SCST_INSTALL_D
			: ($state == SCST_INSTALL || $state == SCST_INSTALL_D) ? (
				  ($shellword =~ qr"^-[ogm]$") ? SCST_CONT
				: $state)
			: ($state == SCST_PAX) ? (
				  ($shellword eq "-s") ? SCST_PAX_S
				: ($shellword =~ qr"^-") ? SCST_PAX
				: SCST_CONT)
			: ($state == SCST_PAX_S) ? SCST_PAX
			: ($state == SCST_SED) ? (
				  ($shellword eq "-e") ? SCST_SED_E
				: ($shellword =~ qr"^-") ? SCST_SED
				: SCST_CONT)
			: ($state == SCST_SED_E) ? SCST_SED
			: ($state == SCST_SET) ? SCST_SET_CONT
			: ($state == SCST_SET_CONT) ? SCST_SET_CONT
			: ($state == SCST_CASE) ? SCST_CASE_IN
			: ($state == SCST_CASE_IN && $shellword eq "in") ? SCST_CASE_LABEL
			: ($state == SCST_CASE_LABEL && $shellword eq "esac") ? SCST_CONT
			: ($state == SCST_CASE_LABEL) ? SCST_CASE_LABEL_CONT
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq "|") ? SCST_CASE_LABEL
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq ")") ? SCST_START
			: ($state == SCST_CONT) ? SCST_CONT
			: ($state == SCST_COND) ? SCST_COND_CONT
			: ($state == SCST_COND_CONT) ? SCST_COND_CONT
			: ($state == SCST_FOR) ? SCST_FOR_IN
			: ($state == SCST_FOR_IN && $shellword eq "in") ? SCST_FOR_CONT
			: ($state == SCST_FOR_CONT) ? SCST_FOR_CONT
			: do {
				$line->log_warning("[" . scst_statename->[$state] . " ${shellword}] Keeping the current state.");
				$state;
			};
	}

	if ($rest ne "") {
		$opt_debug && $line->log_error("[checkline_mk_shelltext] " . scst_statename->[$state] . ": rest=${rest}");
	}
}

sub checkline_mk_shellcmd($$) {
	my ($line, $shellcmd) = @_;

	checkline_mk_text($line, $shellcmd);
	checkline_mk_shelltext($line, $shellcmd);
}

sub checkline_mk_vardef($$$) {
	my ($line, $varname, $op) = @_;

	return unless $opt_warn_perm;

	my $perms = get_variable_perms($line, $varname);
	my $needed = { "=" => "s", "!=" => "s", "?=" => "d", "+=" => "a", ":=" => "s" }->{$op};

	if (index($perms, $needed) == -1) {
		$line->log_warning("Permission [${needed}] requested for ${varname}, but only [${perms}] is allowed.");
		$line->explain_warning(
			"The available permissions are:",
			"\ta\tappend something using +=",
			"\td\tset a default value using ?=",
			"\ts\tset a variable using :=, =, !=",
			"\tp\tuse a variable during preprocessing",
			"\tu\tuse a variable at runtime",
			"",
			"A \"?\" means that it is not yet clear which permissions",
			"are allowed and which aren't.");
	}
}

sub checkline_mk_varuse($$$) {
	my ($line, $varname, $context) = @_;

	return unless $opt_warn_perm;

	my $perms = get_variable_perms($line, $varname);
	# TODO: Check something.
}

sub checkline_mk_vartype_basic($$$$$$$);
sub checkline_mk_vartype_basic($$$$$$$) {
	my ($line, $varname, $type, $op, $value, $comment, $list_context) = @_;
	my ($value_novar);

	$value_novar = $value;
	while ($value_novar =~ s/\$\{([^{}]*)\}//g) {
		my ($varuse) = ($1);
		if (!$list_context && $varuse =~ qr":Q$") {
			$line->log_warning("The :Q operator should only be used in lists and shell commands.");
		}
	}

	if (ref($type) eq "HASH") {
		if (!exists($type->{$value})) {
			$line->log_warning("\"${value}\" is not valid for ${varname}. Use one of ".join(" ", sort(keys(%{$type})))." instead.");
		}

	} elsif ($type eq "AwkCommand") {
		$opt_debug and $line->log_warning("Unchecked AWK command: ${value}");

	} elsif ($type eq "BrokenIn") {
		if ($value ne $value_novar) {
			$line->log_error("${varname} must not refer to other variables.");
		} elsif ($value =~ qr"^(\d\d\d\d)Q(\d)$") {
			# Fine.
		}
		$line->log_note("Please remove this line if the package builds for you.");

	} elsif ($type eq "BuildlinkDepmethod") {
		if ($value ne $value_novar) {
			# No checks yet.
		} elsif ($value ne "build" && $value ne "full") {
			$line->log_warning("Invalid dependency method \"${value}\". Valid methods are \"build\" or \"full\".");
		}

	} elsif ($type eq "BuildlinkDepth") {
		if ($value ne "\${BUILDLINK_DEPTH}+"
		    && $value ne "\${BUILDLINK_DEPTH:S/+\$//}") {
			$line->log_warning("Invalid value for ${varname}.");
		}

	} elsif ($type eq "BuildlinkPackages") {
		my $re_del = qr"\$\{BUILDLINK_PACKAGES:N[+\-.0-9A-Z_a-z]+\}";
		my $re_add = qr"[+\-.0-9A-Z_a-z]+";

		if (($op eq ":=" && $value =~ qr"^${re_del}$") ||
		    ($op eq ":=" && $value =~ qr"^${re_del}\s+${re_add}$") ||
		    ($op eq "+=" && $value =~ qr"^${re_add}$")) {
			# Fine.

		} else {
			$line->log_warning("Invalid value for ${varname}.");
		}

	} elsif ($type eq "Category") {
		my $allowed_categories = join("|", qw(
			archivers audio
			benchmarks biology
			cad chat chinese comms converters cross crosspkgtools
			databases devel
			editors emulators
			finance fonts
			games geography gnome gnustep graphics
			ham
			inputmethod
			japanese java
			kde korean
			lang linux
			mail math mbone meta-pkgs misc multimedia
			net news
			packages parallel perl5 pkgtools plan9 print python
			ruby
			security shells sysutils
			tcl textproc time tk
			windowmaker wm www
			x11 xmms
		));
		if ($value !~ qr"^(?:${allowed_categories})$") {
			$line->log_error("Invalid category \"${value}\".");
		}

	} elsif ($type eq "CFlag") {
		if ($value =~ qr"^-D([0-9A-Z_a-z]+)=(.*)") {
			my ($macname, $macval) = ($1, $2);

			if ($macval =~ qr"^\\\"(?:\$\{[A-Z0-9_]+:Q\}|[^\$])*\\\"") {
				# Everything's fine.

			} elsif ($macval =~ qr"^\"\\\"[^\$]*\$\{[A-Z0-9_]+\}.*\\\"\"") {
				$opt_debug and $line->log_warning("Not the best style for CPP macros, but accepted.");

			} elsif ($macval =~ regex_unresolved && $macval =~ qr"[\"']") {
				$line->log_warning("Unusual macro value ${macval}.");
				$line->explain_warning(
					"String macro definitions should start and end with an escaped quote",
					"(\\\"). Between these quotes, there should be quoted variables in the",
					"form \${VARNAME:Q} or arbitrary non-dollar characters.");
			}
		} elsif ($value =~ qr"^-[DU]([0-9A-Z_a-z]+)") {
			my ($macname) = ($1);

			$opt_debug and $line->log_warning("Unknown macro ${macname} in ${varname}.");

		} elsif ($value =~ qr"^-I(.*)") {
			my ($dirname) = ($1);

			$opt_debug and $line->log_warning("Unknown directory ${dirname} in ${varname}.");

		} elsif ($value eq "-c99") {
			# Only works on IRIX, but is usually enclosed with
			# the proper preprocessor conditional.

		} elsif ($value =~ qr"^-[OWfgm]") {
			$opt_debug and $line->log_warning("Undiscussed compiler flag ${value} in ${varname}.");

		} elsif ($value =~ qr"^-.*") {
			$line->log_warning("Unknown compiler flag \"${value}\".");

		} elsif ($value =~ regex_unresolved) {
			$line->log_debug("Unresolved CFLAG: ${value}\n");

		} else {
			$line->log_warning("Compiler flag \"${value}\" does not start with a dash.");
		}

	} elsif ($type eq "Comment") {
		if ($value eq "SHORT_DESCRIPTION_OF_THE_PACKAGE") {
			$line->log_error("COMMENT must be set.");
		}
		if ($value =~ qr"^(a|an)\s+"i) {
			$line->log_warning("COMMENT should not begin with '$1'.");
		}
		if ($value =~ qr"^[a-z]") {
			$line->log_warning("COMMENT should start with a capital letter.");
		}
		if ($value =~ qr"\.$") {
			$line->log_warning("COMMENT should not end with a period.");
		}
		if (length($value) > 70) {
			$line->log_warning("COMMENT should not be longer than 70 characters.");
		}

	} elsif ($type eq "Dependency") {
		if ($value eq $value_novar && $value !~ qr"^[-*+,.0-9<=>\?\@A-Z_a-z\[\]\{\}]+$") {
			$line->log_warning("\"${value}\" is not a valid dependency.");
			$line->explain_warning(
				"Typical dependencies have the form \"package>=2.5\", \"package-[0-9]*\"",
				"or \"package-3.141\".");
		}

	} elsif ($type eq "DependencyWithPath") {
		if ($value =~ regex_unresolved) {
			# don't even try to check anything
		} elsif ($value =~ qr":(\.\./\.\./([^/]+)/([^/]+))$") {
			my ($relpath, $cat, $pkg) = ($1, $2, $3);

			checkline_relative_pkgdir($line, $relpath);

			if ($pkg eq "msgfmt" || $pkg eq "gettext") {
				$line->log_warning("Please use BUILD_USES_MSGFMT=yes instead of this dependency.");

			} elsif ($pkg =~ qr"^perl\d+") {
				$line->log_warning("Please use USE_TOOLS+=perl:run instead of this dependency.");

			} elsif ($pkg eq "gmake") {
				$line->log_warning("Please use USE_TOOLS+=gmake instead of this dependency.");

			} elsif ($pkg =~ qr"^([-a-zA-Z0-9]+)-dirs[-><=]+(.*)$") {
				my ($dirs, $version) = ($1, $2);

				$line->log_warning("Please use USE_DIRS+=${dirs}-${version} instead of this dependency.");
			}

		} elsif ($value =~ qr":\.\./[^/]+$") {
			$line->log_warning("Dependencies should have the form \"../../category/package\".");
			$line->explain_warning(expl_relative_dirs);

		} else {
			$line->log_warning("Unknown dependency format.");
			$line->explain_warning(
				"Examples for valid dependencies are:",
				"  package-[0-9]*:../../category/package",
				"  package>=3.41:../../category/package",
				"  package-2.718:../../category/package");
		}

	} elsif ($type eq "DistSuffix") {
		if ($value eq ".tar.gz") {
			$line->log_note("${varname} is \".tar.gz\" by default, so this definition may be redundant.");
		}

	} elsif ($type eq "Filename") {
		if ($value_novar !~ qr"^[-0-9\@A-Za-z.,_~+%]*$") {
			$line->log_warning("\"${value}\" is not a valid filename.");
		}

	} elsif ($type eq "Filemask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?]*$") {
			$line->log_warning("\"${value}\" is not a valid filename mask.");
		}

	} elsif ($type eq "Identifier") {
		if ($value ne $value_novar) {
			#$line->log_warning("Identifiers should be given directly.");
		}
		if ($value_novar =~ qr"^[+\-.0-9A-Z_a-z]+$") {
			# Fine.
		} elsif ($value ne "" && $value_novar eq "") {
			# Don't warn here.
		} else {
			$line->log_warning("Invalid identifier \"${value}\".");
		}

	} elsif ($type eq "Integer") {
		if ($value !~ qr"^\d+$") {
			$line->log_warning("${varname} must be a valid integer.");
		}

	} elsif ($type eq "LdFlag") {
		if ($value =~ qr"^-L(.*)") {
			my ($dirname) = ($1);

			$opt_debug and $line->log_warning("Unchecked directory ${dirname} in ${varname}.");

		} elsif ($value =~ qr"^-l(.*)") {
			my ($libname) = ($1);

			$opt_debug and $line->log_warning("Unchecked library name ${libname} in ${varname}.");

		} elsif ($value =~ qr"^(?:-static)$") {
			# Assume that the wrapper framework catches these.

		} elsif ($value =~ qr"^(-Wl,(?:-R|-rpath|--rpath))") {
			my ($rpath_flag) = ($1);
			$line->log_warning("Please use \${COMPILER_RPATH_FLAG} instead of ${rpath_flag}.");

		} elsif ($value =~ qr"^-.*") {
			$line->log_warning("Unknown linker flag \"${value}\".");

		} elsif ($value =~ regex_unresolved) {
			$line->log_debug("Unresolved LDFLAG: ${value}\n");

		} else {
			$line->log_warning("Linker flag \"${value}\" does not start with a dash.");
		}

	} elsif ($type eq "License") {

		use constant deprecated_licenses => array_to_hash(qw(
			fee-based-commercial-use
			no-commercial-use no-profit no-redistribution
			shareware
		));

		my $license_file = "${current_dir}/${pkgsrcdir}/licenses/${value}";
		if (exists($makevar->{"LICENSE_FILE"})) {
			$license_file = "${current_dir}/" . $makevar->{"LICENSE_FILE"};
		}
		if (!-f $license_file) {
			$line->log_warning("License file ${license_file} does not exist.");
		}

		if (exists(deprecated_licenses->{$value})) {
			$line->log_warning("License ${value} is deprecated.");
		}

	} elsif ($type eq "Mail_Address") {
		if ($value =~ qr"^([+\-.0-9A-Z_a-z]+)\@([-\w\d.]+)$") {
			my ($localpart, $domain) = ($1, $2);
			if ($domain =~ qr"^NetBSD.org"i && $domain ne "NetBSD.org") {
				$line->log_warning("Please write NetBSD.org instead of ${domain}.");
			}
			if ($domain =~ qr"^NetBSD.org"i && $localpart eq "tech-pkg") {
				$line->log_warning("Unmaintained packages should have pkgsrc-users\@NetBSD.org as maintainer.");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid mail address.");
		}

	} elsif ($type eq "Message") {
		if ($value =~ qr"^[\"'].*[\"']$") {
			$line->log_warning("${varname} should not be quoted.");
		}

	} elsif ($type eq "Option") {
		if ($value ne $value_novar) {
			$line->log_info("Skipped check for unresolved \"${value}\" as Option name.");

		} elsif ($value_novar =~ qr"^-?([a-z][-0-9a-z]*)$") {
			my ($optname) = ($1);

			if (!exists(get_pkg_options()->{$optname})) {
				$line->log_warning("Unknown option \"${value}\".");
				$line->explain_warning(
					"This option is not documented in the mk/defaults/options.description",
					"file. If this is not a typo, please think of a brief but precise",
					"description and ask on the tech-pkg\@NetBSD.org for inclusion in the",
					"database.");
			}

		} elsif ($value_novar =~ qr"^-?([a-z][-0-9a-z_]*)$") {
			my ($optname) = ($1);

			$line->log_warning("Use of the underscore character in option names is deprecated.");

		} else {
			$line->log_error("\"${value}\" is not a valid option name.");
		}

	} elsif ($type eq "Pathlist") {
		my (@paths) = split(qr":", $value_novar);

		foreach my $p (@paths) {
			checkline_mk_vartype_basic($line, $varname, "Pathname", $op, $p, $comment, false);
		}

	} elsif ($type eq "Pathmask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?/\[\]]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname mask.");
		}

	} elsif ($type eq "Pathname") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname.");
		}

	} elsif ($type eq "Perl5Packlist") {
		if ($value ne $value_novar) {
			$line->log_warning("${varname} should not depend on other variables.");
		}

	} elsif ($type eq "PkgName") {
		if ($value eq $value_novar && $value !~ regex_pkgname) {
			$line->log_warning("\"${value}\" is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.");
		}

	} elsif ($type eq "PkgOptionsVar") {
		checkline_mk_vartype_basic($line, $varname, "Varname", $op, $value, $comment, false);
		if ($value =~ qr"\$\{PKGBASE[:\}]") {
			$line->log_error("PKGBASE must not be used in PKG_OPTIONS_VAR.");
			$line->explain_error(
				"PKGBASE is defined in bsd.pkg.mk, which is included as the",
				"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
				"Use \${PKGNAME:C/-[0-9].*//} instead.");
		}

	} elsif ($type eq "PkgRevision") {
		if ($value !~ qr"^[1-9]\d*$") {
			$line->log_warning("${varname} must be a positive integer number.");
		}
		if ($line->fname !~ qr"(?:^|/)Makefile$") {
			$line->log_error("${varname} must not be set outside the package Makefile.");
		}

	} elsif ($type eq "PlatformTriple") {
		my $part = qr"(?:\[[^\]]+\]|[^-\[])+";
		if ($value =~ qr"^(${part})-(${part})-(${part})$") {
			my ($opsys, $os_version, $arch) = ($1, $2, $3);

			if ($opsys !~ qr"^(?:\*|Darwin|DragonFly|FreeBSD|Interix|Linux|NetBSD|OpenBSD|SunOS|IRIX)$") {
				$line->log_warning("Unknown operating system: ${opsys}");
			}
			# no check for $os_version
			if ($arch !~ qr"^(?:\*|i386|alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|hpcmips|hpcsh|hppa|ia64|m68k|m88k|mips|mips64|mipsel|mipseb|mipsn32|ns32k|pc532|pmax|powerpc|rs6000|s390|sparc|sparc64|vax|x86_64)$") {
				$line->log_warning("Unknown hardware architecture: ${arch}");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid platform triple.");
			$line->explain_warning(
				"A platform triple has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
				"Each of these components may be a shell globbing expression.",
				"Examples: NetBSD-*-i386, *-*-*, Linux-*-*.");
		}

	} elsif ($type eq "RelativePkgDir") {
		checkline_relative_pkgdir($line, $value);

	} elsif ($type eq "RelativePkgPath") {
		checkline_relative_path($line, $value);

	} elsif ($type eq "Restricted") {
		if ($value ne "\${RESTRICTED}") {
			$line->log_warning("The only valid value for this variable is \${RESTRICTED}.");
		}

	} elsif ($type eq "SVR4PkgName") {
		if ($value =~ regex_unresolved) {
			$line->log_error("SVR4_PKGNAME must not contain references to other variables.");
		} elsif (length($value) > 5) {
			$line->log_error("SVR4_PKGNAME must not be longer than 5 characters.");
		}

	} elsif ($type eq "SedCommands") {
		my $words = shell_split($value);
		if (!$words) {
			$line->log_error("Invalid shell words in sed commands.");

		} else {
			my $nwords = scalar(@{$words});
			my $ncommands = 0;

			for (my $i = 0; $i < $nwords; $i++) {
				my $word = $words->[$i];
				checkline_mk_shellword($line, $word, true);

				if ($word eq "-e") {
					if ($i + 1 < $nwords) {
						# Check the real sed command here.
						$i++;
						$ncommands++;
						if ($ncommands > 1) {
							$line->log_warning("Each sed command should appear in an assignment of its own.");
						}
						checkline_mk_shellword($line, $word, true);
					} else {
						$line->log_error("The -e option to sed requires an argument.");
					}
				} elsif ($word eq "-E") {
					# Switch to extended regular expressions mode.

				} elsif ($word eq "-n") {
					# Don't print lines per default.

				} elsif ($i == 0 && $word =~ qr"^([\"']?)(?:\d*|/.*/)s(.).*\2g?\1$") {
					$line->log_warning("Please always use \"-e\" in sed commands, even if there is only one substitution.");

				} else {
					$line->log_warning("Unknown sed command ${word}.");
				}
			}
		}

	} elsif ($type eq "ShellCommand") {
		checkline_mk_shelltext($line, $value);

	} elsif ($type eq "ShellWord") {
		if (!$list_context) {
			checkline_mk_shellword($line, $value, true);
		}

	} elsif ($type eq "Stage") {
		if ($value !~ qr"^(?:pre|do|post)-(?:extract|patch|configure|build|install)$") {
			$line->log_warning("Invalid stage name. Use one of {pre,do,post}-{extract,patch,configure,build,install}.");
		}

	} elsif ($type eq "String") {
		# No further checks possible.

	} elsif ($type eq "Tool") {
		if ($value =~ qr"^([-\w]+|\[)(?::(\w+))?$") {
			my ($toolname, $tooldep) = ($1, $2);
			if (!exists(get_tool_names()->{$toolname})) {
				$line->log_error("Unknown tool \"${toolname}\".");
			}
			if (defined($tooldep) && $tooldep !~ qr"^(?:build|pkgsrc|run)$") {
				$line->log_error("Unknown tool dependency \"${tooldep}\". Use one of \"build\", \"pkgsrc\" or \"run\".");
			}
		} else {
			$line->log_error("Invalid tool syntax: \"${value}\".");
		}

	} elsif ($type eq "Unchecked") {
		# Do nothing, as the name says.

	} elsif ($type eq "URL") {
		if ($value eq "" && defined($comment) && $comment =~ qr"^#") {
			# Ok

		} elsif ($value =~ qr"\$\{(MASTER_SITE_.*):=(.*)\}$") {
			my ($name, $subdir) = ($1, $2);

			if (!exists(get_dist_sites_names()->{$name})) {
				$line->log_error("${name} does not exist.");
			}
			if ($subdir !~ qr"/$") {
				$line->log_error("The subdirectory in ${name} must end with a slash.");
			}

		} elsif ($value =~ regex_unresolved) {
			# No further checks

		} elsif ($value =~ qr"^(?:http://|ftp://|gopher://)[-0-9A-Za-z.]+(?::\d+)?/([-%&+,./0-9:=?\@A-Z_a-z~]|\\#)*?$") {
			my $sites = get_dist_sites();

			foreach my $site (keys(%{$sites})) {
				if (index($value, $site) == 0) {
					my $subdir = substr($value, length($site));
					$line->log_warning(sprintf("Please use \${%s:=%s} instead of \"%s\".", $sites->{$site}, $subdir, $value));
					last;
				}
			}

		} elsif ($value =~ qr"^([0-9A-Za-z]+)://([^/]+)(.*)$") {
			my ($scheme, $host, $abs_path) = ($1, $2, $3);

			if ($scheme ne "ftp" && $scheme ne "http" && $scheme ne "gopher") {
				$line->log_warning("\"${value}\" is not a valid URL. Only http, ftp and gopher URLs are allowed here.");

			} elsif ($abs_path eq "") {
				$line->log_note("For consistency, please add a trailing slash to \"${value}\".");

			} else {
				$line->log_warning("\"${value}\" is not a valid URL.");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid URL.");
		}

	} elsif ($type eq "UserGroupName") {
		if ($value ne $value_novar) {
			# No checks for now.
		} elsif ($value !~ qr"^[0-9_a-z]+$") {
			$line->log_warning("Invalid user or group name \"${value}\".");
		}

	} elsif ($type eq "Varname") {
		if ($value ne "" && $value_novar eq "") {
			# The value of another variable

		} elsif ($value_novar !~ qr"^[A-Z_][0-9A-Z_]*(?:[.].*)?$") {
			$line->log_warning("\"${value}\" is not a valid variable name.");
		}

	} elsif ($type eq "Version") {
		if ($value !~ qr"^([\d.])+$") {
			$line->log_warning("Invalid version number \"${value}\".");
		}

	} elsif ($type eq "WrapperReorder") {
		if ($value =~ qr"^reorder:l:([\w\-]+):([\w\-]+)$") {
			my ($lib1, $lib2) = ($1, $2);
			# Fine.
		} else {
			$line->log_warning("Invalid wrapper reorder command \"${value}\".");
		}

	} elsif ($type eq "WrapperTransform") {
		if ($value =~ qr"^rm:(?:-[DILOUWflm].*|-std=.*)$") {
			# Fine.

		} elsif ($value =~ qr"^l:([^:]+):(.+)$") {
			my ($lib, $replacement_libs) = ($1, $2);
			# Fine.

		} elsif ($value =~ qr"^'?(?:opt|rename|rm-optarg|rmdir):.*$") {
			# FIXME: This is cheated.
			# Fine.

		} elsif ($value eq "-e" || $value =~ qr"^\"?'?s[|:,]") {
			# FIXME: This is cheated.
			# Fine.

		} else {
			$line->log_warning("Invalid wrapper transform command \"${value}\".");
		}

	} elsif ($type eq "WrkdirSubdirectory") {
		$opt_debug and $line->log_warning("Unchecked subdirectory \"${value}\" of \${WRKSRC}.");

	} elsif ($type eq "WrksrcSubdirectory") {
		if ($value =~ qr"^(\$\{WRKSRC\})(?:/(.*))?") {
			my ($prefix, $rest) = ($1, $2);
			$line->log_note("You can use \"" . (defined($rest) ? $rest : ".") . "\" instead of \"${value}\".");

		} elsif ($value ne "" && $value_novar eq "") {
			# The value of another variable

		} elsif ($value_novar !~ qr"^(?:\.|[0-9A-Za-z][-0-9A-Za-z._/+]*)$") {
			$line->log_warning("\"${value}\" is not a valid subdirectory of \${WRKSRC}.");
		}

	} elsif ($type eq "Yes") {
		if ($value !~ qr"^(?:YES|yes)(?:\s+#.*)?$") {
			$line->log_warning("${varname} should be set to YES or yes.");
		}

	} elsif ($type eq "YesNo") {
		if ($value !~ qr"^(?:YES|yes|NO|no)(?:\s+#.*)?$") {
			$line->log_warning("${varname} should be set to YES, yes, NO, or no.");
		}

	} elsif ($type eq "YesNo_Indirectly") {
		if ($value_novar ne "" && $value !~ qr"^(?:YES|yes|NO|no)(?:\s+#.*)?$") {
			$line->log_warning("${varname} should be set to YES, yes, NO, or no.");
		}

	} else {
		$line->log_fatal("Type ${type} unknown.");
	}
}

sub checkline_mk_vartype($$$$$) {
	my ($line, $varname, $op, $value, $comment) = @_;
	my ($guessed);

	return unless $opt_warn_types;

	my $vartypes = get_vartypes_map();
	my $varbase = varname_base($varname);
	my $varcanon = varname_canon($varname);

	my $type = exists($vartypes->{$varname}) ? $vartypes->{$varname}
		: exists($vartypes->{$varcanon}) ? $vartypes->{$varcanon}
		: undef;

	if ($op eq "+=") {
		if ($varbase !~ qr"^_" && $varbase !~ get_regex_plurals()) {
			$line->log_warning("As ${varname} is modified using \"+=\", its name should indicate plural.");
		}
	}

		$guessed = false;
		if (!defined($type)) {
			# Guess the datatype of the variable based on
			# naming conventions.
			$type =	  ($varname =~ qr"DIRS$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", [])
				: ($varname =~ qr"(?:DIR|_HOME)$") ? PkgLint::Type->new(LK_NONE, "Pathname", [])
				: ($varname =~ qr"FILES$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", [])
				: ($varname =~ qr"FILE$") ? PkgLint::Type->new(LK_NONE, "Pathname", [])
				: ($varname =~ qr"PATH$") ? PkgLint::Type->new(LK_NONE, "Pathlist", [])
				: ($varname =~ qr"PATHS$") ? PkgLint::Type->new(LK_EXTERNAL, "List of Pathname", [])
				: ($varname =~ qr"_USER$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", [])
				: ($varname =~ qr"_GROUP$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", [])
				: ($varname =~ qr"_ENV$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", [])
				: ($varname =~ qr"_CMD$") ? PkgLint::Type->new(LK_NONE, "ShellCommand", [])
				: ($varname =~ qr"_ARGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", [])
				: ($varname =~ qr"_FLAGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", [])
				: $type;
			if (defined($type)) {
				$line->log_info("The guessed type of ${varname} is \"${type}\"."); # FIXME
			}
			$guessed = true;
		}

		if ((!defined($type) || $guessed) && $varname !~ qr"^_MK$") {
			$opt_debug and $line->log_warning("[checkline_mk_vartype] Untyped variable ${varname}.");
		}

		if (!defined($type)) {
			# Cannot check anything if the type is not known.

		} elsif ($op eq "!=") {
			$opt_debug and $line->log_info("Use of !=: ${value}");

		} elsif ($type->kind_of_list != LK_NONE) {
			my (@words, $rest);

			if ($type->kind_of_list == LK_INTERNAL) {
				@words = split(qr"\s+", $value);
				$rest = "";
			} else {
				@words = ();
				$rest = $value;
				while ($rest =~ s/^$regex_shellword//) {
					my ($word) = ($1);
					last if ($word =~ qr"^#");
					push(@words, $1);
				}
			}

			foreach my $word (@words) {
				checkline_mk_vartype_basic($line, $varname, $type->basic_type, $op, $word, $comment, true);
				if ($type->kind_of_list != LK_INTERNAL) {
					checkline_mk_shellword($line, $word, true);
				}
			}

			if ($rest !~ qr"^\s*$") {
				$opt_debug and $line->log_warning("Invalid shell word \"${value}\" at the end.");
			}

		} else {
			checkline_mk_vartype_basic($line, $varname, $type->basic_type, $op, $value, $comment, !type_should_be_quoted($type));
		}
}

sub checkline_mk_varassign($$$$$) {
	my ($line, $varname, $op, $value, $comment) = @_;
	my $varbase = varname_base($varname);
	my $varcanon = varname_canon($varname);

	checkline_mk_vardef($line, $varname, $op);

	if ($op eq "?=" && defined($seen_bsd_prefs_mk) && !$seen_bsd_prefs_mk) {
		if ($varbase eq "BUILDLINK_PKGSRCDIR"
		    || $varbase eq "BUILDLINK_DEPMETHOD"
		    || $varbase eq "BUILDLINK_ABI_DEPENDS") {
			# FIXME: What about these ones? They occur quite often.
		} else {
			$opt_warn_extra and $line->log_warning("Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".");
		}
	}

	checkline_mk_text($line, $value);
	checkline_mk_vartype($line, $varname, $op, $value, $comment);

	# If the variable is not used and is untyped, it may be a
	# spelling mistake.
	if (defined($varuse)) {
		my $vartypes = get_vartypes_map();
		my $deprecated = get_deprecated_map();

		if (exists($varuse->{$varname}) || exists($varuse->{$varcanon})) {
			# Ok
		} elsif (exists($vartypes->{$varname}) || exists($vartypes->{$varcanon})) {
			# Ok
		} elsif (exists($deprecated->{$varname}) || exists($deprecated->{$varcanon})) {
			# Ok
		} else {
			$line->log_warning("${varname} is defined but not used. Spelling mistake?");
		}
	}

	if (!$is_internal && $varname =~ qr"^_") {
		$line->log_warning("Variable names starting with an underscore are reserved for internal pkgsrc use.");
	}

	if ($varname eq "PERL5_PACKLIST" && defined($effective_pkgbase) && $effective_pkgbase =~ qr"^p5-(.*)") {
		my ($guess) = ($1);
		$guess =~ s/-/\//g;
		$guess = "auto/${guess}/.packlist";

		my ($ucvalue, $ucguess) = (uc($value), uc($guess));
		if ($ucvalue ne $ucguess && $ucvalue ne "\${PERL5_SITEARCH\}/${ucguess}") {
			$line->log_warning("Unusual value for PERL5_PACKLIST -- \"${guess}\" expected.");
		}
	}

	if (defined($comment) && $comment eq "# defined" && $varname !~ qr".*(?:_MK|_COMMON)$") {
		$line->log_warning("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
	}

	if ($value =~ qr"\$\{(PKGNAME|PKGVERSION)[:\}]") {
		my ($pkgvarname) = ($1);
		if ($varname =~ qr"^PKG_.*_REASON$") {
			# ok
		} elsif ($varname =~ qr"^(?:DIST_SUBDIR|WRKSRC)$") {
			$line->log_warning("${pkgvarname} should not be used in ${varname}, as it sometimes includes the PKGREVISION. Please use ${pkgvarname}_NOREV instead.");
		} else {
			$line->log_info("Use of PKGNAME in ${varname}.");
		}
	}

	if (exists(get_deprecated_map()->{$varname})) {
		$line->log_warning("Definition of ${varname} is deprecated. ".get_deprecated_map()->{$varname});
	} elsif (exists(get_deprecated_map()->{$varcanon})) {
		$line->log_warning("Definition of ${varname} is deprecated. ".get_deprecated_map()->{$varcanon});
	}

	if ($varname =~ qr"^SITES_") {
		$line->log_warning("SITES_* is deprecated. Please use SITES.* instead.");
	}

	if ($value =~ qr"^[^=]\@comment") {
		$line->log_warning("Please don't use \@comment in ${varname}.");
		$line->explain_warning(
			"Here you are defining a variable containing \@comment. As this value",
			"typically includes a space as the last character you probably also used",
			"quotes around the variable. This can lead to confusion when adding this",
			"variable to PLIST_SUBST, as all other variables are quoted using the :Q",
			"operator when they are appended. As it is hard to check whether a",
			"variable that is appended to PLIST_SUBST is already quoted or not, you",
			"should not have pre-quoted variables at all. To solve this, you should",
			"directly use PLIST_SUBST+= ${varname}=${value} or use any other",
			"variable for collecting the list of PLIST substitutions and later",
			"append that variable with PLIST_SUBST+= \${MY_PLIST_SUBST}.");
	}
}

#
# Procedures to check an array of lines.
#

sub checklines_trailing_empty_lines($) {
	my ($lines) = @_;
	my ($last, $max);

	$max = $#{$lines} + 1;
	for ($last = $max; $last > 1 && $lines->[$last - 1]->text eq ""; ) {
		$last--;
	}
	if ($last != $max) {
		$lines->[$last]->log_note("Trailing empty lines.");
	}
}

sub checklines_package_Makefile_varorder($) {
	my ($lines) = @_;

	return unless $opt_warn_varorder;

# TODO: Add support for optional sections with non-optional variables.

	use constant once	=> 0;
	use constant optional	=> 1;
	use constant many	=> 2;
	my (@sections) = (
		[ "initial comments", once,
			[
			]
		],
		[ "DISTNAME", once,
			[
				[ "DISTNAME", once ],
				[ "PKGNAME",  optional ],
				[ "PKGREVISION", optional ],
				[ "SVR4_PKGNAME", optional ],
				[ "CATEGORIES", once ],
				[ "MASTER_SITES", once ],
				[ "DYNAMIC_MASTER_SITES", optional ],
				[ "MASTER_SITE_SUBDIR", optional ],
				[ "EXTRACT_SUFX", optional ],
				[ "DISTFILES", many ],
# The following are questionable.
#				[ "NOT_FOR_PLATFORM", optional ],
#				[ "ONLY_FOR_PLATFORM", optional ],
#				[ "NO_BIN_ON_FTP", optional ],
#				[ "NO_SRC_ON_FTP", optional ],
#				[ "NO_BIN_ON_CDROM", optional ],
#				[ "NO_SRC_ON_CDROM", optional ],
			]
		],
		[ "PATCH_SITES", optional,
			[
				[ "PATCH_SITES", optional ], # or once?
				[ "PATCH_SITE_SUBDIR", optional ],
				[ "PATCHFILES", optional ], # or once?
				[ "PATCH_DIST_ARGS", optional ],
				[ "PATCH_DIST_STRIP", optional ],
				[ "PATCH_DIST_CAT", optional ],
			]
		],
		[ "MAINTAINER", once,
			[
				[ "MAINTAINER", once ],
				[ "HOMEPAGE", optional ],
				[ "COMMENT", once ],
			]
		],
		[ "DEPENDS", optional,
			[
				[ "BUILD_DEPENDS", many ],
				[ "DEPENDS", many ],
			]
		]
	);

	if (!defined($seen_Makefile_common) || $seen_Makefile_common) {
		return;
	}

	my ($lineno, $sectindex, $varindex) = (0, -1, 0);
	my ($next_section, $vars, $below, $below_what) = (true, undef, {}, undef);

	# In each iteration, one of the following becomes true:
	# - new.lineno > old.lineno
	# - new.sectindex > old.sectindex
	# - new.sectindex == old.sectindex && new.varindex > old.varindex
	# - new.next_section == true && old.next_section == false
	while ($lineno <= $#{$lines}) {
		my $line = $lines->[$lineno];
		my $text = $line->text;

		$line->log_debug("[varorder] section ${sectindex} variable ${varindex}.");

		if ($next_section) {
			$next_section = false;
			$sectindex++;
			last if ($sectindex > $#sections);
			$vars = $sections[$sectindex]->[2];
			$varindex = 0;
		}

		if ($text =~ qr"^#") {
			$lineno++;

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			if (exists($below->{$varname})) {
				if (defined($below->{$varname})) {
					$line->log_warning("${varname} appears too late. Please put it below $below->{$varname}.");
				} else {
					$line->log_warning("${varname} appears too late. It should be the very first definition.");
				}
				$lineno++;
				next;
			}

			while ($varindex <= $#{$vars} && $varname ne $vars->[$varindex]->[0] && $vars->[$varindex]->[1] != once) {
				$below->{$vars->[$varindex]->[0]} = $below_what;
				$varindex++;
			}
			if ($varindex > $#{$vars}) {
				if ($sections[$sectindex]->[1] != optional) {
					$line->log_warning("Empty line expected.");
				}
				$next_section = true;

			} elsif ($varname ne $vars->[$varindex]->[0]) {
				$line->log_warning("Expected " . $vars->[$varindex]->[0] . ", but found " . $varname . ".");
				$lineno++;

			} else {
				if ($vars->[$varindex]->[1] != many) {
					$below->{$vars->[$varindex]->[0]} = $below_what;
					$varindex++;
				}
				$lineno++;
			}
			$below_what = $varname;

		} else {
			while ($varindex <= $#{$vars}) {
				if ($vars->[$varindex]->[1] == once) {
					$line->log_warning($vars->[$varindex]->[0] . " should be set here.");
				}
				$below->{$vars->[$varindex]->[0]} = $below_what;
				$varindex++;
			}
			$next_section = true;
			if ($text eq "") {
				$below_what = "the previous empty line";
				$lineno++;
			}
		}
	}
}

sub checklines_mk($) {
	my ($lines) = @_;
	my ($allowed_targets, $for_variables) = ({}, {});

	# Define global variables for the Makefile context.
	$mkctx_indentations = [0];
	$mkctx_target = undef;

	foreach my $prefix (qw(pre do post)) {
		foreach my $action (qw(fetch extract patch tools wrapper configure build test install package clean)) {
			$allowed_targets->{"${prefix}-${action}"} = true;
		}
	}

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);
		checkline_spellcheck($line);

		if ($text =~ qr"^\s*$" || $text =~ qr"^#") {
			# Ignore empty lines and comments

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);
			my $space1 = substr($text, $+[1], $-[2] - $+[1]);
			my $align = substr($text, $+[2], $-[3] - $+[2]);
			if ($align !~ qr"^(\t*|[ ])$") {
				$opt_warn_space && $line->log_note("Alignment of variable values should be done with tabs, not spaces.");
				my $prefix = "${varname}${space1}${op}";
				my $aligned_len = tablen("${prefix}${align}");
				if ($aligned_len % 8 == 0) {
					my $tabalign = ("\t" x (($aligned_len - tablen($prefix) + 7) / 8));
					$line->replace("${prefix}${align}", "${prefix}${tabalign}");
				}
			}
			checkline_mk_varassign($line, $varname, $op, $value, $comment);

		} elsif ($text =~ regex_shellcmd) {
			my ($shellcmd) = ($1);
			checkline_mk_shellcmd($line, $shellcmd);

		} elsif ($text =~ regex_mk_include) {
			my ($includefile) = ($1);

			$line->log_debug("includefile=${includefile}");
			checkline_relative_path($line, $includefile);

			if ($includefile =~ qr"../Makefile$") {
				$line->log_error("Other Makefiles must not be included.");
				$line->explain_warning(
					"If you want to include portions of another Makefile, extract",
					"the common parts and put them into a Makefile.common. After",
					"that, both this one and the other package should include the",
					"Makefile.common.");
			}

			if ($includefile eq "../../mk/bsd.prefs.mk") {
				$seen_bsd_prefs_mk = true;
			}

			if ($includefile =~ qr"/x11-links/buildlink3\.mk$") {
				$line->log_error("${includefile} must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.");
			}
			if ($includefile =~ qr"(.*)/builtin\.mk$") {
				my ($dir) = ($1);
				$line->log_error("${includefile} must not be included directly. Include \"${dir}/buildlink3.mk\" instead.");
			}

		} elsif ($text =~ regex_mk_cond) {
			my ($indent, $directive, $args, $comment) = ($1, $2, $3, $4);

			use constant regex_directives_with_args => qr"^(?:if|ifdef|ifndef|elif|for|undef)$";

			if ($directive =~ qr"^(?:endif|endfor|elif|else)$") {
				if ($#{$mkctx_indentations} >= 1) {
					pop(@{$mkctx_indentations});
				}
			}

			# Check the indentation
			if ($indent ne " " x $mkctx_indentations->[-1]) {
				$opt_warn_space and $line->log_note("This directive should be indented by ".$mkctx_indentations->[-1]." spaces.");
			}

			if ($directive eq "if" && $args =~ qr"^!defined\([\w]+_MK\)$") {
				push(@{$mkctx_indentations}, $mkctx_indentations->[-1]);

			} elsif ($directive =~ qr"^(?:if|ifdef|ifndef|for|elif|else)$") {
				push(@{$mkctx_indentations}, $mkctx_indentations->[-1] + 2);
			}

			if ($directive =~ regex_directives_with_args && !defined($args)) {
				$line->log_error("\".${directive}\" must be given some arguments.");

			} elsif ($directive !~ regex_directives_with_args && defined($args)) {
				$line->log_error("\".${directive}\" does not take arguments.");

				if ($directive eq "else") {
					$line->log_note("If you meant \"else if\", use \".elif\".");
				}

			} elsif ($directive eq "if" || $directive eq "elif") {
				$opt_debug and $line->log_warning("Unchecked conditional \"${args}\".");

			} elsif ($directive eq "ifdef" || $directive eq "ifndef") {
				if ($args =~ qr"\s") {
					$line->log_error("The \".${directive}\" directive can only handle _one_ argument.");
				} else {
					$line->log_warning("The \".${directive}\" directive is deprecated. Please use \".if "
						. (($directive eq "ifdef" ? "" : "!"))
						. "defined(${args})\" instead.");
				}

			} elsif ($directive eq "for") {
				if ($args =~ qr"^(\S+(?:\s*\S+)*?)\s+in\s+(.*)$") {
					my ($vars, $values) = ($1, $2);

					foreach my $var (split(qr"\s+", $vars)) {
						if (!$is_internal && $var =~ qr"^_") {
							$line->log_warning("Variable names starting with an underscore are reserved for internal pkgsrc use.");
						}

						if ($var =~ qr"^[_a-z][_a-z0-9]*$") {
							# Fine.
						} elsif ($var =~ qr"[A-Z]") {
							$line->log_warning(".for variable names should not contain uppercase letters.");
						} else {
							$line->log_error("Invalid variable name \"${var}\".");
						}

						$for_variables->{$var} = true;
					}
				}

			} elsif ($directive eq "undef" && defined($args)) {
				foreach my $var (split(qr"\s+", $args)) {
					if (exists($for_variables->{$var})) {
						$line->log_note("Using \".undef\" after a \".for\" loop is unnecessary.");
					}
				}
			}

		} elsif ($text =~ regex_mk_dependency) {
			my ($targets, $dependencies) = ($1, $2);

			$line->log_debug("targets=${targets}, dependencies=${dependencies}");
			$mkctx_target = $targets;

			foreach my $target (split(/\s+/, $targets)) {
				if ($target eq ".PHONY") {
					foreach my $dep (split(qr"\s+", $dependencies)) {
						$allowed_targets->{$dep} = true;
					}

				} elsif ($target eq ".ORDER") {
					# TODO: Check for spelling mistakes.

				} elsif (!exists($allowed_targets->{$target})) {
					$line->log_warning("Unusual target \"${target}\".");
					$line->explain_warning(
						"If you really want to define your own targets, you can \"declare\"",
						"them by inserting a \".PHONY: my-target\" line before this line. This",
						"will tell make(1) to not interpret this target's name as a filename.");
				}
			}

		} elsif ($text =~ qr"^\.\s*(\S*)") {
			my ($directive) = ($1);

			$line->log_error("Unknown directive \".${directive}\".");

		} elsif ($text =~ qr"^ ") {
			$line->log_warning("Makefile lines should not start with space characters.");
			$line->explain_warning(
				"If you want this line to contain a shell program, use a tab",
				"character for indentation. Otherwise please remove the leading",
				"white-space.");

		} else {
			$line->log_error("[Internal] Unknown line format: $text");
		}
	}

	checklines_trailing_empty_lines($lines);
	autofix($lines);

	if ($#{$mkctx_indentations} != 0) {
		$lines->[-1]->log_error("Directive indentation is not 0, but ".$mkctx_indentations->[-1]." at EOF.");
	}
	$mkctx_indentations = undef;
	$mkctx_target = undef;
}

#
# Procedures to check a single file.
#

sub checkfile_ALTERNATIVES($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_ALTERNATIVES]");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_buildlink3_mk($) {
	my ($fname) = @_;
	my ($lines, $lineno, $m, $bl_PKGBASE, $bl_pkgbase);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_buildlink3_mk]");

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	checklines_mk($lines);

	$lineno = 0;

	# Header comments
	while ($lineno <= $#{$lines} && (my $text = $lines->[$lineno]->text) =~ qr"^#") {
		if ($text =~ qr"^# XXX") {
			$lines->[$lineno]->log_note("Please read this comment and remove it if appropriate.");
		}
		$lineno++;
	}
	expect_empty_line($lines, \$lineno);

	# This line does not belong here, but appears often.
	if (expect($lines, \$lineno, qr"^BUILDLINK_DEPMETHOD\.(\S+)\?=.*$")) {
		$lines->[$lineno - 1]->log_warning("This line belongs in the fourth paragraph.");
		while ($lines->[$lineno]->text eq "") {
			$lineno++;
		}
	}

	# First paragraph: Reference counters.
	if (!expect($lines, \$lineno, qr"^BUILDLINK_DEPTH:=\t+\$\{BUILDLINK_DEPTH\}\+$")) {
		$lines->[$lineno]->log_warning("BUILDLINK_DEPTH line expected.");
		return;
	}
	if (($m = expect($lines, \$lineno, qr"^(.*)_BUILDLINK3_MK:=\t+\$\{\1_BUILDLINK3_MK\}\+$"))) {
		$bl_PKGBASE = $m->text(1);
		$lines->[$lineno - 1]->log_debug("bl_PKGBASE=${bl_PKGBASE}");
	} else {
		$lines->[$lineno]->log_warning("Expected reference counter incrementing line.");
		return;
	}
	expect_empty_line($lines, \$lineno);

	# Second paragraph: Adding the dependency.
	if (!expect($lines, \$lineno, qr"^\.if !empty\(BUILDLINK_DEPTH:M\+\)$")) {
		if (!expect_text($lines, \$lineno, ".if \${BUILDLINK_DEPTH} == \"+\"")) {
			return;
		}
	}
	if (($m = expect($lines, \$lineno, qr"^BUILDLINK_DEPENDS\+=\t+(\S+)$"))) {
		$bl_pkgbase = $m->text(1);
		$lines->[$lineno - 1]->log_debug("bl_pkgbase=${bl_pkgbase}");
	} else {
		$lines->[$lineno]->log_warning("BUILDLINK_DEPENDS line expected.");
		return;
	}
	if (!expect_text($lines, \$lineno, ".endif")) {
		return;
	}
	expect_empty_line($lines, \$lineno);

	# Third paragraph: Duplicate elimination.
	if (expect($lines, \$lineno, qr"^BUILDLINK_PACKAGES:=\t+\$\{BUILDLINK_PACKAGES:N\Q${bl_pkgbase}\E\}\s+\Q${bl_pkgbase}\E$")) {
		# The compressed form of duplicate elimination.

	} else {
		if (!expect($lines, \$lineno, qr"^BUILDLINK_PACKAGES:=\t+\$\{BUILDLINK_PACKAGES:N\Q${bl_pkgbase}\E\}$")) {
			$lines->[$lineno]->log_warning("Expected duplicate elimination line.");
			return;
		}
		if (!expect($lines, \$lineno, qr"^BUILDLINK_PACKAGES\+=\t+\Q${bl_pkgbase}\E$")) {
			$lines->[$lineno]->log_warning("Expected package addition line.");
			return;
		}
	}
	expect_empty_line($lines, \$lineno);

	# Fourth paragraph: Package information.
	if (!expect($lines, \$lineno, qr"^\.if !empty\(\Q${bl_PKGBASE}\E_BUILDLINK3_MK:M\+\)$")) {
		if (!expect_text($lines, \$lineno, ".if \${${bl_PKGBASE}_BUILDLINK3_MK} == \"+\"")) {
			return;
		}
	}
	while ($lineno <= $#{$lines} && !expect($lines, \$lineno, qr"^\.endif.*$")) {
		if (expect($lines, \$lineno, regex_varassign)) {
			# TODO: Stricter checks.

		} elsif (expect($lines, \$lineno, qr"^(?:#.*)?$")) {
			# Comments and empty lines are fine here.

		} else {
			$opt_debug and $lines->[$lineno]->log_warning("Unexpected line.");
			$lineno++;
		}
	}
	expect_empty_line($lines, \$lineno);

	# Fifth paragraph (optional): Dependencies.
	my $have_dependencies = false;
	my $need_empty_line = false;
	while (true) {
		if (expect($lines, \$lineno, qr"^\.include \"\.\./\.\./([^/]+/[^/]+)/buildlink3\.mk\"$")
		 || expect($lines, \$lineno, qr"^\.include \"\.\./\.\./mk/(\S+)\.buildlink3\.mk\"$")) {
			$have_dependencies = true;
			$need_empty_line = true;
		} elsif ($have_dependencies && expect($lines, \$lineno, qr"^$")) {
			$need_empty_line = false;
		} else {
			last;
		}
	}
	if ($need_empty_line) {
		expect_empty_line($lines, \$lineno);
	}

	# Sixth paragraph: Reference counter.
	if (!expect($lines, \$lineno, qr"^BUILDLINK_DEPTH:=\t+\$\{BUILDLINK_DEPTH:S/\+\$//\}$")) {
		$lines->[$lineno]->log_warning("Expected reference counter decrementing line.");
		return;
	}

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_warning("The file should end here.");
	} else {
		$lines->[$lineno - 1]->log_info("Fine.");
	}
}

sub checkfile_DESCR($) {
	my ($fname) = @_;
	my ($maxchars, $maxlines) = (80, 24);
	my ($descr);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_DESCR]");

	checkperms($fname);
	if (!($descr = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$descr} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	foreach my $line (@{$descr}) {
		checkline_length($line, $maxchars);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, regex_validchars);
		checkline_spellcheck($line);
	}
	checklines_trailing_empty_lines($descr);

	if (@{$descr} > $maxlines) {
		my $line = $descr->[$maxlines];

		$line->log_warning("File too long (should be no more than $maxlines lines).");
		$line->explain_warning(
			"A common terminal size is 80x25 characters. The DESCR file should",
			"fit on one screen. It is also intended to give a _brief_ summary",
			"about the package's contents.");
	}
	autofix($descr);
}

sub checkfile_distinfo($) {
	my ($fname) = @_;
	my ($lines, %in_distinfo, $current_fname, $state);

	use constant DIS_start	=> 0;
	use constant DIS_SHA1	=> 0;	# same as DIS_start
	use constant DIS_RMD160	=> 1;
	use constant DIS_Size	=> 2;

	log_info($fname, NO_LINE_NUMBER, "[checkfile_distinfo]");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	checkline_rcsid($lines->[0], "");
	if (1 <= $#{$lines} && $lines->[1]->text ne "") {
		$lines->[1]->log_note("Empty line expected.");
		$lines->[1]->explain_note("This is merely for aesthetical purposes.");
	}

	$current_fname = undef;
	$state = DIS_start;
	foreach my $line (@{$lines}[2..$#{$lines}]) {
		if ($line->text !~ qr"^(\w+) \(([^)]+)\) = (.*)(?: bytes)?$") {
			$line->log_error("Unknown line type.");
			next;
		}
		my ($alg, $chksum_fname, $sum) = ($1, $2, $3);
		my $is_patch = (($chksum_fname =~ qr"^patch-[A-Za-z0-9]+$") ? true : false);

		if ($alg eq "MD5") {
			$line->log_warning("MD5 checksums are deprecated.");
			$line->explain_warning(
				"Run \"".conf_make." makedistinfo\" to regenerate the distinfo file.");
			next;
		}

		if ($state == DIS_SHA1) {
			if ($alg eq "SHA1") {
				$state = ($is_patch ? DIS_start : DIS_RMD160);
				$current_fname = $chksum_fname;
			} else {
				$line->log_warning("Expected an SHA1 checksum.");
			}

		} elsif ($state == DIS_RMD160) {
			$state = DIS_start;
			if ($alg eq "RMD160") {
				if ($chksum_fname eq $current_fname) {
					$state = DIS_Size;
				} else {
					$line->log_warning("Expected an RMD160 checksum for ${current_fname}, not for ${chksum_fname}.");
				}
			} else {
				if ($chksum_fname eq $current_fname) {
					# This is an error because this really should be fixed.
					$line->log_error("Expected an RMD160 checksum, not ${alg} for ${chksum_fname}.");
				} else {
					$line->log_warning("Expected an RMD160 checksum for ${current_fname}, not ${alg} for ${chksum_fname}.");
				}
			}

		} elsif ($state == DIS_Size) {
			$state = DIS_start;
			if ($alg eq "Size") {
				if ($chksum_fname ne $current_fname) {
					$line->log_warning("Expected a Size checksum for ${current_fname}, not for ${chksum_fname}.");
				}
			} else {
				if ($chksum_fname eq $current_fname) {
					$line->log_warning("Expected a Size checksum, not ${alg} for ${chksum_fname}.");
				} else {
					$line->log_warning("Expected a Size checksum for ${current_fname}, not ${alg} for ${chksum_fname}.");
				}
			}
		}

		if ($is_patch) {
			if (open(PATCH, "< ${current_dir}/${patchdir}/${chksum_fname}")) {
				my $data = "";
				foreach my $patchline (<PATCH>) {
					$data .= $patchline unless $patchline =~ qr"\$NetBSD";
				}
				close(PATCH);
				my $chksum = Digest::SHA1::sha1_hex($data);
				if ($sum ne $chksum) {
					$line->log_error("${alg} checksum of ${chksum_fname} differs (expected ${sum}, got ${chksum}). Rerun '".conf_make." makepatchsum'.");
				}
			} elsif (!$hack_php_patches) {
				$line->log_warning("${chksum_fname} does not exist.");
				$line->explain_warning(
					"All patches that are mentioned in a distinfo file should actually exist.",
					"What's the use of a checksum if there is no file to check?");
			}
		}
		$in_distinfo{$chksum_fname} = true;
	}
	checklines_trailing_empty_lines($lines);

	foreach my $patch (<${current_dir}/$patchdir/patch-*>) {
		$patch = basename($patch);
		if (!exists($in_distinfo{$patch})) {
			log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '".conf_make." makepatchsum'.");
		}
	}
}

sub checkfile_extra($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_extra]");

	$lines = load_file($fname);
	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	checklines_trailing_empty_lines($lines);
	checkperms($fname);
}

sub checkfile_INSTALL($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_INSTALL]");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_MESSAGE($) {
	my ($fname) = @_;
	my ($message);

	my @explanation = (
		"A MESSAGE file should consist of a header line, having 75 \"=\"",
		"characters, followed by a line containing only the RCS Id, then an",
		"empty line, your text and finally the footer line, which is the",
		"same as the header line.");

	log_info($fname, NO_LINE_NUMBER, "[checkfile_MESSAGE]");

	checkperms($fname);
	if (!($message = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (@{$message} < 3) {
		log_warning($fname, NO_LINE_NUMBER, "File too short.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
		return;
	}
	if ($message->[0]->text ne "=" x 75) {
		$message->[0]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
	}
	checkline_rcsid($message->[1], "");
	foreach my $line (@{$message}) {
		checkline_length($line, 80);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, regex_validchars);
		checkline_spellcheck($line);
	}
	if ($message->[-1]->text ne "=" x 75) {
		$message->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
	}
	checklines_trailing_empty_lines($message);
}

sub checkfile_mk($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_mk]");

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	checklines_mk($lines);
}

sub checkfile_package_Makefile($$$) {
	my ($fname, $whole, $lines) = @_;

	log_info($fname, NO_LINE_NUMBER, "[checkfile_package_Makefile]");

	checkperms($fname);

	if (!exists($makevar->{"PLIST_SRC"})
	    && !exists($makevar->{"NO_PKG_REGISTER"})
	    && defined($pkgdir)
	    && !-f "${current_dir}/$pkgdir/PLIST"
	    && !-f "${current_dir}/$pkgdir/PLIST.common") {
		log_warning($fname, NO_LINE_NUMBER, "Neither PLIST nor PLIST.common exist, and PLIST_SRC and NO_PKG_REGISTER are unset. Are you sure PLIST handling is ok?");
	}

	if (exists($makevar->{"NO_CHECKSUM"}) && is_emptydir("${current_dir}/${patchdir}")) {
		if (-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM is set.");
		}
	} else {
		if (!-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makesum'.");
		}
	}

	if ($whole =~ /etc\/rc\.d/) {
		log_warning($fname, NO_LINE_NUMBER, "Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	if (exists($makevar->{"MASTER_SITES"})) {
		if (exists($makevar->{"DYNAMIC_MASTER_SITES"})) {
			$makevar->{"MASTER_SITES"}->log_warning("MASTER_SITES and ...");
			$makevar->{"DYNAMIC_MASTER_SITES"}->log_warning("... DYNAMIC_MASTER_SITES conflict.");
		}
	} else {
		if (!exists($makevar->{"DYNAMIC_MASTER_SITES"})) {
			log_warning($fname, NO_LINE_NUMBER, "Neither MASTER_SITES nor DYNAMIC_MASTER_SITES found.");
		}
	}

	if (exists($makevar->{"REPLACE_PERL"}) && exists($makevar->{"NO_CONFIGURE"})) {
		$makevar->{"REPLACE_PERL"}->log_warning("REPLACE_PERL is ignored when ...");
		$makevar->{"NO_CONFIGURE"}->log_warning("... NO_CONFIGURE is set.");
	}

	if (exists($makevar->{"RESTRICTED"}) && !exists($makevar->{"LICENSE"})) {
		$makevar->{"RESTRICTED"}->log_error("Restricted packages must have a LICENSE.");
	}

	my $distname_line = $makevar->{"DISTNAME"};
	my $pkgname_line = $makevar->{"PKGNAME"};

	my $distname = (defined($distname_line) && $distname_line->text =~ regex_varassign) ? $3 : undef;
	my $pkgname = (defined($pkgname_line) && $pkgname_line->text =~ regex_varassign) ? $3 : undef;

	if (defined($pkgname) && defined($distname) && ($pkgname eq $distname || $pkgname eq "\${DISTNAME}")) {
		$pkgname_line->log_note("PKGNAME is \${DISTNAME} by default. You don't need to define PKGNAME.");
	}

	if (!defined($pkgname) && defined($distname) && $distname !~ regex_unresolved && $distname !~ regex_pkgname) {
		$distname_line->log_warning("As DISTNAME ist not a valid package name, please define the PKGNAME explicitly.");
	}

	($effective_pkgname, $effective_pkgname_line, $effective_pkgbase, $effective_pkgversion)
		= (defined($pkgname) && $pkgname !~ regex_unresolved && $pkgname =~ regex_pkgname) ? ($pkgname, $pkgname_line, $1, $2)
		: (defined($distname) && $distname !~ regex_unresolved && $distname =~ regex_pkgname) ? ($distname, $distname_line, $1, $2)
		: (undef, undef, undef, undef);
	if (defined($effective_pkgname_line)) {
		$effective_pkgname_line->log_debug("Effective name=${effective_pkgname} base=${effective_pkgbase} version=${effective_pkgversion}.");
	}

	if (!exists($makevar->{"COMMENT"})) {
		log_warning($fname, NO_LINE_NUMBER, "No COMMENT given.");
	}

	if (exists($makevar->{"USE_IMAKE"}) && exists($makevar->{"USE_X11"})) {
		$makevar->{"USE_IMAKE"}->log_note("USE_IMAKE makes ...");
		$makevar->{"USE_X11"}->log_note("... USE_X11 superfluous.");
	}

	if (defined($effective_pkgbase)) {

		foreach my $suggested_update (@{get_suggested_package_updates()}) {
			my ($line, $suggbase, $suggver, $suggcomm) = @{$suggested_update};
			my $comment = (defined($suggcomm) ? " (${suggcomm})" : "");

			next unless $effective_pkgbase eq $suggbase;

			if (dewey_cmp($effective_pkgversion, "<", $suggver)) {
				$effective_pkgname_line->log_warning("This package should be updated to ${suggver}${comment}.");
			}
			if (dewey_cmp($effective_pkgversion, "==", $suggver)) {
				$effective_pkgname_line->log_note("The update request to ${suggver} from doc/TODO${comment} has been done.");
			}
			if (dewey_cmp($effective_pkgversion, ">", $suggver)) {
				$effective_pkgname_line->log_note("This package is newer than the update request to ${suggver}${comment}.");
			}
		}
	}

	checklines_mk($lines);
	checklines_package_Makefile_varorder($lines);
	autofix($lines);
}

sub checkfile_patch($) {
	my ($fname) = @_;
	my ($strings);
	my ($state, $redostate, $nextstate, $dellines, $addlines, $hunks);
	my ($seen_comment, $current_fname, $patched_files);
	my ($leading_context_lines, $trailing_context_lines, $context_scanning_leading);

	# Abbreviations used:
	# style: [c] = context diff, [u] = unified diff
	# scope: [f] = file, [h] = hunk, [l] = line
	# action: [d] = delete, [m] = modify, [a] = add, [c] = context
	use constant re_patch_rcsid	=> qr"^\$.*\$$";
	use constant re_patch_text	=> qr"^(.+)$";
	use constant re_patch_empty	=> qr"^$";
	use constant re_patch_cfd	=> qr"^\*\*\*\s(\S+)(.*)$";
	use constant re_patch_cfa	=> qr"^---\s(\S+)(.*)$";
	use constant re_patch_ch	=> qr"^\*{15}(.*)$";
	use constant re_patch_chd	=> qr"^\*{3}\s(\d+)(?:,(\d+))?\s\*{4}$";
	use constant re_patch_cha	=> qr"^-{3}\s(\d+)(?:,(\d+))?\s-{4}$";
	use constant re_patch_cld	=> qr"^(?:-\s(.*))?$";
	use constant re_patch_clm	=> qr"^(?:!\s(.*))?$";
	use constant re_patch_cla	=> qr"^(?:\+\s(.*))?$";
	use constant re_patch_clc	=> qr"^(?:\s\s(.*))?$";
	use constant re_patch_ufd	=> qr"^---\s(\S+)(?:\s+(.*))?$";
	use constant re_patch_ufa	=> qr"^\+{3}\s(\S+)(?:\s+(.*))?$";
	use constant re_patch_uh	=> qr"^\@\@\s-(?:(\d+),)?(\d+)\s\+(?:(\d+),)?(\d+)\s\@\@(.*)$";
	use constant re_patch_uld	=> qr"^-(.*)$";
	use constant re_patch_ula	=> qr"^\+(.*)$";
	use constant re_patch_ulc	=> qr"^\s(.*)$";
	use constant re_patch_ulnonl	=> qr"^\\ No newline at end of file$";

	use constant PST_START		=> 0;
	use constant PST_CENTER		=> 1;
	use constant PST_TEXT		=> 2;
	use constant PST_CFA		=> 3;
	use constant PST_CH		=> 4;
	use constant PST_CHD		=> 5;
	use constant PST_CLD0		=> 6;
	use constant PST_CLD		=> 7;
	use constant PST_CLA0		=> 8;
	use constant PST_CLA		=> 9;
	use constant PST_UFA		=> 10;
	use constant PST_UH		=> 11;
	use constant PST_UL		=> 12;

	my ($s, $line, $m);

	my $check_text = sub($) {
		my ($text) = @_;

		if ($text =~ qr"(\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|$opt_rcsidstring)(?::[^\$]*|\$))") {
			my ($tag) = ($2);

			if ($text =~ re_patch_uh) {
				$line->log_warning("Found RCS tag \"\$${tag}\$\". Please remove it.");
				$line->set_text($1);
			} else {
				$line->log_warning("Found RCS tag \"\$${tag}\$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".");
			}
		}
	};

	my $check_contents = sub() {

		if ($m->has(1)) {
			$check_text->($m->text(1));
		}
	};

	my $check_added_contents = sub() {
		my $text;

		return unless $m->has(1);
		$text = $m->text(1);
		checkline_cpp_macro_names($line, $text);
		checkline_spellcheck($line);

		# XXX: This check is not as accurate as the similar one in
		# checkline_mk_shelltext().
		if (defined($current_fname) && $current_fname =~ qr"(?:^|/)Makefile(?:\.in|)") {
			my ($mm, $rest) = $s->match_all($regex_shellword);

			foreach my $m (@{$mm}) {
				my $shellword = $m->text(1);
				if ($shellword =~ qr"^/" && $shellword ne "/dev/null") {
					$m->highlight(1);
					$s->log_warning("Found absolute pathname: ${shellword}");
				}
			}
		}
	};

	my $check_hunk_end = sub($$$) {
		my ($deldelta, $adddelta, $newstate) = @_;

		if ($deldelta > 0 && $dellines == 0) {
			$redostate = $newstate;
			if (defined($addlines) && $addlines > 0) {
				$line->log_error("Expected ${addlines} more lines to be added.");
			}
		} elsif ($adddelta > 0 && $addlines == 0) {
			$redostate = $newstate;
			if (defined($dellines) && $dellines > 0) {
				$line->log_error("Expected ${dellines} more lines to be deleted.");
			}
		} else {
			if (defined($context_scanning_leading)) {
				if ($deldelta != 0 && $adddelta != 0) {
					if ($context_scanning_leading) {
						$leading_context_lines++;
					} else {
						$trailing_context_lines++;
					}
				} else {
					if ($context_scanning_leading) {
						$context_scanning_leading = false;
					} else {
						$trailing_context_lines = 0;
					}
				}
			}

			if ($deldelta != 0) {
				$dellines -= $deldelta;
			}
			if ($adddelta != 0) {
				$addlines -= $adddelta;
			}
			if (!((defined($dellines) && $dellines > 0) ||
			      (defined($addlines) && $addlines > 0))) {
				if (defined($context_scanning_leading)) {
					if ($leading_context_lines != $trailing_context_lines) {
						$opt_debug and $line->log_warning("The hunk that ends here does not have as many leading (${leading_context_lines}) as trailing (${trailing_context_lines}) lines of context.");
					}
				}
				$nextstate = $newstate;
			}
		}
	};

	my $check_hunk_line = sub($$$) {
		my ($deldelta, $adddelta, $newstate) = @_;

		$check_contents->();
		$check_hunk_end->($deldelta, $adddelta, $newstate);
	};

	my $transitions =
		[   [PST_START, re_patch_rcsid, PST_CENTER, sub() {
			checkline_rcsid($line, "");
		}], [PST_START, undef, PST_CENTER, sub() {
			checkline_rcsid($line, "");
		}], [PST_CENTER, re_patch_empty, PST_TEXT, sub() {
			#
		}], [PST_TEXT, re_patch_cfd, PST_CFA, sub() {
			if (!$seen_comment) {
				#$opt_warn_style and $line->log_warning("Comment expected.");
			}
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
		}], [PST_TEXT, re_patch_ufd, PST_UFA, sub() {
			if (!$seen_comment) {
				#$opt_warn_style and $line->log_warning("Comment expected.");
			}
		}], [PST_TEXT, re_patch_text, PST_TEXT, sub() {
			$seen_comment = true;
		}], [PST_TEXT, re_patch_empty, PST_TEXT, sub() {
			#
		}], [PST_TEXT, undef, PST_TEXT, sub() {
			#
		}], [PST_CENTER, re_patch_cfd, PST_CFA, sub() {
			if ($seen_comment) {
				$opt_warn_space and $line->log_note("Empty line expected.");
			} else {
				#$opt_warn_style and $line->log_warning("Comment expected.");
			}
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
		}], [PST_CENTER, re_patch_ufd, PST_UFA, sub() {
			if ($seen_comment) {
				$opt_warn_space and $line->log_note("Empty line expected.");
			} else {
				#$opt_warn_style and $line->log_warning("Comment expected.");
			}
		}], [PST_CENTER, undef, PST_TEXT, sub() {
			$opt_warn_space and $line->log_note("Empty line expected.");
		}], [PST_CFA, re_patch_cfa, PST_CH, sub() {
			$current_fname = $m->text(1);
			$patched_files++;
			$hunks = 0;
		}], [PST_CH, re_patch_ch, PST_CHD, sub() {
			$hunks++;
		}], [PST_CHD, re_patch_chd, PST_CLD0, sub() {
			$dellines = ($m->has(2))
			    ? (1 + $m->text(2) - $m->text(1))
			    : ($m->text(1));
		}], [PST_CLD0, re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD0, re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD0, re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD, re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD, re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD, re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [PST_CLD, undef, PST_CLD0, sub() {
			if ($dellines != 0) {
				$line->log_warning("Invalid number of deleted lines (${dellines} missing).");
			}
		}], [PST_CLD0, re_patch_cha, PST_CLA0, sub() {
			$dellines = undef;
			$addlines = ($m->has(2))
			    ? (1 + $m->text(2) - $m->text(1))
			    : ($m->text(1));
		}], [PST_CLA0, re_patch_clc, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [PST_CLA0, re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
			$check_added_contents->();
		}], [PST_CLA0, re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
			$check_added_contents->();
		}], [PST_CLA, re_patch_clc, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [PST_CLA, re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
			$check_added_contents->();
		}], [PST_CLA, re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
			$check_added_contents->();
		}], [PST_CLA, undef, PST_CLA0, sub() {
			if ($addlines != 0) {
				$line->log_warning("Invalid number of added lines (${addlines} missing).");
			}
		}], [PST_CLA0, undef, PST_CH, sub() {
			#
		}], [PST_CH, undef, PST_TEXT, sub() {
			#
		}], [PST_UFA, re_patch_ufa, PST_UH, sub() {
			$current_fname = $m->text(1);
			$patched_files++;
			$hunks = 0;
		}], [PST_UH, re_patch_uh, PST_UL, sub() {
			$dellines = ($m->has(1) ? $m->text(2) : 1);
			$addlines = ($m->has(3) ? $m->text(4) : 1);
			$check_text->($line->text);
			if ($line->text =~ qr"\r$") {
				$line->log_error("The hunk header must not end with a CR character.");
				$line->explain_warning(
					"The MacOS X patch utility cannot handle these.");
			}
			$hunks++;
			$context_scanning_leading = (($m->has(1) && $m->text(1) ne "1") ? true : undef);
			$leading_context_lines = 0;
			$trailing_context_lines = 0;
		}], [PST_UL, re_patch_uld, PST_UL, sub() {
			$check_hunk_line->(1, 0, PST_UH);
		}], [PST_UL, re_patch_ula, PST_UL, sub() {
			$check_hunk_line->(0, 1, PST_UH);
			$check_added_contents->();
		}], [PST_UL, re_patch_ulc, PST_UL, sub() {
			$check_hunk_line->(1, 1, PST_UH);
		}], [PST_UL, re_patch_ulnonl, PST_UL, sub() {
			#
		}], [PST_UL, re_patch_empty, PST_UL, sub() {
			$opt_warn_space and $line->log_note("Leading white-space missing in hunk.");
			$check_hunk_line->(1, 1, PST_UH);
		}], [PST_UL, undef, PST_UH, sub() {
			if ($dellines != 0 || $addlines != 0) {
				$line->log_warning("Unexpected end of hunk (-${dellines},+${addlines} expected).");
			}
		}], [PST_UH, undef, PST_TEXT, sub() {
			($hunks != 0) || $line->log_warning("No hunks for file ${current_fname}.");
		}]];

	log_info($fname, NO_LINE_NUMBER, "[checkfile_patch]");

	checkperms($fname);
	if (!($strings = PkgLint::FileUtil::load_strings($fname, false))) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	if (@{$strings} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	$state = PST_START;
	$dellines = undef;
	$addlines = undef;
	$patched_files = 0;
	$seen_comment = false;
	$current_fname = undef;
	$hunks = undef;

	for (my $lineno = 0; $lineno <= $#{$strings}; ) {
		$s = $strings->[$lineno];
		$line = $s->line;
		my $text = $line->text;

		$opt_debug and $line->log_debug("[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."] $text");

		my $found = false;
		foreach my $t (@{$transitions}) {
			if ($state == $t->[0]) {
				if (!defined($t->[1])) {
					$m = undef;
				} elsif ($text =~ $t->[1]) {
					$opt_debug and $line->log_debug($t->[1]);
					$m = PkgLint::SimpleMatch->new($text, \@-, \@+);
				} else {
					next;
				}
				$redostate = undef;
				$nextstate = $t->[2];
				$t->[3]->();
				if (defined($redostate)) {
					$state = $redostate;
				} else {
					$state = $nextstate;
					if (defined($t->[1])) {
						$lineno++;
					}
				}
				$found = true;
				last;
			}
		}

		if (!$found) {
			$line->log_error("Parse error: state=${state}");
			$state = PST_TEXT;
			$lineno++;
		}
	}

	while ($state != PST_TEXT) {
		$opt_debug and log_debug($fname, "EOF", "[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."]");

		my $found = false;
		foreach my $t (@{$transitions}) {
			if ($state == $t->[0] && !defined($t->[1])) {
				my $newstate;

				$m = undef;
				$redostate = undef;
				$nextstate = $t->[2];
				$t->[3]->();
				$newstate = (defined($redostate)) ? $redostate : $nextstate;
				if ($newstate == $state) {
					log_fatal($fname, "EOF", "Internal error in the patch transition table.");
				}
				$state = $newstate;
				$found = true;
				last;
			}
		}

		if (!$found) {
			log_error($fname, "EOF", "Parse error: state=${state}");
			$state = PST_TEXT;
		}
	}

	if ($patched_files > 1) {
		log_warning($fname, NO_LINE_NUMBER, "Contains patches for $patched_files files, should be only one.");

	} elsif ($patched_files == 0) {
		log_error($fname, NO_LINE_NUMBER, "Contains no patch.");
	}

	checklines_trailing_empty_lines(strings_to_lines($strings));
}

sub checkfile_PLIST($) {
	my ($fname) = @_;
	my ($plist, $last_file_seen, $libtool_libs);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_PLIST]");

	checkperms($fname);
	if (!($plist = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$plist} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}
	checkline_rcsid($plist->[0], "\@comment ");

	# Get all libtool libraries from the PLIST.
	$libtool_libs = {};
	foreach my $line (@{$plist}) {
		my $text = $line->text;

		if ($text =~ qr"^(.*)\.la$") {
			$libtool_libs->{$1} = $line;
		}
	}

	foreach my $line (@{$plist}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);

		if ($text =~ /^\@([a-z]+)\s+(.*)/) {
			my ($cmd, $arg) = ($1, $2);

			if ($cmd eq "unexec" && $arg =~ qr"^(rmdir|\$\{RMDIR\} \%D/)(.*)") {
				my ($rmdir, $rest) = ($1, $2);
				if ($rest !~ qr"(?:true|\$\{TRUE\})") {
					$line->log_warning("Please use \"\@dirrm\" instead of \"\@unexec rmdir\".");
				}

			} elsif (($cmd eq "exec" || $cmd eq "unexec")) {
				if ($arg =~ /(?:install-info|\$\{INSTALL_INFO\})/) {
					$line->log_warning("\@exec/unexec install-info is deprecated.");

				} elsif ($arg =~ /ldconfig/ && $arg !~ qr"/usr/bin/true") {
					$line->log_error("ldconfig must be used with \"||/usr/bin/true\".");
				}

			} elsif ($cmd eq "comment" || $cmd eq "dirrm") {
				# nothing to do

			} else {
				$line->log_warning("Unknown PLIST directive \"\@$cmd\".");
			}

		} elsif ($text =~ qr"^[A-Za-z0-9\$]") {
			if ($opt_warn_plist_sort && $text =~ qr"^\w" && $text !~ regex_unresolved) {
				if (defined($last_file_seen)) {
					if ($last_file_seen gt $text) {
						$line->log_warning("${text} should be sorted before ${last_file_seen}.");
					}
				}
				$last_file_seen = $text;
			}

			if ($text =~ qr"^bin/.*/") {
				$line->log_warning("The bin/ directory should not have subdirectories.");

			} elsif ($text =~ qr"^bin/") {
				# Fine.

			} elsif ($text =~ qr"^doc/") {
				$line->log_error("Documentation must be installed under share/doc, not doc.");

			} elsif ($text =~ qr"^etc/rc\.d/") {
				$line->log_error("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.");

			} elsif ($text =~ qr"^etc/") {
				$line->log_error("Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in mk/install/bsd.pkginstall.mk.");

			} elsif ($text =~ qr"^include/.*\.(?:h|hpp)$") {
				# Fine.

			} elsif ($text eq "info/dir") {
				$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

			} elsif (defined($effective_pkgbase) && $text =~ qr"^lib/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif ($text =~ qr"^lib/locale/") {
				$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^lib/[^/]+\.(?:so|a|la)$") {
				# Fine.

			} elsif ($text =~ qr"^share/doc/html/") {
				$opt_warn_plist_depr and $line->log_warning("Use of \"share/doc/html\" is deprecated. Use \"share/doc/\${PKGBASE}\" instead.");

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/doc/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/examples/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif ($text =~ qr"^share/locale/[\w\@_]+/LC_MESSAGES/[^/]+\.mo$") {
				# Fine.

			} elsif ($text =~ qr"^share/man/") {
				$line->log_warning("Man pages should be installed into man/, not share/man/.");

			} else {
				#$line->log_warning("Unknown pathname \"${text}\".");
			}

			if ($text =~ /\${PKGLOCALEDIR}/ && defined($makevar) && !exists($makevar->{"USE_PKGLOCALEDIR"})) {
				$line->log_warning("PLIST contains \${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.");
			}

			if ($text =~ qr"/CVS/") {
				$line->log_warning("CVS files should not be in the PLIST.");
			}
			if ($text =~ qr"\.orig$") {
				$line->log_warning(".orig files should not be in the PLIST.");
			}
			if ($text =~ qr"/perllocal\.pod$") {
				$line->log_warning("perllocal.pod files should not be in the PLIST.");
				$line->explain_warning(
					"This file is handled automatically by the INSTALL/DEINSTALL scripts,",
					"since its contents changes frequently.");
			}

			if ($text =~ qr"^(.*)(\.a|\.so[0-9.]*)$") {
				my ($basename, $ext) = ($1, $2);

				if (exists($libtool_libs->{$basename})) {
					$line->log_warning("Redundant library found. The libtool library is in line " . $libtool_libs->{$basename}->lines . ".");
				}
			}
		} else {
			$line->log_error("Unknown line type.");
		}
	}
	checklines_trailing_empty_lines($plist);
}

sub checkfile($) {
	my ($fname) = @_;
	my ($st, $basename);

	log_info($fname, NO_LINE_NUMBER, "[checkfile]");

	$basename = basename($fname);
	if ($basename =~ qr"^(?:work.*|.*~|.*\.orig|.*\.rej)$") {
		if ($opt_import) {
			log_error($fname, NO_LINE_NUMBER, "Must be cleaned up before committing the package.");
		}
		return;
	}

	if (!($st = lstat($fname))) {
		log_error($fname, NO_LINE_NUMBER, "$!");
		return;
	}
	if (S_ISDIR($st->mode)) {
		if ($basename eq "files" || $basename eq "patches" || $basename eq "CVS") {
			# Ok

		} elsif (!is_emptydir($fname)) {
			log_warning($fname, NO_LINE_NUMBER, "Unknown directory name.");
		}

	} elsif (S_ISLNK($st->mode)) {
		if ($basename !~ qr"^work") {
			log_warning($fname, NO_LINE_NUMBER, "Unknown symlink name.");
		}

	} elsif (!S_ISREG($st->mode)) {
		log_error($fname, NO_LINE_NUMBER, "Only files and directories are allowed in pkgsrc.");

	} elsif ($basename eq "ALTERNATIVES") {
		$opt_check_ALTERNATIVES and checkfile_ALTERNATIVES($fname);

	} elsif ($basename eq "buildlink3.mk") {
		$opt_check_bl3 and checkfile_buildlink3_mk($fname);

	} elsif ($basename =~ qr"^(?:.*\.mk|Makefile.*)$") {
		$opt_check_mk and checkfile_mk($fname);

	} elsif ($basename =~ qr"^DESCR") {
		$opt_check_DESCR and checkfile_DESCR($fname);

	} elsif ($basename =~ qr"^distinfo") {
		$opt_check_distinfo and checkfile_distinfo($fname);

	} elsif ($basename eq "DEINSTALL" || $basename eq "INSTALL") {
		$opt_check_INSTALL and checkfile_INSTALL($fname);

	} elsif ($basename =~ qr"^MESSAGE") {
		$opt_check_MESSAGE and checkfile_MESSAGE($fname);

	} elsif ($basename =~ qr"^patch-[A-Za-z0-9]*$") {
		$opt_check_patches and checkfile_patch($fname);

	} elsif ($fname =~ qr"(?:^|/)patches/manual-[^/]*$") {
		$opt_debug and log_info($fname, NO_LINE_NUMBER, "Not checked.");

	} elsif ($fname =~ qr"(?:^|/)patches/[^/]*$") {
		log_warning($fname, NO_LINE_NUMBER, "Patch files should be named \"patch-\", followed by letters and digits only.");

	} elsif ($basename =~ qr"^PLIST") {
		$opt_check_PLIST and checkfile_PLIST($fname);

	} elsif ($basename eq "TODO" || $basename eq "README") {
		# Ok

	} elsif (!-T $fname) {
		log_warning($fname, NO_LINE_NUMBER, "Unexpectedly found a binary file.");

	} else {
		log_warning($fname, NO_LINE_NUMBER, "Unexpected file found.");
		$opt_check_extra and checkfile_extra($fname);
	}
}

#
# Procedures to check a directory including the files in it.
#

sub checkdir_root() {
	my ($fname) = "${current_dir}/Makefile";
	my ($lines, $prev_subdir, @subdirs);

	log_info($fname, NO_LINE_NUMBER, "[checkdir_root] Checking pkgsrc root directory.");

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (0 <= $#{$lines}) {
		checkline_rcsid_regex($lines->[0], qr"#\s+", "# ");
	}

	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^(#?)SUBDIR\s*\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $indentation, $subdir, $comment) = ($1, $2, $3, $4);

			if ($comment_flag eq "#" && (!defined($comment) || $comment eq "")) {
				$line->log_warning("${subdir} commented out without giving a reason.");
			}

			if ($indentation ne "\t") {
				$line->log_warning("Indentation should be a single tab character.");
			}

			if ($subdir =~ qr"\$" || !-f "${current_dir}/${subdir}/Makefile") {
				next;
			}

			if (defined($prev_subdir) && $subdir eq $prev_subdir) {
				$line->log_error("${subdir} must only appear once.");
			} elsif (defined($prev_subdir) && $subdir lt $prev_subdir) {
				$line->log_warning("${subdir} should come before ${prev_subdir}.");
			} else {
				# correctly ordered
			}

			$prev_subdir = $subdir;

			if ($comment_flag eq "") {
				push(@subdirs, "${current_dir}/${subdir}");
			}
		}
	}

	if ($opt_recursive) {
		push(@todo_items, @subdirs);
	}
}

sub checkdir_category() {
	my $fname = "${current_dir}/Makefile";
	my ($lines, $lineno);

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	$lineno = 0;

	# The first line must contain the RCS Id
	if ($lineno <= $#{$lines} && checkline_rcsid_regex($lines->[$lineno], qr"#\s+", "# ")) {
		$lineno++;
	}

	# Then, arbitrary comments may follow
	while ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^#") {
		$lineno++;
	}

	# Then we need an empty line
	expect_empty_line($lines, \$lineno);

	# Then comes the COMMENT line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^COMMENT=\t*(.*)") {
		my ($comment) = ($1);

		checkline_valid_characters_in_variable($lines->[$lineno], qr"[-\040'(),/0-9A-Za-z]");
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("COMMENT= line expected.");
	}

	# Then we need an empty line
	expect_empty_line($lines, \$lineno);

	# And now to the most complicated part of the category Makefiles,
	# the (hopefully) sorted list of SUBDIRs. The first step is to
	# collect the SUBDIRs in the Makefile and in the file system.

	my (@f_subdirs, @m_subdirs);

	@f_subdirs = sort(get_subdirs($current_dir));

	my $prev_subdir = undef;
	while ($lineno <= $#{$lines}) {
		my $line = $lines->[$lineno];

		if ($line->text =~ qr"^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $indentation, $subdir, $comment) = ($1, $2, $3, $4);

			if ($comment_flag eq "#" && (!defined($comment) || $comment eq "")) {
				$line->log_warning("${subdir} commented out without giving a reason.");
			}

			if ($indentation ne "\t") {
				$line->log_warning("Indentation should be a single tab character.");
			}

			if (defined($prev_subdir) && $subdir eq $prev_subdir) {
				$line->log_error("${subdir} must only appear once.");
			} elsif (defined($prev_subdir) && $subdir lt $prev_subdir) {
				$line->log_warning("${subdir} should come before ${prev_subdir}.");
			} else {
				# correctly ordered
			}

			push(@m_subdirs, [$subdir, $line, $comment_flag ? false : true]);
			$prev_subdir = $subdir;
			$lineno++;

		} else {
			if ($line->text ne "") {
				$line->log_error("SUBDIR+= line or empty line expected.");
			}
			last;
		}
	}

	# To prevent unnecessary warnings about subdirectories that are
	# in one list, but not in the other, we generate the sets of
	# subdirs of each list.
	my (%f_check, %m_check);
	foreach my $f (@f_subdirs) { $f_check{$f} = true; }
	foreach my $m (@m_subdirs) { $m_check{$m->[0]} = true; }

	my ($f_index, $f_atend, $f_neednext, $f_current) = (0, false, true, undef, undef);
	my ($m_index, $m_atend, $m_neednext, $m_current) = (0, false, true, undef, undef);
	my ($line, $m_recurse);
	my (@subdirs);

	while (!($m_atend && $f_atend)) {

		if (!$m_atend && $m_neednext) {
			$m_neednext = false;
			if ($m_index > $#m_subdirs) {
				$m_atend = true;
				$line = $lines->[$lineno];
				next;
			} else {
				$m_current = $m_subdirs[$m_index]->[0];
				$line = $m_subdirs[$m_index]->[1];
				$m_recurse = $m_subdirs[$m_index]->[2];
				$m_index++;
			}
		}

		if (!$f_atend && $f_neednext) {
			$f_neednext = false;
			if ($f_index > $#f_subdirs) {
				$f_atend = true;
				next;
			} else {
				$f_current = $f_subdirs[$f_index++];
			}
		}

		if (!$f_atend && ($m_atend || $f_current lt $m_current)) {
			if (!exists($m_check{$f_current})) {
				$line->log_error("${f_current} exists in the file system, but not in the Makefile.");
				$line->append_before("SUBDIR+=\t${f_current}");
			}
			$f_neednext = true;

		} elsif (!$m_atend && ($f_atend || $m_current lt $f_current)) {
			if (!exists($f_check{$m_current})) {
				$line->log_error("${m_current} exists in the Makefile, but not in the file system.");
				$line->delete();
			}
			$m_neednext = true;

		} else { # $f_current eq $m_current
			$f_neednext = true;
			$m_neednext = true;
			if ($m_recurse) {
				push(@subdirs, "${current_dir}/${m_current}");
			}
		}
	}

	# the wip category Makefile may have its own targets for generating
	# indexes and READMEs. Just skip them.
	if ($is_wip) {
		while ($lineno <= $#{$lines} - 2) {
			$lineno++;
		}
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

	# And, last but not least, the .include line
	my $final_line = ".include \"../mk/bsd.pkg.subdir.mk\"";
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq $final_line) {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Expected this: ${final_line}.");
	}

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_error("The file should end here.");
	}

	autofix($lines);

	if ($opt_recursive) {
		unshift(@todo_items, @subdirs);
	}
}

sub checkdir_package() {
	my ($whole, $lines, $have_distinfo, $have_patches);

	# Initialize global variables
	$makevar = {};
	$varuse = {};
	$seen_bsd_prefs_mk = false;
	$seen_Makefile_common = false;

	# we need to handle the Makefile first to get some variables
	if (!load_package_Makefile("${current_dir}/Makefile", \$whole, \$lines)) {
		log_error("${current_dir}/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	my @files = <${current_dir}/*>;
	if ($pkgdir ne ".") {
		push(@files, <${current_dir}/${pkgdir}/*>);
	}
	if ($opt_check_extra) {
		push(@files, <${current_dir}/${filesdir}/*>);
	}
	push(@files, <${current_dir}/${patchdir}/*>);
	if ($distinfo_file !~ qr"^(?:\./)?distinfo$") {
		push(@files, "${current_dir}/${distinfo_file}");
	}
	$have_distinfo = false;
	$have_patches = false;

	# Determine the used variables before checking any of the
	# Makefile fragments.
	foreach my $fname (@files) {
		if ($fname =~ qr"^((?:.*/)?Makefile\..*|.*\.mk)$"
		&& (defined(my $lines = load_lines($fname, true)))) {
			determine_used_variables($lines);
		}
	}

	foreach my $fname (@files) {
		if ($fname eq "${current_dir}/Makefile") {
			$opt_check_Makefile and checkfile_package_Makefile($fname, $whole, $lines);
		} else {
			checkfile($fname);
		}
		if ($fname =~ qr"/patches/patch-[A-Za-z0-9]*$") {
			$have_patches = true;
		} elsif ($fname =~ qr"/distinfo$") {
			$have_distinfo = true;
		}
	}

	if ($opt_check_distinfo && $opt_check_patches) {
		if ($have_patches && ! $have_distinfo) {
			log_warning("${current_dir}/$distinfo_file", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makepatchsum'.");
		}
	}

	if (!is_emptydir("${current_dir}/scripts")) {
		log_warning("${current_dir}/scripts", NO_LINE_NUMBER, "This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.");
	}
}

#
# Selecting the proper checking procedures for a directory entry.
#

sub checkitem($) {
	my ($item) = @_;
	my ($st, $is_dir, $is_reg);

	if (!($st = lstat($item))) {
		log_error($item, NO_LINE_NUMBER, "Does not exist.");
		return;
	}

	$is_dir = S_ISDIR($st->mode);
	$is_reg = S_ISREG($st->mode);
	if (!$is_reg && !$is_dir) {
		log_error($item, NO_LINE_NUMBER, "Must be a file or directory.");
		return;
	}

	# Initialize global variables.
	$pkgdir			= undef;
	$filesdir		= "files";
	$patchdir		= "patches";
	$distinfo_file		= "distinfo";
	$makevar		= undef;
	$varuse			= undef;
	$seen_Makefile_common	= undef;
	$effective_pkgname	= undef;
	$effective_pkgname_line	= undef;
	$hack_php_patches	= false;
	$seen_bsd_prefs_mk	= undef;

	$current_dir = $is_dir ? $item : dirname($item);
	my $abs_current_dir = Cwd::abs_path($current_dir);
	$is_wip = !$opt_import && ($abs_current_dir =~ qr"/wip(?:/|$)");
	$is_internal = ($abs_current_dir =~ qr"/mk(?:/|$)");

	$pkgsrcdir = undef;
	foreach my $d (".", "..", "../..", "../../..") {
		if (-f "${current_dir}/${d}/mk/bsd.pkg.mk") {
			$pkgsrcdir = $d;
		}
	}
	if (!defined($pkgsrcdir)) {
		log_error($current_dir, NO_LINE_NUMBER, "This is not inside a pkgsrc tree.");
		return;
	}

	check_pkglint_version();	# (needs $pkgsrcdir)

	if ($is_reg) {
		checkfile($item);

	} elsif ($pkgsrcdir eq "../..") {
		checkdir_package();

	} elsif ($pkgsrcdir eq "..") {
		checkdir_category();

	} elsif ($pkgsrcdir eq ".") {
		checkdir_root();

	} else {
		log_error($item, NO_LINE_NUMBER, "Don't know how to check this directory.");
	}
}

#
# The main program
#

sub main() {

	$| = true;
	parse_command_line();

	@todo_items = (@ARGV != 0) ? @ARGV : (".");
	while (@todo_items != 0) {
		checkitem(shift(@todo_items));
	}

	PkgLint::Logging::print_summary_and_exit($opt_quiet);
}

main();
