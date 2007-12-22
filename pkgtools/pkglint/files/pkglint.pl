#! @PERL@
# $NetBSD: pkglint.pl,v 1.742 2007/12/22 22:27:17 rillig Exp $
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
		false true dont_know doesnt_matter
		min max
		array_to_hash normalize_pathname print_table
	);
}

use enum qw(false true dont_know doesnt_matter);

sub assert($$) {
	my ($cond, $msg) = @_;
	my (@callers, $n);

	if (!$cond) {
		print STDERR ("FATAL: Assertion failed: ${msg}.\n");

		for ($n = 0; my @info = caller($n); $n++) {
			push(@callers, [$info[2], $info[3]]);
		}

		for (my $i = $#callers; $i >= 0; $i--) {
			my $info = $callers[$i];
			printf STDERR ("  line %4d called %s\n", $info->[0], $info->[1]);
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

sub normalize_pathname($) {
	my ($fname) = @_;

	# strip "." path components
	$fname =~ s,^(?:\./)+,,;
	$fname =~ s,/(?:\./)+,/,g;
	$fname =~ s,/+,/,g;

	# strip intermediate "../.." path components
	while ($fname =~ s,/[^.][^/]*/[^.][^/]*/\.\./\.\./,/,) {
	}

	return $fname;
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
#   log_debug($fname, $lineno, sprintf("invalid character (0x%02x).", $c));
#==========================================================================

use strict;
use warnings;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		NO_FILE NO_LINE_NUMBER NO_LINES
		log_fatal log_error log_warning log_note log_debug
		explain_error explain_warning explain_info
		print_summary_and_exit
		set_explain set_gcc_output_format
		get_show_source_flag set_show_source_flag
		get_klickibunti_flag set_klickibunti_flag
	);
	import PkgLint::Util qw(
		false true
		normalize_pathname
	);
}

use constant NO_FILE		=> undef;
use constant NO_LINE_NUMBER	=> undef;
use constant NO_LINES		=> undef;

use enum qw(:LL_ FATAL ERROR WARNING NOTE DEBUG);

use constant traditional_type	=> ["FATAL", "ERROR", "WARN", "NOTE", "DEBUG"];
use constant gcc_type		=> ["fatal", "error", "warning", "note", "debug"];

my $errors		= 0;
my $warnings		= 0;
my $gcc_output_format	= false;
my $klickibunti_flag	= false;
my $explain_flag	= false;
my $show_source_flag	= false;

sub strxvis($) {
	my ($s) = @_;

	$s =~ s/([^\x09\x20-\x7e])/"\\x" . unpack("H*", $1)/eg;
	return $s;
}

sub log_message { # no prototype due to Perl weirdness
	my ($level, $fname, $lineno, $message) = @_;
	my ($text, $sep);

	if (defined($fname)) {
		$fname = normalize_pathname($fname);
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
	}

	if ($level == LL_FATAL) {
		print STDERR ("${text}\n");
	} else {
		print STDOUT ("${text}\n");
	}
}

sub log_fatal($$$)		{ log_message(LL_FATAL, @_); exit(1); }
sub log_error($$$)		{ log_message(LL_ERROR, @_); $errors++; }
sub log_warning($$$)		{ log_message(LL_WARNING, @_); $warnings++; }
sub log_note($$$)		{ log_message(LL_NOTE, @_); }
sub log_debug($$$)		{ log_message(LL_DEBUG, @_); }

sub explain { # no prototype due to Perl weirdness
	my ($loglevel, $fname, $lines, @texts) = @_;
	my $out = ($loglevel == LL_FATAL) ? *STDERR : *STDOUT;

	if ($explain_flag) {
		foreach my $text ("", @texts, "") {
			print $out ("\t${text}\n");
		}
	}
}
sub explain_error($$@)		{ explain(LL_ERROR, @_); }
sub explain_warning($$@)	{ explain(LL_WARNING, @_); }
sub explain_note($$@)		{ explain(LL_NOTE, @_); }

sub print_summary_and_exit($) {
	my ($quiet) = @_;

	if (!$quiet) {
		if ($errors != 0 || $warnings != 0) {
			print("$errors errors and $warnings warnings found.\n");
		} else {
			print "looks fine.\n";
		}
	}
	exit($errors != 0);
}

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

use enum qw(NAME LINES);

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

use enum qw(LINENO COLNO);

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

use enum qw(STRING STARTS ENDS N);

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

use enum qw(STRING STARTS ENDS);

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
#
# A line can have some "extra" fields that allow the results of parsing to
# be saved under a name.
#==========================================================================
package PkgLint::Line;

BEGIN {
	import PkgLint::Util qw(
		false true
		assert
	);
}

use enum qw(FNAME LINES TEXT PHYSLINES CHANGED BEFORE AFTER EXTRA);

sub new($$$$) {
	my ($class, $fname, $lines, $text, $physlines) = @_;
	my ($self) = ([$fname, $lines, $text, $physlines, false, [], [], {}]);
	bless($self, $class);
	return $self;
}

sub fname($)		{ return shift(@_)->[FNAME]; }
sub lines($)		{ return shift(@_)->[LINES]; }
sub text($)		{ return shift(@_)->[TEXT]; }
# Note: physlines is _not_ a usual getter method.
sub is_changed($)	{ return shift(@_)->[CHANGED]; }

# querying, getting and setting the extra values.
sub has($$) {
	my ($self, $name) = @_;
	return exists($self->[EXTRA]->{$name});
}
sub get($$) {
	my ($self, $name) = @_;
	assert(exists($self->[EXTRA]->{$name}), "Field ${name} does not exist.");
	return $self->[EXTRA]->{$name};
}
sub set($$$) {
	my ($self, $name, $value) = @_;
	assert(!exists($self->[EXTRA]->{$name}), "Field ${name} already exists.");

	# Make sure that the line does not become a cyclic data structure.
	my $type = ref($value);
	if ($type eq "") {
		# ok
	} elsif ($type eq "ARRAY") {
		foreach my $element (@{$value}) {
			my $element_type = ref($element);
			assert($element_type eq "" || $element_type eq "PkgLint::SimpleMatch",
				"Invalid array data type: name=${name}, type=${element_type}.");
		}
	} else {
		assert(false, "Invalid data: name=${name}, value=${value}.");
	}

	$self->[EXTRA]->{$name} = $value;
}

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
sub log_debug($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDOUT);
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

use enum qw(LINE PARTS MARKUPS);

# The structure fields of a Part of a String
use enum qw(:P_ LINENO STARTCOL ENDCOL);

# The structure fields of a MarkupPoint of a String
use enum qw(:MP_ LINENO COLNO TEXT);

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
	my ($physlines, $seen_newline, $loglines);

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
	my ($physlines, $seen_newline, $strings);

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
#==========================================================================
# A Type in pkglint is a combination of a data type and a permission
# specification. Further details can be found in the chapter ``The pkglint
# type system'' of the pkglint book.
#==========================================================================

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
		GUESSED NOT_GUESSED
	);
}

use enum qw(KIND_OF_LIST BASIC_TYPE ACLS IS_GUESSED);
use enum qw(:LK_ NONE INTERNAL EXTERNAL);
use enum qw(:ACLE_ SUBJECT_RE PERMS);
use enum qw(NOT_GUESSED GUESSED);

sub new($$$) {
	my ($class, $kind_of_list, $basic_type, $acls, $guessed) = @_;
	my ($self) = ([$kind_of_list, $basic_type, $acls, $guessed]);
	bless($self, $class);
	return $self;
}

sub kind_of_list($)	{ return shift(@_)->[KIND_OF_LIST]; }
sub basic_type($)	{ return shift(@_)->[BASIC_TYPE]; }
# no getter method for acls
sub is_guessed($)	{ return shift(@_)->[IS_GUESSED]; }

sub perms($$) {
	my ($self, $fname) = @_;
	my ($perms);

	foreach my $acl_entry (@{$self->[ACLS]}) {
		if ($fname =~ $acl_entry->[ACLE_SUBJECT_RE]) {
			return $acl_entry->[ACLE_PERMS];
		}
	}
	return undef;
}

# Returns the union of all possible permissions. This can be used to
# check whether a variable may be defined or used at all, or if it is
# read-only.
sub perms_union($) {
	my ($self) = @_;
	my ($perms);

	$perms = "";
	foreach my $acl_entry(@{$self->[ACLS]}) {
		$perms .= $acl_entry->[ACLE_PERMS];
	}
	return $perms;
}

# Returns whether the type is considered an external list. All external
# lists are, of course, as well as some other data types that are not
# defined as lists to make the implementation of checkline_mk_vartype
# easier.
sub is_practically_a_list($) {
	my ($self) = @_;

	return ($self->kind_of_list == LK_EXTERNAL) ? true
	    : ($self->kind_of_list == LK_INTERNAL) ? false
	    : ($self->basic_type eq "BuildlinkPackages") ? true
	    : ($self->basic_type eq "SedCommands") ? true
	    : ($self->basic_type eq "ShellCommand") ? true
	    : false;
}

# Returns whether variables of this type may be extended using the "+="
# operator.
sub may_use_plus_eq($) {
	my ($self) = @_;

	return ($self->kind_of_list != LK_NONE) ? true
	    : ($self->basic_type eq "AwkCommand") ? true
	    : ($self->basic_type eq "BuildlinkPackages") ? true
	    : ($self->basic_type eq "SedCommands") ? true
	    : false;
}

sub to_string($) {
	my ($self) = @_;

	return (["", "InternalList of ", "List of "]->[$self->kind_of_list]) . $self->basic_type;
}

#== End of PkgLint::Type ==================================================

package PkgLint::VarUseContext;
#==========================================================================
# This class represents the various contexts in which make(1) variables can
# appear in pkgsrc. Further details can be found in the chapter ``The
# pkglint type system'' of the pkglint book.
#==========================================================================

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
		VUC_TIME_UNKNOWN VUC_TIME_LOAD VUC_TIME_RUN
		VUC_TYPE_UNKNOWN
		VUC_SHELLWORD_UNKNOWN VUC_SHELLWORD_PLAIN VUC_SHELLWORD_DQUOT
		  VUC_SHELLWORD_SQUOT VUC_SHELLWORD_BACKT VUC_SHELLWORD_FOR
		VUC_EXTENT_UNKNOWN VUC_EXTENT_FULL VUC_EXTENT_WORD
		  VUC_EXTENT_WORD_PART
	);
}

use enum qw(TIME TYPE SHELLWORD EXTENT);
use enum qw(:VUC_TIME_ UNKNOWN LOAD RUN);
use constant VUC_TYPE_UNKNOWN => undef;
use enum qw(:VUC_SHELLWORD_ UNKNOWN PLAIN DQUOT SQUOT BACKT FOR);
use enum qw(:VUC_EXTENT_ UNKNOWN FULL WORD WORD_PART);

my $pool = {};

sub new($$$$$) {
	my ($class, $time, $type, $shellword, $extent) = @_;
	my ($self) = ([$time, $type, $shellword, $extent]);
	bless($self, $class);
	return $self;
}
sub new_from_pool($$$$$) {
	my ($class, $time, $type, $shellword, $extent) = @_;
	my $key = "${time}-${type}-${shellword}-${extent}";

	if (!exists($pool->{$key})) {
		$pool->{$key} = $class->new($time, $type, $shellword, $extent);
	}
	return $pool->{$key};
}

sub time($)		{ return shift(@_)->[TIME]; }
sub type($)		{ return shift(@_)->[TYPE]; }
sub shellword($)	{ return shift(@_)->[SHELLWORD]; }
sub extent($)		{ return shift(@_)->[EXTENT]; }

sub to_string($) {
	my ($self) = @_;

	return sprintf("(%s %s %s %s)",
	    ["unknown-time", "load-time", "run-time"]->[$self->time],
	    (defined($self->type) ? $self->type->to_string() : "no-type"),
	    ["none", "plain", "squot", "dquot", "backt", "for"]->[$self->shellword],
	    ["unknown", "full", "word", "word-part"]->[$self->extent]);
}

#== End of PkgLint::VarUseContext =========================================

package PkgLint::SubstContext;
#==========================================================================
# This class records the state of a block of variable assignments that make
# up a SUBST class. As these variable assignments are not easy to get right
# unless you do it every day, and the possibility of typos is high, pkglint
# provides additional checks for them.
#==========================================================================

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		log_warning
	);
}

use enum qw(:SUBST_ ID CLASS STAGE MESSAGE FILES SED VARS FILTER_CMD);

sub new($) {
	my ($class) = @_;
	my ($self) = ([undef, undef, undef, undef, [], [], [], undef]);
	bless($self, $class);
	return $self;
}

sub subst_class($)		{ return shift(@_)->[SUBST_CLASS]; }
sub subst_stage($)		{ return shift(@_)->[SUBST_STAGE]; }
sub subst_message($)		{ return shift(@_)->[SUBST_MESSAGE]; }
sub subst_files($)		{ return shift(@_)->[SUBST_FILES]; }
sub subst_sed($)		{ return shift(@_)->[SUBST_SED]; }
sub subst_vars($)		{ return shift(@_)->[SUBST_VARS]; }
sub subst_filter_cmd($)		{ return shift(@_)->[SUBST_FILTER_CMD]; }
sub subst_id($)			{ return shift(@_)->[SUBST_ID]; }

sub init($) {
	my ($self) = @_;

	$self->[SUBST_ID] = undef;
	$self->[SUBST_CLASS] = undef;
	$self->[SUBST_STAGE] = undef;
	$self->[SUBST_MESSAGE] = undef;
	$self->[SUBST_FILES] = [];
	$self->[SUBST_SED] = [];
	$self->[SUBST_VARS] = [];
	$self->[SUBST_FILTER_CMD] = undef;
}

sub check_end($$) {
	my ($self, $line) = @_;

	return unless defined($self->subst_id);

	if (!defined($self->subst_class)) {
		$line->log_warning("Incomplete SUBST block: SUBST_CLASSES missing.");
	}
	if (!defined($self->subst_stage)) {
		$line->log_warning("Incomplete SUBST block: SUBST_STAGE missing.");
	}
	if (@{$self->subst_files} == 0) {
		$line->log_warning("Incomplete SUBST block: SUBST_FILES missing.");
	}
	if (@{$self->subst_sed} == 0 && @{$self->subst_vars} == 0 && !defined($self->subst_filter_cmd)) {
		$line->log_warning("Incomplete SUBST block: SUBST_SED or SUBST_VARS missing.");
	}
	$self->init();
}

sub is_complete($) {
	my ($self) = @_;

	return false unless defined($self->subst_id);
	return false unless defined($self->subst_class);
	return false unless defined($self->subst_files);
	return false if @{$self->subst_sed} == 0 && @{$self->subst_vars} == 0;
	return true;
}

sub check_varassign($$$$$) {
	my ($self, $line, $varname, $op, $value) = @_;
	my ($varbase, $varparam, $id);

	if ($varname eq "SUBST_CLASSES") {

		if ($value =~ qr"^(\S+)\s") {
			$line->log_warning("Please add only one class at a time to SUBST_CLASSES.");
			$self->[SUBST_CLASS] = $1;
			$self->[SUBST_ID] = $1;

		} else {
			if (defined($self->subst_class)) {
				$line->log_warning("SUBST_CLASSES should only appear once in a SUBST block.");
			}
			$self->[SUBST_CLASS] = $value;
			$self->[SUBST_ID] = $value;
		}
		return;
	}

	$id = $self->subst_id;

	if ($varname =~ qr"^(SUBST_(?:STAGE|MESSAGE|FILES|SED|VARS|FILTER_CMD))\.([\-\w_]+)$") {
		($varbase, $varparam) = ($1, $2);

		if (!defined($id)) {
			$line->log_note("SUBST_CLASSES should precede the definition of ${varbase}.${varparam}.");

			$id = $self->[SUBST_ID] = $varparam;
		}
	} else {
		if (defined($id)) {
			$line->log_warning("Foreign variable in SUBST block.");
		}
		return;
	}

	if ($varparam ne $id) {

		# XXX: This code sometimes produces weird warnings. See
		# meta-pkgs/xorg/Makefile.common 1.41 for an example.
		if ($self->is_complete()) {
			$self->check_end($line);

			# The following assignment prevents an additional warning,
			# but from a technically viewpoint, it is incorrect.
			$self->[SUBST_CLASS] = $varparam;
			$self->[SUBST_ID] = $varparam;
			$id = $varparam;
		} else {
			$line->log_warning("Variable parameter \"${varparam}\" does not match SUBST class \"${id}\".");
		}
	}

	if ($varbase eq "SUBST_STAGE") {
		if (defined($self->subst_stage)) {
			$line->log_warning("Duplicate definition of SUBST_STAGE.${id}.");
		} else {
			$self->[SUBST_STAGE] = $value;
		}

	} elsif ($varbase eq "SUBST_MESSAGE") {
		if (defined($self->subst_message)) {
			$line->log_warning("Duplicate definition of SUBST_MESSAGE.${id}.");
		} else {
			$self->[SUBST_MESSAGE] = $value;
		}

	} elsif ($varbase eq "SUBST_FILES") {
		if (@{$self->subst_files} > 0) {
			if ($op ne "+=") {
				$line->log_warning("All but the first SUBST_FILES line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_files}, $value);

	} elsif ($varbase eq "SUBST_SED") {
		if (@{$self->subst_sed} > 0) {
			if ($op ne "+=") {
				$line->log_warning("All but the first SUBST_SED line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_sed}, $value);

	} elsif ($varbase eq "SUBST_FILTER_CMD") {
		if (defined($self->subst_filter_cmd)) {
			$line->log_warning("Duplicate definition of SUBST_FILTER_CMD.${id}.");
		} else {
			$self->[SUBST_FILTER_CMD] = $value;
		}

	} elsif ($varbase eq "SUBST_VARS") {
		if (@{$self->subst_vars} > 0) {
			if ($op ne "+=") {
				$line->log_warning("All but the first SUBST_VARS line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_vars}, $value);

	} else {
		$line->log_warning("Foreign variable in SUBST block.");
	}
}

sub to_string($) {
	my ($self) = @_;

	return sprintf("SubstContext(%s %s %s %s %s %s)",
	    (defined($self->subst_class) ? $self->subst_class : "(undef)"),
	    (defined($self->subst_stage) ? $self->subst_stage : "(undef)"),
	    (defined($self->subst_message) ? $self->subst_message : "(undef)"),
	    scalar(@{$self->subst_files}),
	    scalar(@{$self->subst_sed}),
	    (defined($self->subst_id) ? $self->subst_id : "(undef)"));
}
#== End of PkgLint::SubstContext ==========================================

package CVS_Entry;
#==========================================================================
# A CVS_Entry represents one line from a CVS/Entries file.
#==========================================================================

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		log_warning
	);
}

use enum qw(FNAME REVISION MTIME TAG);

sub new($$$$$) {
	my ($class, $fname, $revision, $date, $tag) = @_;
	my $self = [ $fname, $revision, $date, $tag ];
	bless($self, $class);
	return $self;
}
sub fname($)			{ return shift()->[FNAME]; }
sub revision($)			{ return shift()->[REVISION]; }
sub mtime($)			{ return shift()->[MTIME]; }
sub tag($)			{ return shift()->[TAG]; }
#== End of CVS_Entry ======================================================


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
		array_to_hash assert
		false true dont_know doesnt_matter
		normalize_pathname
	);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER NO_LINES
		log_fatal log_error log_warning log_note log_debug
		explain_error explain_warning explain_info
	);
	import PkgLint::FileUtil qw(
		load_file load_lines
		save_autofix_changes
	);
	import PkgLint::Type qw(
		LK_NONE LK_INTERNAL LK_EXTERNAL
		GUESSED NOT_GUESSED
	);
	import PkgLint::VarUseContext qw(
		VUC_TIME_UNKNOWN VUC_TIME_LOAD VUC_TIME_RUN
		VUC_TYPE_UNKNOWN
		VUC_SHELLWORD_UNKNOWN VUC_SHELLWORD_PLAIN VUC_SHELLWORD_DQUOT
		  VUC_SHELLWORD_SQUOT VUC_SHELLWORD_BACKT VUC_SHELLWORD_FOR
		VUC_EXTENT_UNKNOWN VUC_EXTENT_FULL VUC_EXTENT_WORD
		  VUC_EXTENT_WORD_PART
	);
}

#
# Buildtime configuration
#

use constant conf_distver	=> '@DISTVER@';
use constant conf_make		=> '@MAKE@';
use constant conf_datadir	=> '@DATADIR@';

#
# Global variables that can be modified via command line options.
#

# The pkgsrc directory, relative to the current working directory of
# pkglint.
my $cwd_pkgsrcdir	= undef;

# The pkgsrc directory, relative to the directory that is currently
# checked.
my $cur_pkgsrcdir	= undef;

#
# Command Line Options
#

my $opt_check_ALTERNATIVES = true;
my $opt_check_bl3	= true;
my $opt_check_DESCR	= true;
my $opt_check_distinfo	= true;
my $opt_check_extra	= false;
my $opt_check_global	= false;
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
	"global"	=> [\$opt_check_global, "inter-package checks"],
	"INSTALL"	=> [\$opt_check_INSTALL, "check INSTALL and DEINSTALL scripts"],
	"Makefile"	=> [\$opt_check_Makefile, "check Makefiles"],
	"MESSAGE"	=> [\$opt_check_MESSAGE, "check MESSAGE files"],
	"mk"		=> [\$opt_check_mk, "check other .mk files"],
	"patches"	=> [\$opt_check_patches, "check patches"],
	"PLIST"		=> [\$opt_check_PLIST, "check PLIST files"],
);

my $opt_debug_include	= false;
my $opt_debug_misc	= false;
my $opt_debug_patches	= false;
my $opt_debug_quoting	= false;
my $opt_debug_shell	= false;
my $opt_debug_tools	= false;
my $opt_debug_trace	= false;
my $opt_debug_unchecked	= false;
my $opt_debug_unused	= false;
my $opt_debug_vartypes	= false;
my $opt_debug_varuse	= false;
my (%debug) = (
	"include"	=> [\$opt_debug_include, "included files"],
	"misc"		=> [\$opt_debug_misc, "all things that didn't fit elsewhere"],
	"patches"	=> [\$opt_debug_patches, "the states of the patch parser"],
	"quoting"	=> [\$opt_debug_quoting, "additional information about quoting"],
	"shell"		=> [\$opt_debug_shell, "the parsers for shell words and shell commands"],
	"tools"		=> [\$opt_debug_tools, "the tools framework"],
	"trace"		=> [\$opt_debug_trace, "follow subroutine calls"],
	"unchecked"	=> [\$opt_debug_unchecked, "show the current limitations of pkglint"],
	"unused"	=> [\$opt_debug_unused, "unused variables"],
	"vartypes"	=> [\$opt_debug_vartypes, "additional type information"],
	"varuse"	=> [\$opt_debug_varuse, "contexts where variables are used"],
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
	[ "-D{debug,...}", "Enable or disable debugging categories",
	  "debugging|D=s",
	  sub ($$) {
		my ($opt, $val) = @_;
		parse_multioption($val, \%debug);
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
	# Note: This is intentionally undocumented.
	[ "--pkgsrcdir", "Set the root directory of pkgsrc explicitly.",
	  "pkgsrcdir=s", \$cwd_pkgsrcdir ],
	[ "-q|--quiet", "Don't print a summary line when finishing",
	  "quiet|q", \$opt_quiet ],
	[ "-r|--recursive", "Recursive---check subdirectories, too",
	  "recursive|r", \$opt_recursive ],
	[ "-s|--source", "Show the source lines together with diagnostics",
	  "source|s",
	  sub {
		PkgLint::Logging::set_show_source_flag();
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

use constant regex_dependency_gt => qr"^((?:\$\{[\w_]+\}|[\w_]|-[^\d])+)>=(.*)$";
use constant regex_dependency_wildcard
				=> qr"^((?:\$\{[\w_]+\}|[\w_]|-[^\d\[])+)-(?:\[0-9\]|\d.*)$";
use constant regex_gnu_configure_volatile_vars
				=> qr"^(?:.*_)?(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$";
use constant regex_mk_comment	=> qr"^ *\s*#(.*)$";
use constant regex_mk_cond	=> qr"^\.(\s*)(if|ifdef|ifndef|else|elif|endif|for|endfor|undef)(?:\s+([^\s#][^#]*?))?\s*(?:#.*)?$";
use constant regex_mk_dependency=> qr"^([^\s:]+(?:\s*[^\s:]+)*):\s*([^#]*?)(?:\s*#.*)?$";
use constant regex_mk_include	=> qr"^\.\s*s?include\s+\"([^\"]+)\"\s*(?:#.*)?$";
use constant regex_mk_sysinclude=> qr"^\.\s*s?include\s+<([^>]+)>\s*(?:#.*)?$";
use constant regex_mk_shellvaruse => qr"(?:^|[^\$])\$\$\{?(\w+)\}?"; # XXX: not perfect
use constant regex_pkgname	=> qr"^((?:[\w.+]|-[^\d])+)-(\d(?:\w|\.\d)*)$";
use constant regex_mk_shellcmd	=> qr"^\t(.*)$";
use constant regex_rcs_conflict	=> qr"^(<<<<<<<|=======|>>>>>>>)";
use constant regex_unresolved	=> qr"\$\{";
use constant regex_validchars	=> qr"[\011\040-\176]";
# Note: the following regular expression looks more complicated than
# necessary to avoid a stack overflow in the Perl interpreter.
# The leading white-space may only consist of \040 characters, otherwise
# the order of regex_varassign and regex_mk_shellcmd becomes important.
use constant regex_varassign	=> qr"^ *([-*+A-Z_a-z0-9.\${}\[]+?)\s*(=|\?=|\+=|:=|!=)\s*((?:[^\\#\s]+|\s+?|(?:\\#)+|\\)*?)(?:\s*(#.*))?$";
use constant regex_sh_varassign	=> qr"^([A-Z_a-z][0-9A-Z_a-z]*)=";

# The following "constants" are often used in contexts where
# interpolation comes handy, so they are variables. Nevertheless they
# are not modified.

# This regular expression cannot parse all kinds of shell programs, but
# it will catch almost all shell programs that are portable enough to be
# used in pkgsrc.
my $regex_shellword		=  qr"\s*(
	\#.*				# shell comment
	|
	(?:	'[^']*'			# single quoted string
	|	\"(?:\\.|[^\"\\])*\"	# double quoted string
	|	\`[^\`]*\`		# backticks string
	|	\\\$\$			# an escaped dollar sign
	|	\\[^\$]			# other escaped characters
	|	\$[\w_]			# one-character make(1) variable
	|	\$\{[^{}]+\}		# make(1) variable
	|	\$\([^()]+\)		# make(1) variable, $(...)
	|	\$[/\@<^]		# special make(1) variables
	|	\$\$[0-9A-Z_a-z]+	# shell variable
	|	\$\$[\#?@]		# special shell variables
	|	\$\$\{[0-9A-Z_a-z]+\}	# shell variable in braces
	|	\$\$\(			# POSIX-style backticks replacement
	|	[^\(\)'\"\\\s;&\|<>\`\$] # non-special character
	|	\$\{[^\s\"'`]+		# HACK: nested make(1) variables
	)+ | ;;? | &&? | \|\|? | \( | \) | >& | <<? | >>? | \#.*)"sx;
my $regex_varname		= qr"(?:[-*+.0-9A-Z_a-z{}\[]+|\$\{[\w_]+\})+";
my $regex_pkgbase		= qr"(?:[+.0-9A-Z_a-z]|-[A-Z_a-z])+";
my $regex_pkgversion		= qr"\d(?:\w|\.\d)*";

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

#
# Variables for inter-package checks.
#

my $ipc_distinfo;		# Maps "$alg:$fname" => "checksum".

# Context of the package that is currently checked.
my $pkgdir;			# PKGDIR from the package Makefile
my $filesdir;			# FILESDIR from the package Makefile
my $patchdir;			# PATCHDIR from the package Makefile
my $distinfo_file;		# DISTINFO_FILE from the package Makefile
my $effective_pkgname;		# PKGNAME or DISTNAME from the package Makefile
my $effective_pkgbase;		# The effective PKGNAME without the version
my $effective_pkgversion;	# The version part of the effective PKGNAME
my $effective_pkgname_line;	# The origin of the three effective_* values
my $seen_bsd_prefs_mk;		# Has bsd.prefs.mk already been included?

my $pkgctx_vardef;		# { varname => line }
my $pkgctx_varuse;		# { varname => line }
my $pkgctx_bl3;			# buildlink3.mk name => line of inclusion
my $pkgctx_plist_subst_cond;	# { varname => 1 } list of all variables
				# that are used as conditionals (@comment
				# or nothing) in PLISTs.
my $seen_Makefile_common;	# Does the package have any .includes?

# Context of the Makefile that is currently checked.
my $mkctx_for_variables;	# The variables currently used in .for loops
my $mkctx_indentations;		# Indentation depth of preprocessing directives
my $mkctx_target;		# Current make(1) target
my $mkctx_vardef;		# { varname => line } for all variables that
				# are defined in the current file
my $mkctx_varuse;		# { varname => line } for all variables
				# that are used in the current file
my $mkctx_build_defs;		# Set of variables that are registered in
				# BUILD_DEFS, to assure that all user-defined
				# variables are added to it.
my $mkctx_tools;		# Set of tools that are declared to be used.

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

	my $categories = [
		# options, leading text, 
		[ \%checks, "checks", "check" ],
		[ \%debug, "debugging options", "debug" ],
		[ \%warnings, "warnings", "warning" ],
	];
	foreach my $category (@{$categories}) {
		my ($options, $leading, $name) = (@{$category});
		my $table = [
			["  ", "all", "", "enable all ".$category->[1]],
			["  ", "none", "", "disable all ".$category->[1]],
		];

		foreach my $opt (sort keys %{$options}) {
			push(@{$table}, [ "  ", $opt,
				(${$options->{$opt}->[0]} ? "(enabled)" : "(disabled)"),
				$options->{$opt}->[1]]);
		}

		print $out ("${leading}: (use \"${name}\" to enable, \"no-${name}\" to disable)\n");
		PkgLint::Util::print_table($out, $table);
		print $out ("\n");
	}

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

# The symbol table for ACL definitions maps ACL names to ACLs.
my $acl_definitions = {};

sub parse_acls($$) {
	my ($line, $acltext) = @_;
	my ($acls);

	use constant ACL_shortcuts => {
		"b" => qr"(?:^|/)buildlink3\.mk$",
		"c" => qr"(?:^|/)Makefile\.common$",
		"h" => qr"(?:^|/)hacks\.mk$",
		"m" => qr"(?:^|/)Makefile$",
		"o" => qr"(?:^|/)options\.mk$",
	};

	my $regex_acl_entry = qr"^(?:
		  \$([\w_]+)			# $acl_name
		| ([\w.*]+|_):([adpsu]*)	# file*mask:perms
		) (?:\,\s*|$)"x;

	if (!defined($acltext)) {
		return undef;
	}

	$acls = [];
	while ($acltext =~ s,$regex_acl_entry,,) {
		my ($acldef, $subject, $perms) = ($1, $2, $3);

		if (defined($acldef)) {
			if (!exists($acl_definitions->{$acldef})) {
				$line->log_fatal("ACL definition ${acldef} not found.");
			} else {
				push(@{$acls}, @{$acl_definitions->{$acldef}});
			}

		} else {
			# Transform $subject to a regular expression.
			$subject =~ s/\./[.]/g;
			$subject =~ s/\*/.*/g;

			push(@{$acls}, [exists(ACL_shortcuts->{$subject}) ? ACL_shortcuts->{$subject} : qr"(?:^|/)${subject}$", $perms]);
		}
	}
	if ($acltext ne "") {
		$line->log_fatal("Invalid ACL: ${acltext}.");
	}

	return $acls;
}

my $get_vartypes_map_result = undef;
sub get_vartypes_map() {
	my ($fname, $vartypes);

	if (defined($get_vartypes_map_result)) {
		return $get_vartypes_map_result;
	}

	use constant re_acl_def => qr"^
		acl \s+
		(\w+) \s+				# ACL name
		= \s+
		\[ ([^\]]*) \]				# ACL value
		(?:\s*\#.*)?				# optional comment
		$"x;

	use constant re_vartypedef => qr"^
		([\w\d_.]+?)				# variable name
		(\*|\.\*|) \s+				# parameterized?
		(?:(InternalList|List) \s+ of \s+)?	# kind of list
		(?:([\w\d_]+) | \{\s*([\w\d_+,\-.\s]+?)\s*\}) # basic type
		(?:\s+ \[ ([^\]]*) \])?			# optional ACL
		(?:\s*\#.*)?				# optional comment
		$"x;

	$fname = conf_datadir."/makevars.map";
	$vartypes = {};

	if ((my $lines = load_lines($fname, true))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^(?:#.*|\s*)$") {
				# ignore empty and comment lines

			} elsif ($line->text =~ re_acl_def) {
				my ($aclname, $aclvalue) = ($1, $2);

				$acl_definitions->{$aclname} = parse_acls($line, $aclvalue);

			} elsif ($line->text =~ re_vartypedef) {
				my ($varname, $par, $kind_of_list_text, $typename, $enums, $acltext) = ($1, $2, $3, $4, $5, $6);
				my $kind_of_list = !defined($kind_of_list_text) ? LK_NONE
				    : ($kind_of_list_text eq "List") ? LK_EXTERNAL
				    : LK_INTERNAL;

				my $basic_type = defined($enums)
				    ? array_to_hash(split(qr"\s+", $enums))
				    : $typename;
				my $type = PkgLint::Type->new($kind_of_list, $basic_type, parse_acls($line, $acltext), NOT_GUESSED);
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
	$fname = "${cwd_pkgsrcdir}/mk/defaults/mk.conf";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^#?([\w_]+)\?=") {
				my ($varname) = ($1);
				$opt_debug_misc and $line->log_debug("Found user-definable variable ${varname}.");
				$vartypes->{$varname} = "Userdefined"; # FIXME: type error
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
	my ($fname) = ("${cwd_pkgsrcdir}/mk/fetch/sites.mk");
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
			$line->log_fatal("Unknown line type.");
		}
	}

	# Explicitly allowed, although not defined in mk/fetch/sites.mk.
	$names->{"MASTER_SITE_SUSE_UPD"} = true;
	$names->{"MASTER_SITE_LOCAL"} = true;

	$opt_debug_misc and log_debug($fname, NO_LINES, "Loaded " . scalar(keys(%{$url2name})) . " MASTER_SITE_* definitions.");
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

	my ($fname) = ("${cwd_pkgsrcdir}/mk/defaults/options.description");
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

my $load_tool_names_system_build_defs = undef;		# XXX: misplaced, but works
my $load_tool_names_tools = undef;
my $load_tool_names_vartools = undef;
my $load_tool_names_varname_to_toolname = undef;
my $load_tool_names_predefined_tools = undef;
sub load_tool_names() {
	my ($tools, $vartools, $predefined_tools, $varname_to_toolname, @tool_files);
	my ($system_build_defs);

	#
	# Get the list of files that define the tools from bsd.tools.mk.
	#

	@tool_files = ("defaults.mk");
	{
		my $fname = "${cwd_pkgsrcdir}/mk/tools/bsd.tools.mk";
		my $lines = load_lines($fname, true);
		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_mk_include) {
				my ($includefile) = ($1);
				if ($includefile =~ qr"^\$\{PKGSRCDIR\}/mk/tools/(.*)$") {
					push(@tool_files, $1);
				}
			}
		}
	}
	assert(scalar(@tool_files) > 1, "Too few tool files. Maybe the files have been renamed again?");

	#
	# Scan the tool files for the actual definitions of the tools.
	#

	$tools = {};
	$vartools = {};
	$predefined_tools = {};
	$varname_to_toolname = {};
	$system_build_defs = {};
	foreach my $basename (@tool_files) {
		my $fname = "${cwd_pkgsrcdir}/mk/tools/${basename}";
		my $lines = load_lines($fname, true);

		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);
				if ($varname eq "TOOLS_CREATE" && $value =~ qr"^([-\w.]+|\[)$") {
					$tools->{$value} = true;

				} elsif ($varname =~ qr"^(?:_TOOLS_VARNAME)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;
					$vartools->{$1} = $value;
					$varname_to_toolname->{$value} = $1;

				} elsif ($varname =~ qr"^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;

				} elsif ($varname =~ qr"^_TOOLS\.(.*)") {
					$tools->{$1} = true;
					foreach my $tool (split(qr"\s+", $value)) {
						$tools->{$tool} = true;
					}
				}
			}
		}
	}

	foreach my $basename ("bsd.pkg.mk") {
		my $fname = "${cwd_pkgsrcdir}/mk/${basename}";
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
					$opt_debug_tools and $line->log_debug("[cond_depth=${cond_depth}] $value");
					if ($cond_depth == 0) {
						foreach my $tool (split(qr"\s+", $value)) {
							if ($tool !~ regex_unresolved && exists($tools->{$tool})) {
								$predefined_tools->{$tool} = true;
								# The path (without arguments) to the tool
								$predefined_tools->{"TOOLS_${tool}"} = true;
							}
						}
					}
				} elsif ($varname eq "_BUILD_DEFS") {
					foreach my $bdvar (split(qr"\s+", $value)) {
						$system_build_defs->{$bdvar} = true;
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

	$opt_debug_tools and log_debug(NO_FILE, NO_LINE_NUMBER, "Known tools: ".join(" ", sort(keys(%{$tools}))));
	$opt_debug_tools and log_debug(NO_FILE, NO_LINE_NUMBER, "Known vartools: ".join(" ", sort(keys(%{$vartools}))));
	$opt_debug_tools and log_debug(NO_FILE, NO_LINE_NUMBER, "Predefined tools: " . join(" ", sort(keys(%{$predefined_tools}))));
	$opt_debug_tools and log_debug(NO_FILE, NO_LINE_NUMBER, "Known varnames: " . join(" ", sort(keys(%{$varname_to_toolname}))));
	$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "System-provided BUILD_DEFS: " . join(" ", sort(keys(%{$system_build_defs}))));

	# Some user-defined variables do not influence the binary
	# package at all and therefore do not have to be added to
	# BUILD_DEFS.
	foreach my $bdvar (qw(DISTDIR FETCH_CMD FETCH_OUTPUT_ARGS GAMEOWN GAMEGRP GAMEDIRMODE)) {
		$system_build_defs->{$bdvar} = true;
	}
	#$system_build_defs->{"PACKAGES"} = true;

	$load_tool_names_tools = $tools;
	$load_tool_names_vartools = $vartools;
	$load_tool_names_predefined_tools = $predefined_tools;
	$load_tool_names_varname_to_toolname = $varname_to_toolname;
	$load_tool_names_system_build_defs = $system_build_defs;
}

# Returns the set of known tool names and contains for example "sed" and
# "gm4".
sub get_tool_names() {

	if (!defined($load_tool_names_tools)) {
		load_tool_names();
	}
	return $load_tool_names_tools;
}

# Returns the mapping from tool names to their respective variable. For
# example, "sed" => "SED", "gzip" => "GZIP_CMD".
sub get_vartool_names() {

	if (!defined($load_tool_names_vartools)) {
		load_tool_names();
	}
	return $load_tool_names_vartools;
}

# Returns the set of those tools with associated variables that a
# package does not need to add to USE_TOOLS explicitly because they
# are used by the pkgsrc infrastructure, too.
sub get_predefined_tool_names() {
	if (!defined($load_tool_names_predefined_tools)) {
		load_tool_names();
	}
	return $load_tool_names_predefined_tools;
}

# Returns a mapping from tool variable names to the tool name they use.
# For example, "GZIP_CMD" => "gzip" and "SED" => "sed".
sub get_varname_to_toolname() {
	if (!defined($load_tool_names_varname_to_toolname)) {
		load_tool_names();
	}
	return $load_tool_names_varname_to_toolname;
}

# Returns the set of tool variable names that may not be converted to
# their "direct" form, that is: ${CP} => cp.
sub get_required_vartool_varnames() {
	use constant required_vartool_varnames => array_to_hash(qw(ECHO ECHO_N FALSE TEST TRUE));

	return required_vartool_varnames;
}

# Returns the set of tools that must be used by their variable name.
sub get_required_vartools() {
	use constant required_vartools => array_to_hash(qw(echo false test true));

	return required_vartools;
}


# Returns the set of user-defined variables that are added to BUILD_DEFS
# within the bsd.pkg.mk file.
sub get_system_build_defs() {
	if (!defined($load_tool_names_system_build_defs)) {
		load_tool_names();
	}
	return $load_tool_names_system_build_defs;
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
		$get_doc_TODO_updates_result = load_doc_TODO_updates("${cwd_pkgsrcdir}/doc/TODO");
	}
	return $get_doc_TODO_updates_result;
}

my $get_wip_TODO_updates_result = undef;
sub get_wip_TODO_updates() {

	if (!defined($get_wip_TODO_updates_result)) {
		$get_wip_TODO_updates_result = load_doc_TODO_updates("${cwd_pkgsrcdir}/wip/TODO");
	}
	return $get_wip_TODO_updates_result;
}

sub get_suggested_package_updates() {

	return ($is_wip)
	    ? get_wip_TODO_updates()
	    : get_doc_TODO_updates();
}

# Load all variables from mk/defaults/mk.conf. Since pkglint does not
# load the infrastructure files during normal operation, these
# definitions have to be added explicitly.
sub load_userdefined_variables() {
	my $fname = "${cwd_pkgsrcdir}/mk/defaults/mk.conf";
	my ($lines, $vars);

	$vars = {};
	$lines = load_lines($fname, true);
	if (!$lines) {
		log_fatal($fname, NO_LINES, "Cannot be read.");
	}

	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			$vars->{$varname} = $line;
		}
	}

	return $vars;
}

my $get_userdefined_variables_result = undef;
sub get_userdefined_variables() {

	if (!defined($get_userdefined_variables_result)) {
		$get_userdefined_variables_result = load_userdefined_variables();
	}
	return $get_userdefined_variables_result;
}

sub match_all($$);	# needed by load_shared_dirs()

my $load_shared_dirs_dir_to_varname = undef;
my $load_shared_dirs_varname_to_dirs = undef;
my $load_shared_dirs_dir_to_id = undef;
sub load_shared_dirs() {
	return if defined($load_shared_dirs_dir_to_varname);

	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "load_shared_dirs()");

	my $dir_to_varname = {};
	my $varname_to_dirs = {};
	my $dir_to_id = {};

	foreach my $pkg qw(
		misc/gnome-dirs misc/gnome1-dirs misc/gnome2-dirs
		misc/theme-dirs
		misc/xdg-dirs misc/xdg-x11-dirs
		print/texmf-dirs) {

		$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "pkg=$pkg");
		my $dirs_mk = load_lines("$cwd_pkgsrcdir/$pkg/dirs.mk", true);
		assert($dirs_mk, "$pkg/dirs.mk is not readable.");

		foreach my $line (@$dirs_mk) {
			parseline_mk($line);
			if ($line->has("is_varassign")) {
				my $varname = $line->get("varname");
				my $value = $line->get("value");

				if ($varname =~ qr"^[A-Z]\w*_DIRS$" && $value ne "") {
					if (exists($dir_to_varname->{$value})) {
						# FIXME: misc/xdg-x11-dirs and misc/xdg-dirs conflict.
						#$line->log_warning("Duplicate directory, also appears in " . $dir_to_varname->{$value} . ".");
					} else {
						$dir_to_varname->{$value} = $varname;
					}
				}

			} elsif ($line->has("is_cond") && $line->get("directive") eq "for") {
				my $args = $line->get("args");
				while ($args =~ /\$\{(\w+_DIRS)\}/gc) {
					push(@{$varname_to_dirs->{$1}}, $pkg);
				}
			}
		}

		my $makefile = load_lines("$cwd_pkgsrcdir/$pkg/Makefile", true);
		assert(defined($makefile), "$pkg/Makefile is not readable.");
		foreach my $line (@$makefile) {
			my $pkgname = undef;

			parseline_mk($line);
			if ($line->has("is_varassign") && $line->get("varname") eq "DISTNAME") {
				if ($line->get("value") =~ qr"^(.*)-dirs-(.*)$") {
					$dir_to_id->{$pkg} = "$1-$2";
				} else {
					assert(false, "$pkg/Makefile does not define a proper DISTNAME.");
				}
			}
		}
	}
	$load_shared_dirs_dir_to_varname = $dir_to_varname;
	$load_shared_dirs_varname_to_dirs = $varname_to_dirs;
	$load_shared_dirs_dir_to_id = $dir_to_id;
}

# Given a directory name, returns a list of possible identifiers to be
# used in USE_DIRS.
sub get_shared_dir_ids($$) {
	my ($line, $dir) = @_;
	my @ids;

	$opt_debug_trace and $line->log_debug("get_shared_dir_ids(\"$dir\")");

	load_shared_dirs();
	my $varname = $load_shared_dirs_dir_to_varname->{$dir};
	return () unless $varname;
	#print "varname=$varname\n";
	foreach my $dir2 (@{$load_shared_dirs_varname_to_dirs->{$varname}}) {
		#print "dir2=$dir2\n";
		my $id = $load_shared_dirs_dir_to_id->{$dir2};
		#print "id=$id\n";
		push(@ids, $id);
	}
	return @ids;
}

#
# Miscellaneous functions
#

sub match_all($$) {
	my ($text, $re) = @_;
	my ($mm, $rest, $lastpos);

	$mm = [];
	$rest = $text;
	$lastpos = 0;
	pos(undef);
	while ($rest =~ m/$re/gc) {
		my @starts = @-;
		my @ends = @+;

		$lastpos = $ends[0];

		push(@{$mm}, PkgLint::SimpleMatch->new($text, \@starts, \@ends));
	}
	return ($mm, substr($rest, $lastpos));
}

sub autofix($) {
	my ($lines) = @_;

	if ($opt_autofix) {
		save_autofix_changes($lines);
	}
}

# Checks whether a file is already committed to the CVS repository or not.
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

# Checks whether a directory is practically empty, that is, all it
# contains are ".", ".." and "CVS", recursively.
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

# Guess the type of file based on the filename. This is used to select
# the proper subroutine for detecting absolute pathnames.
#
# Returns one of "source", "shell", "make", "text", "configure",
# "ignore", "unknown".
#
sub get_filetype($$) {
	my ($line, $fname) = @_;
	my $basename = basename($fname);

	# The trailig .in part is not needed, since it does not
	# influence the type of contents.
	$basename =~ s,\.in$,,;

	# Let's assume that everything else that looks like a Makefile
	# is indeed a Makefile.
	if ($basename =~ qr"^I?[Mm]akefile(?:\..*|)?|.*\.ma?k$") {
		return "make";
	}

	# Too many false positives for shell scripts, so configure
	# scripts get their own category.
	if ($basename =~ qr"^configure(?:|\.ac)$") {
		$opt_debug_unchecked and $line->log_debug("Skipped check for absolute pathnames.");
		return "configure";
	}

	if ($basename =~ qr"\.(?:sh|m4)$"i) {
		return "shell";
	}

	if ($basename =~ qr"\.(?:cc?|cpp|cxx|el|hh?|hpp|l|pl|pm|py|s|t|y)$"i) {
		return "source";
	}

	if ($basename =~ qr"^.+\.(?:\d+|conf|html|info|man|po|tex|texi|texinfo|txt|xml)$"i) {
		return "text";
	}

	# Filenames without extension are hard to guess right. :(
	if ($basename !~ qr"\.") {
		return "unknown";
	}

	$opt_debug_misc and $line->log_debug("Don't know the file type of ${fname}.");

	return "unknown";
}

# Returns the list of subdirectories of a directory, except "CVS".
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

# No package file should ever be executable. Even the INSTALL and
# DEINSTALL scripts are usually not usable in the form they have in the
# package, as the pathnames get adjusted during installation. So there is
# no need to have any file executable.
sub checkperms($) {
	my ($fname) = @_;

	if (-f $fname && -x $fname && !is_committed($fname)) {
		log_warning($fname, NO_LINE_NUMBER, "Should not be executable.");
	}
}

sub resolve_relative_path($$) {
	my ($relpath, $adjust_depth) = @_;

	my $arg = $relpath;
	$relpath =~ s,\$\{PKGSRCDIR\},$cur_pkgsrcdir,;
	$relpath =~ s,\$\{\.CURDIR\},.,;
	$relpath =~ s,\$\{\.PARSEDIR\},.,;
	$relpath =~ s,\$\{PHPPKGSRCDIR\},../../lang/php5,;
	$relpath =~ s,\$\{SUSE_DIR_PREFIX\},suse91,;
	$relpath =~ s,\$\{PYPKGSRCDIR\},../../lang/python23,;
	if ($adjust_depth && $relpath =~ qr"^\.\./\.\./([^.].*)$") {
		$relpath = "${cur_pkgsrcdir}/$1";
	}
	if (defined($pkgdir)) {
		$relpath =~ s,\$\{PKGDIR\},$pkgdir,g;
	}

	$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "resolve_relative_path: $arg => $relpath");
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
		$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "[expand_variable] The variable ${varname} could not be resolved completely. Its value is \"${value}\".");
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

# Returns the value of a shell word, with one level of quoting removed.
# This makes pattern matching easier when the interesting part is not
# what make(1) or sh(1) sees, but the command that is called by the
# shell. This function does not resolve or replace any variables.
sub unescape_shellword($) {
	my ($text) = @_;

	# TODO: implement this.
	assert(false, "unescape_shellword is not yet implemented.");
}

# Removes all uses of make variables from a string.
sub remove_variables($) {
	my ($text) = @_;

	while ($text =~ s/\$\{([^{}]*)\}//g) {
	}
	return $text;
}

# Converts an array of PkgLint::String to an array of PkgLint::Line.
sub strings_to_lines($) {
	my ($strings) = @_;
	my ($retval);

	$retval = [];
	foreach my $s (@{$strings}) {
		push(@{$retval}, $s->line);
	}
	return $retval;
}

sub backtrace($) {
	my $msg = shift();
	my (@callers);

	my $n = 0;
	while (my @info = caller($n)) {
		push(@callers, [$info[2], $info[3]]);
		$n++;
	}

	log_debug(NO_FILE, NO_LINE_NUMBER, $msg);
	for (my $i = $#callers; $i >= 0; $i--) {
		my $info = $callers[$i];
		log_debug(NO_FILE, NO_LINE_NUMBER, sprintf("  line %4d called %s", $info->[0], $info->[1]));
	}
}

# Returns the number of columns that a string occupies when printed with
# a tabulator size of 8.
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

sub varname_param($) {
	my ($varname) = @_;

	return ($varname =~ qr"^.*?\.(.*)$") ? $2 : undef;
}

sub use_var($$) {
	my ($line, $varname) = @_;
	my $varcanon = varname_canon($varname);

	if (defined($mkctx_varuse)) {
		$mkctx_varuse->{$varname} = $line;
		$mkctx_varuse->{$varcanon} = $line;
	}

	if (defined($pkgctx_varuse)) {
		$pkgctx_varuse->{$varname} = $line;
		$pkgctx_varuse->{$varcanon} = $line;
	}
}

sub var_is_used($) {
	my ($varname) = @_;
	my $varcanon = varname_canon($varname);

	if (defined($mkctx_varuse)) {
		return $mkctx_varuse->{$varname} if exists($mkctx_varuse->{$varname});
		return $mkctx_varuse->{$varcanon} if exists($mkctx_varuse->{$varcanon});
	}
	if (defined($pkgctx_varuse)) {
		return $pkgctx_varuse->{$varname} if exists($pkgctx_varuse->{$varname});
		return $pkgctx_varuse->{$varcanon} if exists($pkgctx_varuse->{$varcanon});
	}
	return false;
}

sub var_is_defined($) {
	my ($varname) = @_;
	my $varcanon = varname_canon($varname);

	if (defined($mkctx_vardef)) {
		return $mkctx_vardef->{$varname} if exists($mkctx_vardef->{$varname});
		return $mkctx_vardef->{$varcanon} if exists($mkctx_vardef->{$varcanon});
	}
	if (defined($pkgctx_vardef)) {
		return $pkgctx_vardef->{$varname} if exists($pkgctx_vardef->{$varname});
		return $pkgctx_vardef->{$varcanon} if exists($pkgctx_vardef->{$varcanon});
	}
	return false;
}

sub determine_used_variables($) {
	my ($lines) = @_;
	my ($rest);

	foreach my $line (@{$lines}) {
		$rest = $line->text;
		while ($rest =~ s/(?:\$\{|defined\(|empty\()([0-9+.A-Z_a-z]+)[:})]//) {
			my ($varname) = ($1);
			use_var($line, $varname);
			$opt_debug_unused and $line->log_debug("Variable ${varname} is used.");
		}
	}
}

sub extract_used_variables($$) {
	my ($line, $text) = @_;
	my ($rest, $result);

	$rest = $text;
	$result = [];
	while ($rest =~ s/^(?:[^\$]+|\$[\$*<>?\@]|\$\{([.0-9A-Z_a-z]+)(?::(?:[^\${}]|\$[^{])+)?\})//) {
		my ($varname) = ($1);

		if (defined($varname)) {
			push(@{$result}, $varname);
		}
	}

	if ($rest ne "") {
		$opt_debug_misc and $line->log_warning("Could not extract variables: ${rest}");
	}

	return $result;
}

my $check_pkglint_version_done = false;
sub check_pkglint_version() {

	return if $check_pkglint_version_done;
	$check_pkglint_version_done = true;

	my $lines = load_lines("${cwd_pkgsrcdir}/pkgtools/pkglint/Makefile", true);
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

# When processing a file using the expect* subroutines below, it may
# happen that $lineno points past the end of the file. In that case,
# print the warning without associated source code.
sub lines_log_warning($$$) {
	my ($lines, $lineno, $msg) = @_;

	assert(0 <= $lineno, "The line number is negative (${lineno}).");
	assert(@{$lines} != 0, "The lines may not be empty.");

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_warning($msg);
	} else {
		log_warning($lines->[0]->fname, "EOF", $msg);
	}
}

# Checks if the current line ($lines->{${$lineno_ref}}) matches the
# regular expression, and if it does, increments ${${lineno_ref}}.
# @param $lines
#	The lines that are checked.
# @param $lineno_ref
#	A reference to the line number, an integer variable.
# @param $regex
#	The regular expression to be checked.
# @return
#	The result of the regular expression match or false.
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
		lines_log_warning($lines, ${$lineno_ref}, "Expected \"${text}\".");
		return false;
	}
}

sub get_variable_type($$) {
	my ($line, $varname) = @_;
	my ($type);

	assert(defined($varname), "The varname parameter must be defined.");

	if (exists(get_vartypes_map()->{$varname})) {
		return get_vartypes_map()->{$varname};
	}

	my $varcanon = varname_canon($varname);
	if (exists(get_vartypes_map()->{$varcanon})) {
		return get_vartypes_map()->{$varcanon};
	}

	if (exists(get_varname_to_toolname()->{$varname})) {
		return PkgLint::Type->new(LK_NONE, "ShellCommand", [[ qr".*", "u" ]], NOT_GUESSED);
	}

	if ($varname =~ qr"^TOOLS_(.*)" && exists(get_varname_to_toolname()->{$1})) {
		return PkgLint::Type->new(LK_NONE, "Pathname", [[ qr".*", "u" ]], NOT_GUESSED);
	}

	use constant allow_all => [[ qr".*", "adpsu" ]];
	use constant allow_runtime => [[ qr".*", "adsu" ]];

	# Guess the datatype of the variable based on
	# naming conventions.
	$type =	  ($varname =~ qr"DIRS$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", allow_runtime, GUESSED)
		: ($varname =~ qr"(?:DIR|_HOME)$") ? PkgLint::Type->new(LK_NONE, "Pathname", allow_runtime, GUESSED)
		: ($varname =~ qr"FILES$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", allow_runtime, GUESSED)
		: ($varname =~ qr"FILE$") ? PkgLint::Type->new(LK_NONE, "Pathname", allow_runtime, GUESSED)
		: ($varname =~ qr"PATH$") ? PkgLint::Type->new(LK_NONE, "Pathlist", allow_runtime, GUESSED)
		: ($varname =~ qr"PATHS$") ? PkgLint::Type->new(LK_EXTERNAL, "List of Pathname", allow_runtime, GUESSED)
		: ($varname =~ qr"_USER$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", allow_all, GUESSED)
		: ($varname =~ qr"_GROUP$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", allow_all, GUESSED)
		: ($varname =~ qr"_ENV$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ qr"_CMD$") ? PkgLint::Type->new(LK_NONE, "ShellCommand", allow_runtime, GUESSED)
		: ($varname =~ qr"_ARGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ qr"_(?:C|CPP|CXX|LD|)FLAGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ qr"_MK$") ? PkgLint::Type->new(LK_NONE, "Unchecked", allow_all, GUESSED)
		: undef;

	if (defined($type)) {
		$opt_debug_vartypes and $line->log_debug("The guessed type of ${varname} is \"" . $type->to_string . "\".");
		return $type;
	}

	$opt_debug_vartypes and $line->log_debug("No type definition found for ${varcanon}.");
	return undef;
}

sub get_variable_perms($$) {
	my ($line, $varname) = @_;

	my $type = get_variable_type($line, $varname);
	if (!defined($type)) {
		$opt_debug_misc and $line->log_debug("No type definition found for ${varname}.");
		return "adpsu";
	}

	my $perms = $type->perms($line->fname, $varname);
	if (!defined($perms)) {
		$opt_debug_misc and $line->log_debug("No permissions specified for ${varname}.");
		return "?";
	}
	return $perms;
}

# This function returns whether a variable needs the :Q operator in a
# certain context. There are four possible outcomes:
#
# false:	The variable should not be quoted.
# true:		The variable should be quoted.
# doesnt_matter:
#		Since the values of the variable usually don't contain
#		special characters, it does not matter whether the
#		variable is quoted or not.
# dont_know:	pkglint cannot say whether the variable should be quoted
#		or not, most likely because type information is missing.
#
sub variable_needs_quoting($$$) {
	my ($line, $varname, $context) = @_;
	my $type = get_variable_type($line, $varname);
	my ($want_list, $have_list);

	$opt_debug_trace and $line->log_debug("variable_needs_quoting($varname, " . $context->to_string() . ")");

	use constant safe_types => array_to_hash(qw(
		DistSuffix
		FileMode Filename
		Identifier
		Option
		Pathname PkgName PkgOptionsVar PkgRevision
		RelativePkgDir RelativePkgPath
		URL UserGroupName
		Varname Version
		WrkdirSubdirectory
	));

	if (!defined($type) || !defined($context->type)) {
		return dont_know;
	}

	# Variables of certain predefined types, as well as all
	# enumerations, are expected to not require the :Q operator.
	if (ref($type->basic_type) eq "HASH" || exists(safe_types->{$type->basic_type})) {
		if ($type->kind_of_list == LK_NONE) {
			return false;

		} elsif ($type->kind_of_list == LK_EXTERNAL && $context->extent != VUC_EXTENT_WORD_PART) {
			return false;
		}
	}

	# In .for loops, the :Q operator is always misplaced, since
	# the items are broken up at white-space, not as shell words
	# like in all other parts of make(1).
	if ($context->shellword == VUC_SHELLWORD_FOR) {
		return false;
	}

	# Determine whether the context expects a list of shell words or
	# not.
	$want_list = $context->type->is_practically_a_list() && ($context->shellword == VUC_SHELLWORD_BACKT || $context->extent != VUC_EXTENT_WORD_PART);
	$have_list = $type->is_practically_a_list();

	$opt_debug_quoting and $line->log_debug("[variable_needs_quoting]"
		. " varname=$varname"
		. " context=" . $context->to_string()
		. " type=" . $type->to_string()
		. " want_list=" . ($want_list ? "yes" : "no")
		. " have_list=" . ($have_list ? "yes" : "no")
		. ".");

	# A shell word may appear as part of a shell word, for example
	# COMPILER_RPATH_FLAG.
	if ($context->extent == VUC_EXTENT_WORD_PART && $context->shellword == VUC_SHELLWORD_PLAIN) {
		if ($type->kind_of_list == LK_NONE && $type->basic_type eq "ShellWord") {
			return false;
		}
	}

	# Assume that the tool definitions don't include very special
	# characters, so they can safely be used inside any quotes.
	if (exists(get_varname_to_toolname()->{$varname})) {
		my $sw = $context->shellword;

		if ($sw == VUC_SHELLWORD_PLAIN && $context->extent != VUC_EXTENT_WORD_PART) {
			return false;

		} elsif ($sw == VUC_SHELLWORD_BACKT) {
			return false;

		} elsif ($sw == VUC_SHELLWORD_DQUOT || $sw == VUC_SHELLWORD_SQUOT) {
			return doesnt_matter;

		} else {
			# Let the other rules decide.
		}
	}

	# Variables that appear as parts of shell words generally need
	# to be quoted. An exception is in the case of backticks,
	# because the whole backticks expression is parsed as a single
	# shell word by pkglint.
	#
	# XXX: When the shell word parser gets rewritten the next time,
	# this test can be refined.
	if ($context->extent == VUC_EXTENT_WORD_PART && $context->shellword != VUC_SHELLWORD_BACKT) {
		return true;
	}

	# Assigning lists to lists does not require any quoting, though
	# there may be cases like "CONFIGURE_ARGS+= -libs ${LDFLAGS:Q}"
	# where quoting is necessary. So let's hope that no developer
	# ever makes the mistake of using :Q when appending a list to
	# a list.
	if ($want_list && $have_list) {
		return doesnt_matter;
	}

	# Appending elements to a list requires quoting, as well as
	# assigning a list value to a non-list variable.
	if ($want_list != $have_list) {
		return true;
	}

	$opt_debug_quoting and $line->log_debug("Don't know whether :Q is needed for ${varname}.");
	return dont_know;
}

#
# Parsing.
#

# This procedure fills in the extra fields of a line, depending on the
# line type. These fields can later be queried without having to parse
# them again and again.
#
sub parseline_mk($) {
	my ($line) = @_;
	my $text = $line->text;

	if ($text =~ regex_varassign) {
		my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

		# In variable assignments, a '#' character is preceded
		# by a backslash. In shell commands, it is interpreted
		# literally.
		$value =~ s/\\\#/\#/g;

		$line->set("is_varassign", true);
		$line->set("varname", $varname);
		$line->set("varcanon", varname_canon($varname));
		my $varparam = varname_param($varname);
		defined($varparam) and $line->set("varparam", $varparam);
		$line->set("op", $op);
		$line->set("value", $value);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_shellcmd) {
		my ($shellcmd) = ($1);

		# Shell command lines cannot have embedded comments.
		$line->set("is_shellcmd", true);
		$line->set("shellcmd", $shellcmd);

		my ($shellwords, $rest) = match_all($shellcmd, $regex_shellword);
		$line->set("shellwords", $shellwords);
		if ($rest !~ qr"^\s*$") {
			$line->set("shellwords_rest", $rest);
		}

	} elsif ($text =~ regex_mk_comment) {
		my ($comment) = ($1);

		$line->set("is_comment", true);
		$line->set("comment", $comment);

	} elsif ($text =~ qr"^\s*$") {

		$line->set("is_empty", true);

	} elsif ($text =~ regex_mk_cond) {
		my ($indent, $directive, $args, $comment) = ($1, $2, $3, $4);

		$line->set("is_cond", true);
		$line->set("indent", $indent);
		$line->set("directive", $directive);
		defined($args) and $line->set("args", $args);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_include) {
		my ($includefile, $comment) = ($1, $2);

		$line->set("is_include", true);
		$line->set("includefile", $includefile);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_sysinclude) {
		my ($includefile, $comment) = ($1, $2);

		$line->set("is_sysinclude", true);
		$line->set("includefile", $includefile);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_dependency) {
		my ($targets, $sources, $comment) = ($1, $2, $3);

		$line->set("is_dependency", true);
		$line->set("targets", $targets);
		$line->set("sources", $sources);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_rcs_conflict) {
		# This line is useless

	} else {
		assert(false, "Unknown line format: " . $line->to_string());
	}
}

sub parselines_mk($) {
	my ($lines) = @_;

	foreach my $line (@{$lines}) {
		parseline_mk($line);
	}
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
	parselines_mk($lines);

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

			} else {
				$is_include_line = true;
			}
		}

		if ($is_include_line) {
			if ($fname !~ qr"buildlink3\.mk$" && $includefile =~ qr"^\.\./\.\./(.*)/buildlink3\.mk$") {
				my ($bl3_file) = ($1);

				$pkgctx_bl3->{$bl3_file} = $line;
				$opt_debug_misc and $line->log_debug("Buildlink3 file in package: ${bl3_file}");
			}
		}

		if ($is_include_line && !exists($seen_Makefile_include->{$includefile})) {
			$seen_Makefile_include->{$includefile} = true;

			if ($includefile =~ qr"^\.\./[^./][^/]*/[^/]+") {
				$line->log_warning("Relative directories should look like \"../../category/package\", not \"../package\".");
				$line->explain_warning(expl_relative_dirs);
			}
			if ($includefile =~ qr"(?:^|/)Makefile.common$"
			    || ($includefile =~ qr"^(?:\.\./(\.\./[^/]+/)?[^/]+/)?([^/]+)$"
				&& (!defined($1) || $1 ne "../mk")
				&& $2 ne "buildlink3.mk"
				&& $2 ne "options.mk")) {
				$opt_debug_include and $line->log_debug("including ${includefile} sets seen_Makefile_common.");
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
					$opt_debug_include and $line->log_debug("Including \"$dirname/$includefile\".");
					$contents .= readmakefile("$dirname/$includefile", $main_lines, $all_lines, $seen_Makefile_include);
				}
			}

		} elsif ($line->has("is_varassign")) {
			my ($varname, $op, $value) = ($line->get("varname"), $line->get("op"), $line->get("value"));

			# Record all variables that are defined in these lines, so that they
			# are not reported as "used but not defined".
			if ($op ne "?=" || !exists($pkgctx_vardef->{$varname})) {
				$opt_debug_misc and $line->log_debug("varassign(${varname}, ${op}, ${value})");
				$pkgctx_vardef->{$varname} = $line;
			}
			$contents .= $text . "\n";

		} else {
			$contents .= $text . "\n";
		}
	}

	return $contents;
}

sub load_package_Makefile($$$) {
	my ($fname, $ref_whole, $ref_lines) = @_;
	my ($subr) = "load_package_Makefile";
	my ($whole, $lines, $all_lines, $seen_php_pecl_version);

	$opt_debug_trace and log_debug($fname, NO_LINES, "load_package_Makefile()");

	$whole = readmakefile($fname, $lines = [], $all_lines = [], {});
	if (!$whole) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	if ($opt_dumpmakefile) {
		log_debug(NO_FILE, NO_LINES, "Whole Makefile (with all included files) follows:");
		foreach my $line (@{$all_lines}) {
			print($line->to_string() . "\n");
		}
	}

	determine_used_variables($all_lines);

	$pkgdir = expand_variable($whole, "PKGDIR");
	set_default_value(\$pkgdir, ".");
	$distinfo_file = expand_variable($whole, "DISTINFO_FILE");
	set_default_value(\$distinfo_file, "distinfo");
	$filesdir = expand_variable($whole, "FILESDIR");
	set_default_value(\$filesdir, "files");
	$patchdir = expand_variable($whole, "PATCHDIR");
	set_default_value(\$patchdir, "patches");

	if (var_is_defined("PHPEXT_MK")) {
		if (!var_is_defined("USE_PHP_EXT_PATCHES")) {
			$patchdir = "patches";
		}
		if (var_is_defined("PECL_VERSION")) {
			$distinfo_file = "distinfo";
		}
	}

	$opt_debug_misc and log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] DISTINFO_FILE=$distinfo_file");
	$opt_debug_misc and log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] FILESDIR=$filesdir");
	$opt_debug_misc and log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] PATCHDIR=$patchdir");
	$opt_debug_misc and log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] PKGDIR=$pkgdir");

	${$ref_whole} = $whole;
	${$ref_lines} = $lines;
	return true;
}

sub warn_about_PLIST_imake_mannewsuffix($) {
	my ($line) = @_;

	$line->log_warning("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.");
	$line->explain_warning(
"This is the result of a print-PLIST call that has _not_ been checked",
"thoroughly by the developer. Please replace the IMAKE_MANNEWSUFFIX with",
"",
"\tIMAKE_MAN_SUFFIX for programs,",
"\tIMAKE_LIBMAN_SUFFIX for library functions,",
"\tIMAKE_FILEMAN_SUFFIX for file formats,",
"\tIMAKE_GAMEMAN_SUFFIX for games,",
"\tIMAKE_MISCMAN_SUFFIX for other man pages.");
}

#
# Subroutines to check part of a single line.
#

sub checkword_absolute_pathname($$) {
	my ($line, $word) = @_;

	$opt_debug_trace and $line->log_debug("checkword_absolute_pathname(\"${word}\")");

	if ($word =~ qr"^/dev/(?:null|tty|zero)$") {
		# These are defined by POSIX.

	} elsif ($word eq "/bin/sh") {
		# This is usually correct, although on Solaris, it's pretty
		# feature-crippled.

	} elsif ($word !~ qr"/(?:[a-z]|\$[({])") {
		# Assume that all pathnames start with a lowercase letter.

	} else {
		$line->log_warning("Found absolute pathname: ${word}");
		$line->explain_warning(
			"Absolute pathnames are often an indicator for unportable code. As",
			"pkgsrc aims to be a portable system, absolute pathnames should be",
			"avoided whenever possible.",
			"",
			"A special variable in this context is \${DESTDIR}, which is used in GNU",
			"projects to specify a different directory for installation than what",
			"the programs see later when they are executed. Usually it is empty, so",
			"if anything after that variable starts with a slash, it is considered",
			"an absolute pathname.");
	}
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

	$varname = $line->get("varname");
	$rest = $line->get("value");

	$rest =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning("${varname} contains invalid characters (" . join(", ", @chars) . ").");
	}
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;

	$opt_debug_trace and $line->log_debug("checkline_trailing_whitespace()");

	if ($line->text =~ /\s+$/) {
		$line->log_note("Trailing white-space.");
		$line->replace_regex(qr"\s+\n$", "\n");
	}
}

sub checkline_rcsid_regex($$$) {
	my ($line, $prefix_regex, $prefix) = @_;
	my ($id) = ($opt_rcsidstring . ($is_wip ? "|Id" : ""));

	$opt_debug_trace and $line->log_debug("checkline_rcsid_regex(${prefix_regex}, ${prefix})");

	if ($line->text !~ qr"^${prefix_regex}\$(${id})(?::[^\$]+|)\$$") {
		$line->log_error("\"${prefix}\$${opt_rcsidstring}\$\" expected.");
		return false;
	}
	return true;
}

sub checkline_rcsid($$) {
	my ($line, $prefix) = @_;

	checkline_rcsid_regex($line, quotemeta($prefix), $prefix);
}

# Checks whether the line contains text that looks like absolute
# pathnames, assuming that the file uses the common syntax with
# single or double quotes to represent strings.
#
sub checkline_source_absolute_pathname($$) {
	my ($line, $text) = @_;
	my ($abspath);

	$opt_debug_trace and $line->log_debug("checkline_source_absolute_pathname(${text})");

	if ($text =~ qr"(.*)([\"'])(/[^\"']*)\2") {
		my ($before, $delim, $string) = ($1, $2, $3);

		$opt_debug_misc and $line->log_debug("checkline_source_absolute_pathname(before=${before}, string=${string})");
		if ($before =~ qr"[A-Z_]+\s*$") {
			# allowed: PREFIX "/bin/foo"

		} elsif ($string =~ qr"^/[*/]") {
			# This is more likely to be a C or C++ comment.

		} elsif ($string !~ qr"^/\w") {
			# Assume that pathnames start with a letter or digit.

		} elsif ($before =~ qr"\+\s*$") {
			# Something like foodir + '/lib'

		} else {
			$abspath = $string;
		}
	}

	if (defined($abspath)) {
		checkword_absolute_pathname($line, $abspath);
	}
}

sub checkline_mk_absolute_pathname($$) {
	my ($line, $text) = @_;
	my $abspath;

	$opt_debug_trace and $line->log_debug("checkline_mk_absolute_pathname(${text})");

	# In the GNU coding standards, DESTDIR is defined as a (usually
	# empty) prefix that can be used to install files to a different
	# location from what they have been built for. Therefore
	# everything following it is considered an absolute pathname.
	# Another commonly used context is in assignments like
	# "bindir=/bin".
	if ($text =~ qr"(?:^|\$\{DESTDIR\}|\$\(DESTDIR\)|[\w_]+\s*=\s*)(/(?:[^\"'\`\s]|\"[^\"*]\"|'[^']*'|\`[^\`]*\`)*)") {
		my $path = $1;

		if ($path =~ qr"^/\w") {
			$abspath = $path;
		}
	}

	if (defined($abspath)) {
		checkword_absolute_pathname($line, $abspath);
	}
}

# Last resort if the file does not look like a Makefile or typical
# source code. All strings that look like pathnames and start with
# one of the typical Unix prefixes are found.
#
sub checkline_other_absolute_pathname($$) {
	my ($line, $text) = @_;

	$opt_debug_trace and $line->log_debug("checkline_other_absolute_pathname(\"${text}\")");

	if ($text =~ qr"^#[^!]") {
		# Don't warn for absolute pathnames in comments,
		# except for shell interpreters.

	} elsif ($text =~ qr"^(.*?)((?:/[\w.]+)*/(?:bin|dev|etc|home|lib|mnt|opt|proc|sbin|tmp|usr|var)\b[\w./\-]*)(.*)$") {
		my ($before, $path, $after) = ($1, $2, $3);

		if ($before =~ qr"\@$") {
			# Something like @PREFIX@/bin

		} elsif ($before =~ qr"[)}]$") {
			# Something like ${prefix}/bin or $(PREFIX)/bin

		} elsif ($before =~ qr"\+\s*[\"']$") {
			# Something like foodir + '/lib'

		} elsif ($before =~ qr"\w$") {
			# Something like $dir/lib

		} elsif ($before =~ qr"\.$") {
			# ../foo is not an absolute pathname.

		} else {
			$opt_debug_misc and $line->log_debug("before=${before}");
			checkword_absolute_pathname($line, $path);
		}
	}
}

sub checkline_relative_path($$) {
	my ($line, $path) = @_;
	my ($res_path);

	if (!$is_wip && $path =~ qr"/wip/") {
		$line->log_error("A pkgsrc package must not depend on any outside package.");
	}
	$res_path = resolve_relative_path($path, true);
	if ($res_path =~ regex_unresolved) {
		$opt_debug_unchecked and $line->log_debug("Unchecked path: \"${path}\".");
	} elsif (!-e ((($res_path =~ qr"^/") ? "" : "${current_dir}/") . $res_path)) {
		$line->log_error("\"${res_path}\" does not exist.");
	} elsif ($path =~ qr"^\.\./\.\./([^/]+)/([^/]+)(.*)") {
		my ($cat, $pkg, $rest) = ($1, $2, $3);
	} elsif ($path =~ qr"^\.\./\.\./mk/") {
		# There need not be two directory levels for mk/ files.
	} elsif ($path =~ qr"^\.\./mk/" && $cur_pkgsrcdir eq "..") {
		# That's fine for category Makefiles.
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
		__sgi
		__sun

		__GLIBC__
	));
	use constant bad_macros  => {
		"__sgi__" => "__sgi",
		"__sparc__" => "__sparc",
		"__sparc_v9__" => "__sparcv9",
		"__sun__" => "__sun",
		"__svr4__" => "__SVR4",
	};

	$rest = $text;
	while ($rest =~ s/defined\((__[\w_]+)\)//) {
		my ($macro) = ($1);

		if (exists(good_macros->{$macro})) {
			$opt_debug_misc and $line->log_debug("Found good macro \"${macro}\".");
		} elsif (exists(bad_macros->{$macro})) {
			$line->log_warning("The macro \"${macro}\" is not portable enough. Please use \"".bad_macros->{$macro}."\" instead.");
			$line->explain_warning("See the pkgsrc guide, section \"CPP defines\" for details.");
		} else {
			$opt_debug_unchecked and $line->log_debug("Unchecked macro \"${macro}\".");
		}
	}
}

sub checkline_mk_varuse($$$$) {
	my ($line, $varname, $mod, $context) = @_;

	assert(defined($varname), "The varname parameter must be defined");
	assert(defined($context), "The context parameter must be defined");
	$opt_debug_trace and $line->log_debug("checkline_mk_varuse(\"${varname}\", \"${mod}\", ".$context->to_string().")");

	# Check for spelling mistakes.
	my $type = get_variable_type($line, $varname);
	if (defined($type) && !($type->is_guessed)) {
		# Great.

	} elsif (defined($pkgctx_vardef) && exists($pkgctx_vardef->{$varname})) {
		# A variable that is defined somewhere may also be used.

	} elsif (exists($mkctx_vardef->{$varname})) {
		# A variable that has been defined in the current file
		# may also be used.

	} elsif (defined($mkctx_for_variables) && exists($mkctx_for_variables->{$varname})) {
		# Variables defined in .for loops are also ok.

	} else {
		$opt_warn_extra and $line->log_warning("${varname} is used but not defined. Spelling mistake?");
	}

	if ($opt_warn_perm) {
		my $perms = get_variable_perms($line, $varname);
		my $is_load_time;	# Will the variable be used at load time?
		my $is_indirect;	# Might the variable be used indirectly at load time,
					# for example by assigning it to another variable
					# which then gets evaluated?

		# Don't warn about variables that are not recorded in the
		# pkglint variable definition.
		if (defined($context->type) && $context->type->is_guessed()) {
			$is_load_time = false;

		} elsif ($context->time == VUC_TIME_LOAD && $perms !~ qr"p") {
			$is_load_time = true;
			$is_indirect = false;

		} elsif (defined($context->type) && $context->type->perms_union() =~ qr"p" && $perms !~ qr"p") {
			$is_load_time = true;
			$is_indirect = true;

		} else {
			$is_load_time = false;
		}

		if ($is_load_time && !$is_indirect) {
			$line->log_warning("${varname} should not be evaluated at load time.");
			$line->explain_warning(
				"Many variables, especially lists of something, get their values",
				"incrementally. Therefore it is generally unsafe to rely on their value",
				"until it is clear that it will never change again. This point is",
				"reached when the whole package Makefile is loaded and execution of the",
				"shell commands starts, in some cases earlier.",
				"",
				"Additionally, when using the \":=\" operator, each \$\$ is replaced",
				"with a single \$, so variables that have references to shell variables",
				"or regular expressions are modified in a subtle way.");
		}
		if ($is_load_time && $is_indirect) {
			$line->log_warning("${varname} should not be evaluated indirectly at load time.");
			$line->explain_warning(
				"The variable on the left-hand side may be evaluated at load time, but",
				"the variable on the right-hand side may not. Due to this assignment, it",
				"might be used indirectly at load-time, when it is not guaranteed to be",
				"properly defined.");
		}

		if ($perms !~ qr"p" && $perms !~ qr"u") {
			$line->log_warning("${varname} may not be used in this file.");
		}
	}

	my $needs_quoting = variable_needs_quoting($line, $varname, $context);

	if ($context->shellword == VUC_SHELLWORD_FOR) {
		if (!defined($type)) {
			# Cannot check anything here.

		} elsif ($type->kind_of_list == LK_INTERNAL) {
			# Fine.

		} elsif ($needs_quoting == doesnt_matter || $needs_quoting == false) {
			# Fine, these variables are assumed to not
			# contain special characters.

		} else {
			$line->log_warning("The variable ${varname} should not be used in .for loops.");
			$line->explain_warning(
				"The .for loop splits its argument at sequences of white-space, as",
				"opposed to all other places in make(1), which act like the shell.",
				"Therefore only variables that are specifically designed to match this",
				"requirement should be used here.");
		}
	}

	if ($opt_warn_quoting and $context->shellword != VUC_SHELLWORD_UNKNOWN && $needs_quoting != dont_know) {

		# In GNU configure scripts, a few variables need to be
		# passed through the :M* operator before they reach the
		# configure scripts.
		my $need_mstar = false;
		if ($varname =~ regex_gnu_configure_volatile_vars) {
			# When we are not checking a package, but some other file,
			# the :M* operator is needed for safety.
			if (!defined($pkgctx_vardef) || exists($pkgctx_vardef->{"GNU_CONFIGURE"})) {
				$need_mstar = true;
			}
		}

		my $stripped_mod = ($mod =~ qr"(.*?)(?::M\*)?(?::Q)?$") ? $1 : $mod;
		my $correct_mod = $stripped_mod . ($need_mstar ? ":M*:Q" : ":Q");

		if ($mod eq ":M*:Q" && !$need_mstar) {
			$line->log_note("The :M* modifier is not needed here.");

		} elsif ($mod ne $correct_mod && $needs_quoting == true) {
			if ($context->shellword == VUC_SHELLWORD_PLAIN) {
				$line->log_warning("Please use \${${varname}${correct_mod}} instead of \${${varname}${mod}}.");
				#$line->replace("\${${varname}}", "\${${varname}:Q}");
			} else {
				$line->log_warning("Please use \${${varname}${correct_mod}} instead of \${${varname}${mod}} and make sure the variable appears outside of any quoting characters.");
			}
			$line->explain_warning("See the pkgsrc guide, section \"quoting guideline\", for details.");
		}

		if ($needs_quoting == false && $mod =~ qr":Q$") {
			$line->log_warning("The :Q operator should not be used for \${${varname}} here.");
			$line->explain_warning(
"Many variables in pkgsrc do not need the :Q operator, since they",
"are not expected to contain white-space or other evil characters.",
"",
"Another case is when a variable of type ShellWord appears in a context",
"that expects a shell word, it does not need to have a :Q operator. Even",
"when it is concatenated with another variable, it still stays _one_ word.",
"",
"Example:",
"\tWORD1=  Have\\ fun             # 1 word",
"\tWORD2=  \"with BSD Make\"       # 1 word, too",
"",
"\tdemo:",
"\t\techo \${WORD1}\${WORD2} # still 1 word");

		}
	}

	assert(defined($mkctx_build_defs), "The build_defs variable must be defined here.");
	if (exists(get_userdefined_variables()->{$varname}) && !exists(get_system_build_defs()->{$varname}) && !exists($mkctx_build_defs->{$varname})) {
		$line->log_warning("The user-defined variable ${varname} is used but not added to BUILD_DEFS.");
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
		$line->explain_warning(
			"You should define WRKSRC such that all of CONFIGURE_DIRS, BUILD_DIRS",
			"and INSTALL_DIRS are subdirectories of it.");
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
	my ($rest, $state, $value);

	$opt_debug_trace and $line->log_debug("checkline_mk_shellword(\"${shellword}\", ${check_quoting}).");
	use constant shellcommand_context_type => PkgLint::Type->new(
		LK_NONE, "ShellCommand", [[ qr".*", "adsu" ]], NOT_GUESSED
	);
	use constant shellword_vuc => PkgLint::VarUseContext->new(
		VUC_TIME_UNKNOWN,
		shellcommand_context_type,
		VUC_SHELLWORD_PLAIN,
		VUC_EXTENT_WORD
	);

	if ($shellword =~ qr"^\$\{(${regex_varname})(:[^{}]+)?\}$") {
		my ($varname, $mod) = ($1, $2);

		checkline_mk_varuse($line, $varname, defined($mod) ? $mod : "", shellword_vuc);
		return;
	}

	if ($shellword =~ qr"\$\{PREFIX\}/man(?:$|/)") {
		$line->log_warning("Please use \${PKGMANDIR} instead of \"man\".");
	}

	# Note: SWST means [S]hell[W]ord [ST]ate
	use enum qw(:SWST_ PLAIN SQUOT DQUOT DQUOT_BACKT BACKT);
	use constant statename		=> [
		"SWST_PLAIN", "SWST_SQUOT", "SWST_DQUOT",
		"SWST_DQUOT_BACKT", "SWST_BACKT",
	];
	use constant user_statename	=> [
		"unquoted string", "single quoted string",
		"double quoted string", "backticks inside double quoted string",
		"backticks",
	];

	$rest = ($shellword =~ qr"^#") ? "" : $shellword;
	$state = SWST_PLAIN;
	while ($rest ne "") {

		$opt_debug_shell and $line->log_debug(statename->[$state] . ": ${rest}");

		# When we are parsing inside backticks, it is more
		# reasonable to check the whole shell command
		# recursively, instead of splitting off the first
		# make(1) variable (see the elsif below).
		if ($state == SWST_BACKT || $state == SWST_DQUOT_BACKT) {

			# Scan for the end of the backticks, checking
			# for single backslashes and removing one level
			# of backslashes. Backslashes are only removed
			# before a dollar, a backslash or a backtick.
			#
			# References:
			# * http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
			my $stripped = "";
			while ($rest ne "") {
				if ($rest =~ s/^\`//) {
					$state = ($state == SWST_BACKT) ? SWST_PLAIN : SWST_DQUOT;
					goto end_of_backquotes;
				} elsif ($rest =~ s/^\\([\\\`\$])//) {
					$stripped .= $1;
				} elsif ($rest =~ s/^(\\)//) {
					$line->log_warning("Backslashes should be doubled inside backticks.");
					$stripped .= $1;
				} elsif ($state == SWST_DQUOT_BACKT && $rest =~ s/^"//) {
					$line->log_warning("Double quotes inside backticks inside double quotes are error prone.");
					$line->explain_warning(
"According to the SUSv3, they produce undefined results.",
"",
"See the paragraph starting \"Within the backquoted ...\" in",
"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html");
				} elsif ($rest =~ s/^([^\\\`]+)//) {
					$stripped .= $1;
				} else {
					assert(false, "rest=$rest");
				}
			}
			$line->log_error("Unfinished backquotes: rest=$rest");

		end_of_backquotes:
			# Check the resulting command.
			checkline_mk_shelltext($line, $stripped);

		# make(1) variables have the same syntax, no matter in
		# which state we are currently.
		} elsif ($rest =~ s/^\$\{(${regex_varname}|[\@])(:[^\{]+)?\}//
		||  $rest =~ s/^\$\((${regex_varname}|[\@])(:[^\)]+)?\)//
		||  $rest =~ s/^\$([\w\@])//) {
			my ($varname, $mod) = ($1, $2);

			if ($varname eq "\@") {
				$line->log_warning("Please use \"\${.TARGET}\" instead of \"\$\@\".");
				$line->explain_warning(
					"The variable \$\@ can easily be confused with the shell variable of the",
					"same name, which has a completely different meaning.");
				$varname = ".TARGET";
			}

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

			}

			my $ctx = PkgLint::VarUseContext->new_from_pool(
				VUC_TIME_UNKNOWN,
				shellcommand_context_type,
				  ($state == SWST_PLAIN) ? VUC_SHELLWORD_PLAIN
				: ($state == SWST_DQUOT) ? VUC_SHELLWORD_DQUOT
				: ($state == SWST_SQUOT) ? VUC_SHELLWORD_SQUOT
				: ($state == SWST_BACKT) ? VUC_SHELLWORD_BACKT
				: VUC_SHELLWORD_UNKNOWN,
				VUC_EXTENT_WORD_PART
			);
			if ($varname ne "\@") {
				checkline_mk_varuse($line, $varname, defined($mod) ? $mod : "", $ctx);
			}

		# The syntax of the variable modifiers can get quite
		# hairy. In lack of motivation, we just skip anything
		# complicated, hoping that at least the braces are
		# balanced.
		} elsif ($rest =~ s/^\$\{//) {
			my $braces = 1;
			while ($rest ne "" && $braces > 0) {
				if ($rest =~ s/^\}//) {
					$braces--;
				} elsif ($rest =~ s/^\{//) {
					$braces++;
				} elsif ($rest =~ s/^[^{}]+//) {
					# Nothing to do here.
				} else {
					last;
				}
			}

		} elsif ($state == SWST_PLAIN) {

			if ($rest =~ qr"([\w_]+)=\"\`") {
				$line->log_note("In the assignment to \"$1\", you don't need double quotes around backticks.");
				$line->explain_note(
"Assignments are a special context, where no double quotes are needed",
"around backticks. In other contexts, the double quotes are necessary.");
			}

			if ($rest =~ s/^[!#\%&\(\)*+,\-.\/0-9:;<=>?\@A-Z\[\]^_a-z{|}~]+//) {
			} elsif ($rest =~ s/^\'//) {
				$state = SWST_SQUOT;
			} elsif ($rest =~ s/^\"//) {
				$state = SWST_DQUOT;
			} elsif ($rest =~ s/^\`//) {
				$state = SWST_BACKT;
			} elsif ($rest =~ s/^\\(?:[ !"#'\(\)*;?\\^{|}]|\$\$)//) {
			} elsif ($rest =~ s/^\$\$([0-9A-Z_a-z]+|\#)//
			    || $rest =~ s/^\$\$\{([0-9A-Z_a-z]+|\#)\}//) {
				my ($shvarname) = ($1);
				if ($opt_warn_quoting && $check_quoting) {
					$line->log_warning("Unquoted shell variable \"${shvarname}\".");
				}

			} elsif ($rest =~ s/^\$\@//) {
				$line->log_warning("Please use \"\${.TARGET}\" instead of \"\$@\".");
				$line->explain_warning(
					"It is more readable and prevents confusion with the shell variable of",
					"the same name.");

			} elsif ($rest =~ s/^\$\$\@//) {
				$line->log_warning("The \$@ shell variable should only be used in double quotes.");

			} elsif ($rest =~ s/^\$\$\?//) {
				$line->log_warning("The \$? shell variable is often not available in \"set -e\" mode.");

			} elsif ($rest =~ s/^\$\$\(/(/) {
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
			} elsif ($rest =~ s/^\`//) {
				$state = SWST_DQUOT_BACKT;
			} elsif ($rest =~ s/^[^\$"\\\`]+//) {
			} elsif ($rest =~ s/^\\(?:[\\\"\`]|\$\$)//) {
			} elsif ($rest =~ s/^\$\$\{([0-9A-Za-z_]+)\}//
			    || $rest =~ s/^\$\$([0-9A-Z_a-z]+|[!#?\@]|\$\$)//) {
				my ($shvarname) = ($1);
				$opt_debug_shell and $line->log_debug("[checkline_mk_shellword] Found double-quoted variable ${shvarname}.");
			} elsif ($rest =~ s/^\$\$//) {
				$line->log_warning("Unquoted \$ or strange shell variable found.");
			} elsif ($rest =~ s/^\\(.)//) {
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

		} else {
			last;
		}
	}
	if ($rest !~ qr"^\s*$") {
		$line->log_error("Internal pkglint error: " . statename->[$state] . ": rest=${rest}");
	}
}

# Some shell commands should not be used in the install phase.
#
sub checkline_mk_shellcmd_use($$) {
	my ($line, $shellcmd) = @_;

	use constant allowed_install_commands => array_to_hash(qw(
		${INSTALL}
		${INSTALL_DATA} ${INSTALL_DATA_DIR}
		${INSTALL_LIB} ${INSTALL_LIB_DIR}
		${INSTALL_MAN} ${INSTALL_MAN_DIR}
		${INSTALL_PROGRAM} ${INSTALL_PROGRAM_DIR}
		${INSTALL_SCRIPT}
		${LIBTOOL}
		${LN}
		${PAX}
	));
	use constant discouraged_install_commands => array_to_hash(qw(
		sed ${SED}
		tr ${TR}
	));

	if (defined($mkctx_target) && $mkctx_target =~ qr"^(?:pre|do|post)-install") {

		if (exists(allowed_install_commands->{$shellcmd})) {
			# Fine.

		} elsif (exists(discouraged_install_commands->{$shellcmd})) {
			$line->log_warning("The shell command \"${shellcmd}\" should not be used in the install phase.");
			$line->explain_warning(
				"In the install phase, the only thing that should be done is to install",
				"the prepared files to their final location. The file's contents should",
				"not be changed anymore.");

		} elsif ($shellcmd eq "\${CP}") {
			$line->log_warning("\${CP} should not be used to install files.");
			$line->explain_warning(
				"The \${CP} command is highly platform dependent and cannot overwrite",
				"files that don't have write permission. Please use \${PAX} instead.",
				"",
				"For example, instead of",
				"\t\${CP} -R \${WRKSRC}/* \${PREFIX}/foodir",
				"you should use",
				"\tcd \${WRKSRC} && \${PAX} -wr * \${PREFIX}/foodir");

		} else {
			$opt_debug_misc and $line->log_debug("May \"${shellcmd}\" be used in the install phase?");
		}
	}
}

sub checkline_mk_shelltext($$) {
	my ($line, $text) = @_;
	my ($vartools, $state, $rest, $set_e_mode);

	$opt_debug_trace and $line->log_debug("checkline_mk_shelltext(\"$text\")");

	# Note: SCST is the abbreviation for [S]hell [C]ommand [ST]ate.
	use constant scst => qw(
		START CONT
		INSTALL INSTALL_D
		MKDIR
		PAX PAX_S
		SED SED_E
		SET SET_CONT
		COND COND_CONT
		CASE CASE_IN CASE_LABEL CASE_LABEL_CONT CASE_PAREN
		FOR FOR_IN FOR_CONT
		ECHO
		INSTALL_DIR INSTALL_DIR2
	);
	use enum (":SCST_", scst);
	use constant scst_statename => [ map { $_ = "SCST_$_"; } scst ];

	use constant forbidden_commands => array_to_hash(qw(
		ktrace
		strace
		truss
	));

	if ($text =~ qr"\$\{SED\}" && $text =~ qr"\$\{MV\}") {
		$line->log_note("Please use the SUBST framework instead of \${SED} and \${MV}.");
		$line->explain_note(
			"When converting things, pay attention to \"#\" characters. In shell",
			"commands make(1) does not interpret them as comment character, but",
			"in other lines it does. Therefore, instead of the shell command",
			"",
			"\tsed -e 's,#define foo,,'",
			"",
			"you need to write",
			"",
			"\tSUBST_SED.foo+=\t's,\\#define foo,,'");
	}

	if ($text =~ qr"^\@*-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)") {
		my ($mkdir_cmd) = ($1);

		$line->log_note("You don't need to use \"-\" before ${mkdir_cmd}.");
	}

	$vartools = get_vartool_names();
	$rest = $text;

	use constant hidden_shell_commands => array_to_hash(qw(
		${DELAYED_ERROR_MSG} ${DELAYED_WARNING_MSG}
		${DO_NADA}
		${ECHO} ${ECHO_MSG} ${ECHO_N} ${ERROR_CAT} ${ERROR_MSG}
		${FAIL_MSG}
		${PHASE_MSG} ${PRINTF}
		${SHCOMMENT} ${STEP_MSG}
		${WARNING_CAT} ${WARNING_MSG}
	));

	if ($rest =~ s/^\s*([-@]*)(?:\$\{_PKG_SILENT\}\$\{_PKG_DEBUG\})?//) {
		my ($hidden) = ($1);

		if ($hidden !~ qr"\@") {
			# Nothing is hidden at all.

		} elsif (defined($mkctx_target) && $mkctx_target =~ qr"^(?:show-.*|.*-message)$") {
			# In some targets commands may be hidden.

		} elsif ($rest =~ $regex_shellword) {
			my ($cmd) = ($1);

			if (!exists(hidden_shell_commands->{$cmd})) {
				$line->log_warning("The shell command \"${cmd}\" should not be hidden.");
				$line->explain_warning(
					"Hidden shell commands do not appear on the terminal or in the log file",
					"when they are executed. When they fail, the error message cannot be",
					"assigned to the command, which is very difficult to debug.");
			}
		}

		if ($hidden =~ qr"-") {
			$line->log_warning("The use of a leading \"-\" to suppress errors is deprecated.");
			$line->explain_warning(
				"If you really want to ignore any errors from this command (including",
				"all errors you never thought of), append \"|| \${TRUE}\" to the",
				"command.");
		}
	}

	$state = SCST_START;
	$set_e_mode = false;
	while ($rest =~ s/^$regex_shellword//) {
		my ($shellword) = ($1);

		$opt_debug_shell and $line->log_debug(scst_statename->[$state] . ": ${shellword}");

		checkline_mk_shellword($line, $shellword, !(
		       $state == SCST_CASE
		    || $state == SCST_FOR_CONT
		    || $state == SCST_SET_CONT
		    || ($state == SCST_START && $shellword =~ regex_sh_varassign)));

		#
		# Actions associated with the current state
		# and the symbol on the "input tape".
		#

		if ($state == SCST_START || $state == SCST_COND) {
			my ($type);

			if ($shellword eq "\${RUN}") {
				# Just skip this one.

			} elsif (exists(forbidden_commands->{$shellword})) {
				$line->log_error("${shellword} is forbidden and must not be used.");

			} elsif (exists(get_tool_names()->{$shellword})) {
				if (!exists($mkctx_tools->{$shellword})) {
					$line->log_warning("The \"${shellword}\" tool is used but not added to USE_TOOLS.");
				}

				if (exists(get_required_vartools()->{$shellword})) {
					$line->log_warning("Please use \"\${" . get_vartool_names()->{$shellword} . "}\" instead of \"${shellword}\".");
				}

				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ qr"^\$\{([\w_]+)\}$" && exists(get_varname_to_toolname()->{$1})) {
				my ($vartool) = ($1);
				my $plain_tool = get_varname_to_toolname()->{$vartool};

				if (!exists($mkctx_tools->{$plain_tool})) {
					$line->log_warning("The \"${plain_tool}\" tool is used but not added to USE_TOOLS.");
				}

				if (defined($mkctx_target) && $mkctx_target =~ qr"^(?:pre|do|post)-(?:extract|patch|wrapper|configure|build|install|package|clean)$") {
					if (!exists(get_required_vartool_varnames()->{$vartool})) {
						$opt_warn_extra and $line->log_note("You can write \"${plain_tool}\" instead of \"${shellword}\".");
						$opt_warn_extra and $line->explain_note(
"The wrapper framework from pkgsrc takes care that a sufficiently",
"capable implementation of that tool will be selected.",
"",
"Calling the commands by their plain name instead of the macros is",
"only available in the {pre,do,post}-* targets. For all other targets,",
"you should still use the macros.");
					}
				}

				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ qr"^\$\{([\w_]+)\}$" && defined($type = get_variable_type($line, $1)) && $type->basic_type eq "ShellCommand") {
				checkline_mk_shellcmd_use($line, $shellword);

			} elsif ($shellword =~ qr"^(?:\(|\)|:|;|;;|&&|\|\||\{|\}|break|case|cd|continue|do|done|elif|else|esac|eval|exec|exit|export|fi|for|if|read|set|shift|then|umask|unset|while)$") {
				# Shell builtins are fine.

			} elsif ($shellword =~ qr"^[\w_]+=.*$") {
				# Variable assignment.

			} elsif ($shellword =~ qr"^\./.*$") {
				# All commands from the current directory are fine.

			} elsif ($shellword =~ qr"^#") {
				my $semicolon = ($shellword =~ qr";");
				my $multiline = ($line->lines =~ qr"--");

				if ($semicolon) {
					$line->log_warning("A shell comment should not contain semicolons.");
				}
				if ($multiline) {
					$line->log_warning("A shell comment does not stop at the end of line.");
				}

				if ($semicolon || $multiline) {
					$line->explain_warning(
						"When you split a shell command into multiple lines that are continued",
						"with a backslash, they will nevertheless be converted to a single line",
						"before the shell sees them. That means that even if it _looks_ like that",
						"the comment only spans one line in the Makefile, in fact it spans until",
						"the end of the whole shell command. To insert a comment into shell code,",
						"you can pass it as an argument to the \${SHCOMMENT} macro, which expands",
						"to a command doing nothing. Note that any special characters are",
						"nevertheless interpreted by the shell.");
				}

			} else {
				$opt_warn_extra and $line->log_warning("Unknown shell command \"${shellword}\".");
				$opt_warn_extra and $line->explain_warning(
					"If you want your package to be portable to all platforms that pkgsrc",
					"supports, you should only use shell commands that are covered by the",
					"tools framework.");

			}
		}

		if ($state == SCST_COND && $shellword eq "cd") {
			$line->log_error("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.");
			$line->explain_error(
				"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
				"shell will exit, no matter if it is protected by an \"if\" or the",
				"\"||\" operator.");
		}

		if (($state != SCST_PAX_S && $state != SCST_SED_E && $state != SCST_CASE_LABEL)) {
			checkline_mk_absolute_pathname($line, $shellword);
		}

		if (($state == SCST_INSTALL_D || $state == SCST_MKDIR) && $shellword =~ qr"^\$\{PREFIX(?:|:Q)\}/") {
			$line->log_warning("Please use one of the INSTALL_*_DIR commands instead of "
				. (($state == SCST_MKDIR) ? "\${MKDIR}" : "\${INSTALL} -d")
				. ".");
			$line->explain_warning(
				"Choose one of INSTALL_PROGRAM_DIR, INSTALL_SCRIPT_DIR, INSTALL_LIB_DIR,",
				"INSTALL_MAN_DIR, INSTALL_DATA_DIR.");
		}

		if (($state == SCST_INSTALL_DIR || $state == SCST_INSTALL_DIR2) && $shellword !~ regex_mk_shellvaruse && $shellword =~ qr"^\$\{PREFIX(?:|:Q)\}/(.*)") {
			my ($dirname) = ($1);

			$opt_warn_extra and $line->log_note("You can use INSTALLATION_DIRS+= ${dirname} instead of this command.");
			$opt_warn_extra and $line->explain_note(
				"This saves you some typing. You also don't have to think about which of",
				"the many INSTALL_*_DIR macros is appropriate, since INSTALLATION_DIRS",
				"takes care of that.",
				"",
				"Note that you should only do this if the package creates _all_",
				"directories it needs before trying to install files into them.");
		}

		if ($state == SCST_INSTALL_DIR2 && $shellword =~ qr"^\$") {
			$line->log_warning("The INSTALL_*_DIR commands can only handle one directory at a time.");
			$line->explain_warning(
				"Many implementations of install(1) can handle more, but pkgsrc aims at",
				"maximum portability.");
		}

		if ($state == SCST_PAX && $shellword eq "-pe") {
			$line->log_warning("Please use the -pp option to pax(1) instead of -pe.");
			$line->explain_warning(
				"The -pe option tells pax to preserve the ownership of the files, which",
				"means that the installed files will belong to the user that has built",
				"the package. That's a Bad Thing.");
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

		if ($state == SCST_ECHO && $shellword eq "-n") {
			$line->log_warning("Please use \${ECHO_N} instead of \"echo -n\".");
		}

		if ($opt_warn_extra && $state != SCST_CASE_LABEL_CONT && $shellword eq "|") {
			$line->log_warning("The exitcode of the left-hand-side command of the pipe operator is ignored.");
			$line->explain_warning(
				"If you need to detect the failure of the left-hand-side command, use",
				"temporary files to save the output of the command.");
		}

		if ($opt_warn_extra && $shellword eq ";" && $state != SCST_COND_CONT && $state != SCST_FOR_CONT && !$set_e_mode) {
			$line->log_warning("Please switch to \"set -e\" mode before using a semicolon to separate commands.");
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
		if ($state == SCST_START && $shellword eq "\${RUN}") {
			$set_e_mode = true;
		}

		$state =  ($shellword eq ";;") ? SCST_CASE_LABEL
			# Note: The order of the following two lines is important.
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq "|") ? SCST_CASE_LABEL
			: ($shellword =~ qr"^[;&\|]+$") ? SCST_START
			: ($state == SCST_START) ? (
				  ($shellword eq "\${INSTALL}") ? SCST_INSTALL
				: ($shellword eq "\${MKDIR}") ? SCST_MKDIR
				: ($shellword eq "\${PAX}") ? SCST_PAX
				: ($shellword eq "\${SED}") ? SCST_SED
				: ($shellword eq "\${ECHO}") ? SCST_ECHO
				: ($shellword eq "\${RUN}") ? SCST_START
				: ($shellword eq "echo") ? SCST_ECHO
				: ($shellword eq "set") ? SCST_SET
				: ($shellword =~ qr"^(?:if|elif|while)$") ? SCST_COND
				: ($shellword =~ qr"^(?:then|else|do)$") ? SCST_START
				: ($shellword eq "case") ? SCST_CASE
				: ($shellword eq "for") ? SCST_FOR
				: ($shellword eq "(") ? SCST_START
				: ($shellword =~ qr"^\$\{INSTALL_[A-Z]+_DIR\}$") ? SCST_INSTALL_DIR
				: ($shellword =~ regex_sh_varassign) ? SCST_START
				: SCST_CONT)
			: ($state == SCST_MKDIR) ? SCST_MKDIR
			: ($state == SCST_INSTALL && $shellword eq "-d") ? SCST_INSTALL_D
			: ($state == SCST_INSTALL || $state == SCST_INSTALL_D) ? (
				  ($shellword =~ qr"^-[ogm]$") ? SCST_CONT
				: $state)
			: ($state == SCST_INSTALL_DIR) ? (
				  ($shellword =~ qr"^-") ? SCST_CONT
				: ($shellword =~ qr"^\$") ? SCST_INSTALL_DIR2
				: $state)
			: ($state == SCST_INSTALL_DIR2) ? $state
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
			: ($state == SCST_CASE_LABEL_CONT && $shellword eq ")") ? SCST_START
			: ($state == SCST_CONT) ? SCST_CONT
			: ($state == SCST_COND) ? SCST_COND_CONT
			: ($state == SCST_COND_CONT) ? SCST_COND_CONT
			: ($state == SCST_FOR) ? SCST_FOR_IN
			: ($state == SCST_FOR_IN && $shellword eq "in") ? SCST_FOR_CONT
			: ($state == SCST_FOR_CONT) ? SCST_FOR_CONT
			: ($state == SCST_ECHO) ? SCST_CONT
			: do {
				$line->log_warning("[" . scst_statename->[$state] . " ${shellword}] Keeping the current state.");
				$state;
			};
	}

	if ($rest !~ qr"^\s*$") {
		$line->log_error("Internal pkglint error: " . scst_statename->[$state] . ": rest=${rest}");
	}
}

sub checkline_mk_shellcmd($$) {
	my ($line, $shellcmd) = @_;

	checkline_mk_text($line, $shellcmd);
	checkline_mk_shelltext($line, $shellcmd);
}

sub checkline_mk_vardef($$$) {
	my ($line, $varname, $op) = @_;

	$opt_debug_trace and $line->log_debug("checkline_mk_vardef(${varname}, ${op})");

	# If we are checking a whole package, add it to the package-wide
	# list of defined variables.
	if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{$varname})) {
		$pkgctx_vardef->{$varname} = $line;
	}

	# Add it to the file-wide list of defined variables.
	if (!exists($mkctx_vardef->{$varname})) {
		$mkctx_vardef->{$varname} = $line;
	}

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
			"A \"?\" means that it is not yet clear which permissions are allowed",
			"and which aren't.");
	}
}

sub checkline_mk_vartype_basic($$$$$$$$);
sub checkline_mk_vartype_basic($$$$$$$$) {
	my ($line, $varname, $type, $op, $value, $comment, $list_context, $is_guessed) = @_;
	my ($value_novar);

	$opt_debug_trace and $line->log_debug(sprintf("checkline_mk_vartype_basic(%s, %s, %s, %s, %s, %s, %s)",
	    $varname, $type, $op, $value, defined($comment) ? $comment : "<undef>", $list_context, $is_guessed));

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
		$opt_debug_unchecked and $line->log_debug("Unchecked AWK command: ${value}");

	} elsif ($type eq "BrokenIn") {
		if ($value ne $value_novar) {
			$line->log_error("${varname} must not refer to other variables.");

		} elsif ($value =~ qr"^pkgsrc-(\d\d\d\d)Q(\d)$") {
			my ($year, $quarter) = ($1, $2);

			# Fine.

		} else {
			$line->log_warning("Invalid value \"${value}\" for ${varname}.");
		}
		$line->log_note("Please remove this line if the package builds for you.");

	} elsif ($type eq "BuildlinkDepmethod") {
		# Note: this cannot be replaced with { build full } because
		# enumerations may not contain references to other variables.
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
		my $re_del = qr"\$\{BUILDLINK_PACKAGES:N(?:[+\-.0-9A-Z_a-z]|\$\{[^\}]+\})+\}";
		my $re_add = qr"(?:[+\-.0-9A-Z_a-z]|\$\{[^\}]+\})+";

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
			filesystems finance fonts
			games geography gnome gnustep graphics
			ham
			inputmethod
			japanese java
			kde korean
			lang linux local
			mail math mbone meta-pkgs misc multimedia
			net news
			packages parallel perl5 pkgtools plan9 print python
			ruby
			scm security shells sysutils
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

			# No checks needed, since the macro definitions
			# are usually directory names, which don't need
			# any quoting.

		} elsif ($value =~ qr"^-[DU]([0-9A-Z_a-z]+)") {
			my ($macname) = ($1);

			$opt_debug_unchecked and $line->log_debug("Unchecked macro ${macname} in ${varname}.");

		} elsif ($value =~ qr"^-I(.*)") {
			my ($dirname) = ($1);

			$opt_debug_unchecked and $line->log_debug("Unchecked directory ${dirname} in ${varname}.");

		} elsif ($value eq "-c99") {
			# Only works on IRIX, but is usually enclosed with
			# the proper preprocessor conditional.

		} elsif ($value =~ qr"^-[OWfgm]") {
			$opt_debug_unchecked and $line->log_debug("Unchecked compiler flag ${value} in ${varname}.");

		} elsif ($value =~ qr"^-.*") {
			$line->log_warning("Unknown compiler flag \"${value}\".");

		} elsif ($value =~ regex_unresolved) {
			$opt_debug_unchecked and $line->log_debug("Unchecked CFLAG: ${value}");

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
		if ($value =~ qr"^(${regex_pkgbase})(<|=|>|<=|>=|!=)(${regex_pkgversion})$") {
			my ($depbase, $op, $depversion) = ($1, $2, $3);

		} elsif ($value =~ qr"^(${regex_pkgbase})-(?:\[(.*)\]\*|(\d+(?:\.\d+)*(?:\.\*)?)(\{,nb\*\}|\*|)|(.*))?$") {
			my ($depbase, $bracket, $version, $version_wildcard, $other) = ($1, $2, $3, $4, $5);

			if (defined($bracket)) {
				if ($bracket ne "0-9") {
					$line->log_warning("Only [0-9]* is allowed in the numeric part of a dependency.");
				}

			} elsif (defined($version) && defined($version_wildcard) && $version_wildcard ne "") {
				# Great.

			} elsif (defined($version)) {
				$line->log_warning("Please append {,nb*} to the version number of this dependency.");
				$line->explain_warning(
"Usually, a dependency should stay valid when the PKGREVISION is",
"increased, since those changes are most often editorial. In the",
"current form, the dependency only matches if the PKGREVISION is",
"undefined.");

			} elsif ($other eq "*") {
				$line->log_warning("Please use ${depbase}-[0-9]* instead of ${depbase}-*.");
				$line->explain_warning(
					"If you use a * alone, the package specification may match other",
					"packages that have the same prefix, but a longer name. For example,",
					"foo-* matches foo-1.2, but also foo-client-1.2 and foo-server-1.2.");

			} else {
				$line->log_warning("Unknown dependency pattern \"${value}\".");
			}

		} elsif ($value =~ qr"\{") {
			# Dependency patterns containing alternatives
			# are just too hard to check.
			$opt_debug_unchecked and $line->log_debug("Unchecked dependency pattern: ${value}");

		} elsif ($value ne $value_novar) {
			$opt_debug_unchecked and $line->log_debug("Unchecked dependency: ${value}");

		} else {
			$line->log_warning("Unknown dependency format: ${value}");
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
		if ($value_novar =~ qr"/") {
			$line->log_warning("A filename should not contain a slash.");

		} elsif ($value_novar !~ qr"^[-0-9\@A-Za-z.,_~+%]*$") {
			$line->log_warning("\"${value}\" is not a valid filename.");
		}

	} elsif ($type eq "Filemask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?]*$") {
			$line->log_warning("\"${value}\" is not a valid filename mask.");
		}

	} elsif ($type eq "FileMode") {
		if ($value ne "" && $value_novar eq "") {
			# Fine.
		} elsif ($value =~ qr"^[0-7]{3,4}") {
			# Fine.
		} else {
			$line->log_warning("Invalid file mode ${value}.");
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

			$opt_debug_unchecked and $line->log_debug("Unchecked directory ${dirname} in ${varname}.");

		} elsif ($value =~ qr"^-l(.*)") {
			my ($libname) = ($1);

			$opt_debug_unchecked and $line->log_debug("Unchecked library name ${libname} in ${varname}.");

		} elsif ($value =~ qr"^(?:-static)$") {
			# Assume that the wrapper framework catches these.

		} elsif ($value =~ qr"^(-Wl,(?:-R|-rpath|--rpath))") {
			my ($rpath_flag) = ($1);
			$line->log_warning("Please use \${COMPILER_RPATH_FLAG} instead of ${rpath_flag}.");

		} elsif ($value =~ qr"^-.*") {
			$line->log_warning("Unknown linker flag \"${value}\".");

		} elsif ($value =~ regex_unresolved) {
			$opt_debug_unchecked and $line->log_debug("Unchecked LDFLAG: ${value}");

		} else {
			$line->log_warning("Linker flag \"${value}\" does not start with a dash.");
		}

	} elsif ($type eq "License") {

		use constant deprecated_licenses => array_to_hash(qw(
			fee-based-commercial-use
			no-commercial-use no-profit no-redistribution
			shareware
		));

		my $license_file = "${cwd_pkgsrcdir}/licenses/${value}";
		if (defined($pkgctx_vardef) && exists($pkgctx_vardef->{"LICENSE_FILE"})) {
			my $license_file_line = $pkgctx_vardef->{"LICENSE_FILE"};

			$license_file = "${current_dir}/" . resolve_relative_path($license_file_line->get("value"), false);
		}
		if (!-f $license_file) {
			$line->log_warning("License file ".normalize_pathname($license_file)." does not exist.");
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
			if ("${localpart}\@${domain}" =~ qr"^(tech-pkg|packages)\@NetBSD\.org$"i) {
				$line->log_warning("${localpart}\@${domain} is deprecated. Use pkgsrc-users\@NetBSD.org instead.");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid mail address.");
		}

	} elsif ($type eq "Message") {
		if ($value =~ qr"^[\"'].*[\"']$") {
			$line->log_warning("${varname} should not be quoted.");
			$line->explain_warning(
"The quoting is only needed for variables which are interpreted as",
"multiple words (or, generally speaking, a list of something). A single",
"text message does not belong to this class, since it is only printed",
"as a whole.",
"",
"On the other hand, PKG_FAIL_REASON is a _list_ of text messages, so in",
"that case, the quoting has to be done.");
		}

	} elsif ($type eq "Option") {
		if ($value ne $value_novar) {
			$opt_debug_unchecked and $line->log_debug("Unchecked option name \"${value}\".");

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

		if ($value !~ qr":" && $is_guessed) {
			checkline_mk_vartype_basic($line, $varname, "Pathname", $op, $value, $comment, $list_context, $is_guessed);

		} else {

			# XXX: The splitting will fail if $value contains any
			# variables with modifiers, for example :Q or :S/././.
			foreach my $p (split(qr":", $value)) {
				my $p_novar = remove_variables($p);

				if ($p_novar !~ qr"^[-0-9A-Za-z._~+%/]*$") {
					$line->log_warning("\"${p}\" is not a valid pathname.");
				}

				if ($p !~ qr"^[\$/]") {
					$line->log_warning("All components of ${varname} (in this case \"${p}\") should be an absolute path.");
				}
			}
		}

	} elsif ($type eq "Pathmask") {
		if ($value_novar !~ qr"^[#\-0-9A-Za-z._~+%*?/\[\]]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname mask.");
		}
		checkline_mk_absolute_pathname($line, $value);

	} elsif ($type eq "Pathname") {
		if ($value_novar !~ qr"^[#\-0-9A-Za-z._~+%/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname.");
		}
		checkline_mk_absolute_pathname($line, $value);

	} elsif ($type eq "Perl5Packlist") {
		if ($value ne $value_novar) {
			$line->log_warning("${varname} should not depend on other variables.");
		}

	} elsif ($type eq "PkgName") {
		if ($value eq $value_novar && $value !~ regex_pkgname) {
			$line->log_warning("\"${value}\" is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.");
		}

	} elsif ($type eq "PkgOptionsVar") {
		checkline_mk_vartype_basic($line, $varname, "Varname", $op, $value, $comment, false, $is_guessed);
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

			if ($opsys !~ qr"^(?:\*|BSDOS|Darwin|DragonFly|FreeBSD|HPUX|Interix|IRIX|Linux|NetBSD|OpenBSD|OSF1|SunOS)$") {
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

	} elsif ($type eq "PrefixPathname") {
		if ($value =~ qr"^man/(.*)") {
			my ($mansubdir) = ($1);

			$line->log_warning("Please use \"\${PKGMANDIR}/${mansubdir}\" instead of \"${value}\".");
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

	} elsif ($type eq "SedCommand") {
		

	} elsif ($type eq "SedCommands") {
		my $words = shell_split($value);
		if (!$words) {
			$line->log_error("Invalid shell words in sed commands.");
			$line->explain_error(
				"If your sed commands have embedded \"#\" characters, you need to escape",
				"them with a backslash, otherwise make(1) will interpret them as a",
				"comment, no matter if they occur in single or double quotes or",
				"whatever.");

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
							$line->explain_warning(
								"For example, instead of",
								"    SUBST_SED.foo+=        -e s,command1,, -e s,command2,,",
								"use",
								"    SUBST_SED.foo+=        -e s,command1,,",
								"    SUBST_SED.foo+=        -e s,command2,,",
								"",
								"This way, short sed commands cannot be hidden at the end of a line.");
						}
						checkline_mk_shellword($line, $words->[$i - 1], true);
						checkline_mk_shellword($line, $words->[$i], true);
						checkline_mk_vartype_basic($line, $varname, "SedCommand", $op, $words->[$i], $comment, $list_context, $is_guessed);
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
			if (defined($tooldep) && $tooldep !~ qr"^(?:bootstrap|build|pkgsrc|run)$") {
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

		} elsif ($value =~ qr"\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$") {
			my ($name, $subdir) = ($1, $2);

			if (!exists(get_dist_sites_names()->{$name})) {
				$line->log_error("${name} does not exist.");
			}
			if ($subdir !~ qr"/$") {
				$line->log_error("The subdirectory in ${name} must end with a slash.");
			}

		} elsif ($value =~ regex_unresolved) {
			# No further checks

		} elsif ($value =~ qr"^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:=?\@A-Z_a-z~]|#)*$") {
			my ($proto, $host, $port, $path) = ($1, $2, $3, $4);
			my $sites = get_dist_sites();

			if ($host =~ qr"\.NetBSD\.org$"i && $host !~ qr"\.NetBSD\.org$") {
				$line->log_warning("Please write NetBSD.org instead of ${host}.");
			}

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
			$line->log_warning("Unknown wrapper reorder command \"${value}\".");
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
			$line->log_warning("Unknown wrapper transform command \"${value}\".");
		}

	} elsif ($type eq "WrkdirSubdirectory") {
		checkline_mk_vartype_basic($line, $varname, "Pathname", $op, $value, $comment, $list_context, $is_guessed);
		if ($value eq "\${WRKDIR}") {
			# Fine.
		} else {
			$opt_debug_unchecked and $line->log_debug("Unchecked subdirectory \"${value}\" of \${WRKDIR}.");
		}

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
			$line->explain_warning(
				"This variable means \"yes\" if it is defined, and \"no\" if it is",
				"undefined. Even when it has the value \"no\", this means \"yes\".",
				"Therefore when it is defined, its value should correspond to its",
				"meaning.");
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

# Checks whether the list of version numbers that are given as the
# C<value> of the variable C<varname> are in decreasing order.
sub checkline_decreasing_order($$$) {
	my ($line, $varname, $value) = @_;

	my @pyver = split(qr"\s+", $value);
	if (!@pyver) {
		$line->log_error("There must be at least one value for ${varname}.");
		return;
	}

	my $ver = shift(@pyver);
	if ($ver !~ qr"^\d+$") {
		$line->log_error("All values for ${varname} must be numeric.");
		return;
	}

	while (@pyver) {
		my $nextver = shift(@pyver);
		if ($nextver !~ qr"^\d+$") {
			$line->log_error("All values for ${varname} must be numeric.");
			return;
		}

		if ($nextver >= $ver) {
			$line->log_warning("The values for ${varname} should be in decreasing order.");
			$line->explain_warning(
				"If they aren't, it may be possible that needless versions of packages",
				"are installed.");
		}
		$ver = $nextver;
	}
}

sub checkline_mk_vartype($$$$$) {
	my ($line, $varname, $op, $value, $comment) = @_;

	return unless $opt_warn_types;

	my $vartypes = get_vartypes_map();
	my $varbase = varname_base($varname);
	my $varcanon = varname_canon($varname);

	my $type = get_variable_type($line, $varname);

	if ($op eq "+=") {
		if (defined($type)) {
			if (!$type->may_use_plus_eq()) {
				$line->log_warning("The \"+=\" operator should only be used with lists.");
			}
		} elsif ($varbase !~ qr"^_" && $varbase !~ get_regex_plurals()) {
			$line->log_warning("As ${varname} is modified using \"+=\", its name should indicate plural.");
		}
	}

	if (!defined($type)) {
		# Cannot check anything if the type is not known.
		$opt_debug_unchecked and $line->log_debug("Unchecked variable assignment for ${varname}.");

	} elsif ($op eq "!=") {
		$opt_debug_misc and $line->log_debug("Use of !=: ${value}");

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
			checkline_mk_vartype_basic($line, $varname, $type->basic_type, $op, $word, $comment, true, $type->is_guessed);
			if ($type->kind_of_list != LK_INTERNAL) {
				checkline_mk_shellword($line, $word, true);
			}
		}

		if ($rest !~ qr"^\s*$") {
			$line->log_error("Internal pkglint error: rest=${rest}");
		}

	} else {
		checkline_mk_vartype_basic($line, $varname, $type->basic_type, $op, $value, $comment, $type->is_practically_a_list(), $type->is_guessed);
	}
}

sub checkline_mk_varassign($$$$$) {
	my ($line, $varname, $op, $value, $comment) = @_;
	my ($used_vars);
	my $varbase = varname_base($varname);
	my $varcanon = varname_canon($varname);

	$opt_debug_trace and $line->log_debug("checkline_mk_varassign($varname, $op, $value)");

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
	if (!var_is_used($varname)) {
		my $vartypes = get_vartypes_map();
		my $deprecated = get_deprecated_map();

		if (exists($vartypes->{$varname}) || exists($vartypes->{$varcanon})) {
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

	if ($varname eq "CONFIGURE_ARGS" && $value =~ qr"=\$\{PREFIX\}/share/kde") {
		$line->log_note("Please .include \"../../meta-pkgs/kde3/kde3.mk\" instead of this line.");
		$line->explain_note(
			"That file probably does many things automatically and consistently that",
			"this package also does. When using kde3.mk, you can probably also leave",
			"out some explicit dependencies.");
	}

	if ($varname eq "EVAL_PREFIX" && $value =~ qr"^([\w_]+)=") {
		my ($eval_varname) = ($1);

		# This assignment will define the variable named
		# $eval_varname. It is marked as known in the current
		# file.
		$mkctx_vardef->{$eval_varname} = $line;
	}

	if ($varname eq "PYTHON_VERSIONS_ACCEPTED") {
		checkline_decreasing_order($line, $varname, $value);
	}

	if (defined($comment) && $comment eq "# defined" && $varname !~ qr".*(?:_MK|_COMMON)$") {
		$line->log_note("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
		$line->explain_note(
			"The value #defined says something about the state of the variable, but",
			"not what that _means_. In some cases a variable that is defined means",
			"\"yes\", in other cases it is an empty list (which is also only the",
			"state of the variable), whose meaning could be described with \"none\".",
			"It is this meaning that should be described.");
	}

	if ($value =~ qr"\$\{(PKGNAME|PKGVERSION)[:\}]") {
		my ($pkgvarname) = ($1);
		if ($varname =~ qr"^PKG_.*_REASON$") {
			# ok
		} elsif ($varname =~ qr"^(?:DIST_SUBDIR|WRKSRC)$") {
			$line->log_warning("${pkgvarname} should not be used in ${varname}, as it sometimes includes the PKGREVISION. Please use ${pkgvarname}_NOREV instead.");
		} else {
			$opt_debug_misc and $line->log_debug("Use of PKGNAME in ${varname}.");
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

	# Mark the variable as PLIST condition. This is later used in
	# checkfile_PLIST.
	if (defined($pkgctx_plist_subst_cond) && $value =~ qr"(.+)=.*\@comment.*") {
		$pkgctx_plist_subst_cond->{$1}++;
	}

	use constant op_to_use_time => {
		":="	=> VUC_TIME_LOAD,
		"!="	=> VUC_TIME_LOAD,
		"="	=> VUC_TIME_RUN,
		"+="	=> VUC_TIME_RUN,
		"?="	=> VUC_TIME_RUN
	};
	
	$used_vars = extract_used_variables($line, $value);
	my $vuc = PkgLint::VarUseContext->new(
		op_to_use_time->{$op},
		get_variable_type($line, $varname),
		VUC_SHELLWORD_UNKNOWN,		# XXX: maybe PLAIN?
		VUC_EXTENT_UNKNOWN
	);
	foreach my $used_var (@{$used_vars}) {
		checkline_mk_varuse($line, $used_var, "", $vuc);
	}
}

# The bmake parser is way too sloppy about syntax, so we need to check
# that here.
#
sub checkline_mk_cond($$) {
	my ($line, $cond) = @_;

	$opt_debug_trace and $line->log_debug("checkline_mk_cond($cond)");
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

	use enum qw(once optional many);
	my (@sections) = (
		[ "Initial comments", once,
			[
			]
		],
		[ "Unsorted stuff, part 1", once,
			[
				[ "DISTNAME", once ],
				[ "PKGNAME",  optional ],
				[ "PKGREVISION", optional ],
				[ "SVR4_PKGNAME", optional ],
				[ "CATEGORIES", once ],
				[ "MASTER_SITES", once ],
				[ "DIST_SUBDIR", optional ],
				[ "EXTRACT_SUFX", optional ],
				[ "DISTFILES", many ],
				[ "SITES.*", many ],
			]
		],
		[ "Distribution patches", optional,
			[
				[ "PATCH_SITES", optional ], # or once?
				[ "PATCH_SITE_SUBDIR", optional ],
				[ "PATCHFILES", optional ], # or once?
				[ "PATCH_DIST_ARGS", optional ],
				[ "PATCH_DIST_STRIP", optional ],
				[ "PATCH_DIST_CAT", optional ],
			]
		],
		[ "Unsorted stuff, part 2", once,
			[
				[ "MAINTAINER", once ],
				[ "HOMEPAGE", optional ],
				[ "COMMENT", once ],
			]
		],
		[ "Legal issues", optional,
			[
				[ "LICENSE", once ],
				[ "RESTRICTED", optional ],
				[ "NO_BIN_ON_CDROM", optional ],
				[ "NO_BIN_ON_FTP", optional ],
				[ "NO_SRC_ON_CDROM", optional ],
				[ "NO_SRC_ON_FTP", optional ],
			]
		],
		[ "Technical restrictions", optional,
			[
				[ "NOT_FOR_PLATFORM", many ],
				[ "ONLY_FOR_PLATFORM", many ],
				[ "NOT_FOR_COMPILER", many ],
				[ "ONLY_FOR_COMPILER", many ],
				[ "NOT_FOR_UNPRIVILEGED", optional ],
				[ "ONLY_FOR_UNPRIVILEGED", optional ],
			]
		],
		[ "Dependencies", optional,
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

	# If the current section is optional but contains non-optional
	# fields, the complete section may be skipped as long as there
	# has not been a non-optional variable.
	my $may_skip_section = false;

	# In each iteration, one of the following becomes true:
	# - new.lineno > old.lineno
	# - new.sectindex > old.sectindex
	# - new.sectindex == old.sectindex && new.varindex > old.varindex
	# - new.next_section == true && old.next_section == false
	while ($lineno <= $#{$lines}) {
		my $line = $lines->[$lineno];
		my $text = $line->text;

		$opt_debug_misc and $line->log_debug("[varorder] section ${sectindex} variable ${varindex}.");

		if ($next_section) {
			$next_section = false;
			$sectindex++;
			last if ($sectindex > $#sections);
			$vars = $sections[$sectindex]->[2];
			$may_skip_section = ($sections[$sectindex]->[1] == optional);
			$varindex = 0;
		}

		if ($text =~ qr"^#") {
			$lineno++;

		} elsif ($line->has("varcanon")) {
			my $varcanon = $line->get("varcanon");

			if (exists($below->{$varcanon})) {
				if (defined($below->{$varcanon})) {
					$line->log_warning("${varcanon} appears too late. Please put it below $below->{$varcanon}.");
				} else {
					$line->log_warning("${varcanon} appears too late. It should be the very first definition.");
				}
				$lineno++;
				next;
			}

			while ($varindex <= $#{$vars} && $varcanon ne $vars->[$varindex]->[0] && ($vars->[$varindex]->[1] != once || $may_skip_section)) {
				if ($vars->[$varindex]->[1] == once) {
					$may_skip_section = false;
				}
				$below->{$vars->[$varindex]->[0]} = $below_what;
				$varindex++;
			}
			if ($varindex > $#{$vars}) {
				if ($sections[$sectindex]->[1] != optional) {
					$line->log_warning("Empty line expected.");
				}
				$next_section = true;

			} elsif ($varcanon ne $vars->[$varindex]->[0]) {
				$line->log_warning("Expected " . $vars->[$varindex]->[0] . ", but found " . $varcanon . ".");
				$lineno++;

			} else {
				if ($vars->[$varindex]->[1] != many) {
					$below->{$vars->[$varindex]->[0]} = $below_what;
					$varindex++;
				}
				$lineno++;
			}
			$below_what = $varcanon;

		} else {
			while ($varindex <= $#{$vars}) {
				if ($vars->[$varindex]->[1] == once && !$may_skip_section) {
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
	my ($allowed_targets) = ({});
	my ($substcontext) = PkgLint::SubstContext->new();

	assert(@{$lines} != 0, "checklines_mk may only be called with non-empty lines.");
	$opt_debug_trace and log_debug($lines->[0]->fname, NO_LINES, "checklines_mk()");

	# Define global variables for the Makefile context.
	$mkctx_indentations = [0];
	$mkctx_target = undef;
	$mkctx_for_variables = {};
	$mkctx_vardef = {};
	$mkctx_build_defs = {};
	$mkctx_tools = {%{get_predefined_tool_names()}};
	$mkctx_varuse = {};

	determine_used_variables($lines);

	foreach my $prefix (qw(pre do post)) {
		foreach my $action (qw(fetch extract patch tools wrapper configure build test install package clean)) {
			$allowed_targets->{"${prefix}-${action}"} = true;
		}
	}

	#
	# In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	# are collected to make the order of the definitions irrelevant.
	#

	foreach my $line (@{$lines}) {
		next unless $line->has("is_varassign");
		my $varcanon = $line->get("varcanon");

		if ($varcanon eq "BUILD_DEFS" || $varcanon eq "PKG_GROUPS_VARS" || $varcanon eq "PKG_USERS_VARS") {
			foreach my $varname (split(qr"\s+", $line->get("value"))) {
				$mkctx_build_defs->{$varname} = true;
				$opt_debug_misc and $line->log_debug("${varname} is added to BUILD_DEFS.");
			}

		} elsif ($varcanon eq "USE_TOOLS") {
			foreach my $tool (split(qr"\s+", $line->get("value"))) {
				$mkctx_tools->{$tool} = true;
				$opt_debug_misc and $line->log_debug("${tool} is added to USE_TOOLS.");
			}

		} elsif ($varcanon eq "SUBST_VARS.*") {
			foreach my $svar (split(/\s+/, $line->get("value"))) {
				use_var($svar, varname_canon($svar));
				$opt_debug_misc and $line->log_debug("varuse $svar");
			}
		}
	}

	#
	# In the second pass, all "normal" checks are done.
	#

	if (0 <= $#{$lines}) {
		checkline_rcsid_regex($lines->[0], qr"^#\s+", "# ");
	}

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);
		checkline_spellcheck($line);

		if ($line->has("is_empty")) {
			$substcontext->check_end($line);

		} elsif ($line->has("is_comment")) {
			# No further checks.

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, undef, $comment) = ($1, $2, $3, $4);
			my $space1 = substr($text, $+[1], $-[2] - $+[1]);
			my $align = substr($text, $+[2], $-[3] - $+[2]);
			my $value = $line->get("value");

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
			$substcontext->check_varassign($line, $varname, $op, $value);

		} elsif ($text =~ regex_mk_shellcmd) {
			my ($shellcmd) = ($1);
			checkline_mk_shellcmd($line, $shellcmd);

		} elsif ($text =~ regex_mk_include) {
			my ($includefile) = ($1);

			$opt_debug_include and $line->log_debug("includefile=${includefile}");
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
				if ($line->fname =~ qr"buildlink3\.mk$") {
					$line->log_note("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.");
				}
				$seen_bsd_prefs_mk = true;
			} elsif ($includefile eq "../../mk/bsd.fast.prefs.mk") {
				$seen_bsd_prefs_mk = true;
			}

			if ($includefile =~ qr"/x11-links/buildlink3\.mk$") {
				$line->log_error("${includefile} must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.");
			}
			if ($includefile =~ qr"/intltool/buildlink3\.mk$") {
				$line->log_warning("Please say \"USE_TOOLS+= intltool\" instead of this line.");
			}
			if ($includefile =~ qr"(.*)/builtin\.mk$") {
				my ($dir) = ($1);
				$line->log_error("${includefile} must not be included directly. Include \"${dir}/buildlink3.mk\" instead.");
			}

		} elsif ($text =~ regex_mk_sysinclude) {
			my ($includefile, $comment) = ($1, $2);

			# No further action.

		} elsif ($text =~ regex_mk_cond) {
			my ($indent, $directive, $args, $comment) = ($1, $2, $3, $4);

			use constant regex_directives_with_args => qr"^(?:if|ifdef|ifndef|elif|for|undef)$";

			if ($directive =~ qr"^(?:endif|endfor|elif|else)$") {
				if ($#{$mkctx_indentations} >= 1) {
					pop(@{$mkctx_indentations});
				} else {
					$line->log_error("Unmatched .${directive}.");
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
				checkline_mk_cond($line, $args);

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

						$mkctx_for_variables->{$var} = true;
					}

					# Check if any of the value's types is not guessed.
					my $guessed = true;
					foreach my $value (split(qr"\s+", $values)) { # XXX: too simple
						if ($value =~ qr"^\$\{(.*)\}") {
							my $type = get_variable_type($line, $1);
							if (defined($type) && !$type->is_guessed()) {
								$guessed = false;
							}
						}
					}

					my $for_loop_type = PkgLint::Type->new(
						LK_INTERNAL,
						"Unchecked",
						[[qr".*", "pu"]],
						$guessed
					);
					my $for_loop_context = PkgLint::VarUseContext->new(
						VUC_TIME_LOAD,
						$for_loop_type,
						VUC_SHELLWORD_FOR,
						VUC_EXTENT_WORD
					);
					foreach my $var (@{extract_used_variables($line, $values)}) {
						checkline_mk_varuse($line, $var, "", $for_loop_context);
					}

				}

			} elsif ($directive eq "undef" && defined($args)) {
				foreach my $var (split(qr"\s+", $args)) {
					if (exists($mkctx_for_variables->{$var})) {
						$line->log_note("Using \".undef\" after a \".for\" loop is unnecessary.");
					}
				}
			}

		} elsif ($text =~ regex_mk_dependency) {
			my ($targets, $dependencies) = ($1, $2);

			$opt_debug_misc and $line->log_debug("targets=${targets}, dependencies=${dependencies}");
			$mkctx_target = $targets;

			foreach my $source (split(/\s+/, $dependencies)) {
				if ($source eq ".PHONY") {
					foreach my $target (split(/\s+/, $targets)) {
						$allowed_targets->{$target} = true;
					}
				}
			}

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
	if (@{$lines} > 0) {
		$substcontext->check_end($lines->[-1]);
	}

	checklines_trailing_empty_lines($lines);

	if ($#{$mkctx_indentations} != 0) {
		$lines->[-1]->log_error("Directive indentation is not 0, but ".$mkctx_indentations->[-1]." at EOF.");
	}

	# Clean up global variables.
	$mkctx_for_variables = undef;
	$mkctx_indentations = undef;
	$mkctx_target = undef;
	$mkctx_vardef = undef;
	$mkctx_build_defs = undef;
	$mkctx_tools = undef;
	$mkctx_varuse = undef;
}

sub checklines_buildlink3_inclusion($) {
	my ($lines) = @_;
	my ($included_files);

	assert(@{$lines} != 0, "The lines array must be non-empty.");
	$opt_debug_trace and log_debug($lines->[0]->fname, NO_LINES, "checklines_buildlink3_inclusion()");

	if (!defined($pkgctx_bl3)) {
		return;
	}

	# Collect all the included buildlink3.mk files from the file.
	$included_files = {};
	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_mk_include) {
			my ($file, $comment) = ($1, $2);

			if ($file =~ qr"^\.\./\.\./(.*)/buildlink3\.mk") {
				my ($bl3) = ($1);

				$included_files->{$bl3} = $line;
				if (!exists($pkgctx_bl3->{$bl3})) {
					$line->log_warning("${bl3}/buildlink3.mk is included by this file but not by the package.");
				}
			}
		}
	}

	# Print debugging messages for all buildlink3.mk files that are
	# included by the package but not by this buildlink3.mk file.
	foreach my $package_bl3 (sort(keys(%{$pkgctx_bl3}))) {
		if (!exists($included_files->{$package_bl3})) {
			$opt_debug_misc and $pkgctx_bl3->{$package_bl3}->log_debug("${package_bl3}/buildlink3.mk is included by the package but not by the buildlink3.mk file.");
		}
	}
}

#
# Procedures to check a single file.
#

sub checkfile_ALTERNATIVES($) {
	my ($fname) = @_;
	my ($lines);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_ALTERNATIVES()");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_buildlink3_mk($) {
	my ($fname) = @_;
	my ($lines, $lineno, $m);
	my ($bl_PKGBASE_line, $bl_PKGBASE);
	my ($bl_pkgbase_line, $bl_pkgbase);
	my ($abi_line, $abi_pkg, $abi_version);
	my ($api_line, $api_pkg, $api_version);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_buildlink3_mk()");

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINES, "Must not be empty.");
		return;
	}

	parselines_mk($lines);
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
		lines_log_warning($lines, $lineno, "Expected BUILDLINK_DEPTH:= \${BUILDLINK_DEPTH}+.");
		return;
	}
	if (($m = expect($lines, \$lineno, qr"^(.*)_BUILDLINK3_MK:=\t+\$\{\1_BUILDLINK3_MK\}\+$"))) {
		$bl_PKGBASE_line = $lines->[$lineno - 1];
		$bl_PKGBASE = $m->text(1);
		$opt_debug_misc and $bl_PKGBASE_line->log_debug("bl_PKGBASE=${bl_PKGBASE}");
	} else {
		lines_log_warning($lines, $lineno, "Expected {PKGNAME}_BUILDLINK3_MK:= \${{PKGNAME}_BUILDLINK3_MK}+.");
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
		$bl_pkgbase_line = $lines->[$lineno - 1];
		$bl_pkgbase = $m->text(1);
		$opt_debug_misc and $bl_pkgbase_line->log_debug("bl_pkgbase=${bl_pkgbase}");
	} else {
		lines_log_warning($lines, $lineno, "BUILDLINK_DEPENDS line expected.");
		return;
	}

	my $norm_bl_pkgbase = $bl_pkgbase;
	$norm_bl_pkgbase =~ s/-/_/g;
	$norm_bl_pkgbase = uc($norm_bl_pkgbase);
	if ($norm_bl_pkgbase ne $bl_PKGBASE) {
		$bl_PKGBASE_line->log_error("Package name mismatch between ${bl_PKGBASE} ...");
		$bl_pkgbase_line->log_error("... and ${bl_pkgbase}.");
	}
	if (defined($effective_pkgbase) && $effective_pkgbase ne $bl_pkgbase) {
		$bl_pkgbase_line->log_error("Package name mismatch between ${bl_pkgbase} ...");
		$effective_pkgname_line->log_error("... and ${effective_pkgbase}.");
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
			lines_log_warning($lines, $lineno, "Expected BUILDLINK_PACKAGES:= \${BUILDLINK_PACKAGES:N${bl_pkgbase}} line.");
			return;
		}
		if (!expect($lines, \$lineno, qr"^BUILDLINK_PACKAGES\+=\t+\Q${bl_pkgbase}\E$")) {
			lines_log_warning($lines, $lineno, "Expected BUILDLINK_PACKAGES+= ${bl_pkgbase} line.");
			return;
		}
	}
	expect_text($lines, \$lineno, "BUILDLINK_ORDER:=\t\${BUILDLINK_ORDER} \${BUILDLINK_DEPTH}${bl_pkgbase}");
	expect_empty_line($lines, \$lineno);

	# Fourth paragraph: Package information.
	if (!expect($lines, \$lineno, qr"^\.if !empty\(\Q${bl_PKGBASE}\E_BUILDLINK3_MK:M\+\)$")) {
		if (!expect_text($lines, \$lineno, ".if \${${bl_PKGBASE}_BUILDLINK3_MK} == \"+\"")) {
			return;
		}
	}
	while (!expect($lines, \$lineno, qr"^\.endif.*$")) {

		if ($lineno > $#{$lines}) {
			lines_log_warning($lines, $lineno, "Expected .endif");
			return;
		}

		my $line = $lines->[$lineno];

		if (($m = expect($lines, \$lineno, regex_varassign))) {
			my ($varname, $value) = ($m->text(1), $m->text(3));
			my $do_check = false;

			if ($varname eq "BUILDLINK_ABI_DEPENDS.${bl_pkgbase}") {
				$abi_line = $line;
				if ($value =~ regex_dependency_gt) {
					($abi_pkg, $abi_version) = ($1, $2);
				} elsif ($value =~ regex_dependency_wildcard) {
					($abi_pkg) = ($1);
				} else {
					$opt_debug_unchecked and $line->log_debug("Unchecked dependency pattern \"${value}\".");
				}
				$do_check = true;
			}
			if ($varname eq "BUILDLINK_API_DEPENDS.${bl_pkgbase}") {
				$api_line = $line;
				if ($value =~ regex_dependency_gt) {
					($api_pkg, $api_version) = ($1, $2);
				} elsif ($value =~ regex_dependency_wildcard) {
					($api_pkg) = ($1);
				} else {
					$opt_debug_unchecked and $line->log_debug("Unchecked dependency pattern \"${value}\".");
				}
				$do_check = true;
			}
			if ($do_check && defined($abi_pkg) && defined($api_pkg)) {
				if ($abi_pkg ne $api_pkg) {
					$abi_line->log_warning("Package name mismatch between ${abi_pkg} ...");
					$api_line->log_warning("... and ${api_pkg}.");
				}
			}
			if ($do_check && defined($abi_version) && defined($api_version)) {
				if (!dewey_cmp($abi_version, ">=", $api_version)) {
					$abi_line->log_warning("ABI version (${abi_version}) should be at least ...");
					$api_line->log_warning("... API version (${api_version}).");
				}
			}

			if ($varname =~ qr"^BUILDLINK_[\w_]+\.(.*)$") {
				my ($varparam) = ($1);

				if ($varparam ne $bl_pkgbase) {
					$line->log_warning("Only buildlink variables for ${bl_pkgbase}, not ${varparam} may be set in this file.");
				}
			}

			# TODO: More checks.

		} elsif (expect($lines, \$lineno, qr"^(?:#.*)?$")) {
			# Comments and empty lines are fine here.

		} else {
			$opt_debug_unchecked and lines_log_warning($lines, $lineno, "Unchecked line in fourth paragraph.");
			$lineno++;
		}
	}
	if (!defined($api_line)) {
		$lines->[$lineno - 1]->log_warning("Definition of BUILDLINK_API_DEPENDS is missing.");
	}
	expect_empty_line($lines, \$lineno);

	# Fifth paragraph (optional): Dependencies.
	my $have_dependencies = false;
	my $need_empty_line = false;
	while (true) {
		if (expect($lines, \$lineno, qr"^\.\s*include \"\.\./\.\./([^/]+/[^/]+)/buildlink3\.mk\"$")
		 || expect($lines, \$lineno, qr"^\.\s*include \"\.\./\.\./mk/(\S+)\.buildlink3\.mk\"$")
		 || expect($lines, \$lineno, qr"^\.if !empty\(PKG_BUILD_OPTIONS\.\Q${bl_pkgbase}\E:M\S+\)$")
		 || expect($lines, \$lineno, qr"^\.endif$")) {
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
		lines_log_warning($lines, $lineno, "Expected BUILDLINK_DEPTH:= \${BUILDLINK_DEPTH:S/+\$//}.");
		explain_warning($lines, $lineno,
			"Everything besides the .include lines for the buildlink3.mk files of",
			"dependencies should go between the .if !empty({PKGNAME}_BUILDLINK3_MK)",
			"and the corresponding .endif.");
		return;
	}

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_warning("The file should end here.");
	}

	checklines_buildlink3_inclusion($lines);
}

sub checkfile_DESCR($) {
	my ($fname) = @_;
	my ($maxchars, $maxlines) = (80, 24);
	my ($lines);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_DESCR()");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	foreach my $line (@{$lines}) {
		checkline_length($line, $maxchars);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, regex_validchars);
		checkline_spellcheck($line);
		if ($line->text =~ qr"\$\{") {
			$line->log_warning("Variables are not expanded in the DESCR file.");
		}
	}
	checklines_trailing_empty_lines($lines);

	if (@{$lines} > $maxlines) {
		my $line = $lines->[$maxlines];

		$line->log_warning("File too long (should be no more than $maxlines lines).");
		$line->explain_warning(
			"A common terminal size is 80x25 characters. The DESCR file should",
			"fit on one screen. It is also intended to give a _brief_ summary",
			"about the package's contents.");
	}
	autofix($lines);
}

sub checkfile_distinfo($) {
	my ($fname) = @_;
	my ($lines, %in_distinfo, $current_fname, $state, $patches_dir);
	my ($di_is_committed);

	use enum qw(:DIS_ start=0 SHA1=0 RMD160 Size);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_distinfo()");

	$di_is_committed = is_committed($fname);

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

	$patches_dir = $patchdir;
	if (!defined($patches_dir) && -d "${current_dir}/patches") {
		$patches_dir = "patches";
	} else {
		# it stays undefined.
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

		if ($chksum_fname !~ qr"^\w") {
			$line->log_error("All file names should start with a letter.");
		}

		# Inter-package check for differing distfile checksums.
		if ($opt_check_global && !$is_patch) {
			# Note: Perl-specific auto-population.
			if (exists($ipc_distinfo->{$alg}->{$chksum_fname})) {
				my $other = $ipc_distinfo->{$alg}->{$chksum_fname};

				if ($other->[1] eq $sum) {
					# Fine.
				} else {
					$line->log_error("The ${alg} checksum for ${chksum_fname} differs ...");
					$other->[0]->log_error("... from this one.");
				}
			} else {
				$ipc_distinfo->{$alg}->{$chksum_fname} = [$line, $sum];
			}
		}

		if ($alg eq "MD5") {
			$line->log_error("MD5 checksums are obsolete.");
			$line->explain_error(
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

		if ($is_patch && defined($patches_dir) && !(defined($distinfo_file) && $distinfo_file eq "./../../lang/php5/distinfo")) {
			my $fname = "${current_dir}/${patches_dir}/${chksum_fname}";
			if ($di_is_committed && !is_committed($fname)) {
				$line->log_warning("${patches_dir}/${chksum_fname} is registered in distinfo but not added to CVS.");
			}

			if (open(PATCH, "<", $fname)) {
				my $data = "";
				foreach my $patchline (<PATCH>) {
					$data .= $patchline unless $patchline =~ qr"\$[N]etBSD";
				}
				close(PATCH);
				my $chksum = Digest::SHA1::sha1_hex($data);
				if ($sum ne $chksum) {
					$line->log_error("${alg} checksum of ${chksum_fname} differs (expected ${sum}, got ${chksum}). Rerun '".conf_make." makepatchsum'.");
				}
			} elsif (true) {
				$line->log_warning("${chksum_fname} does not exist.");
				$line->explain_warning(
					"All patches that are mentioned in a distinfo file should actually exist.",
					"What's the use of a checksum if there is no file to check?");
			}
		}
		$in_distinfo{$chksum_fname} = true;
	}
	checklines_trailing_empty_lines($lines);

	if (defined($patches_dir)) {
		foreach my $patch (<${current_dir}/${patches_dir}/patch-*>) {
			$patch = basename($patch);
			if (!exists($in_distinfo{$patch})) {
				log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '".conf_make." makepatchsum'.");
			}
		}
	}
}

sub checkfile_extra($) {
	my ($fname) = @_;
	my ($lines);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_extra()");

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

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_INSTALL()");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_MESSAGE($) {
	my ($fname) = @_;
	my ($lines);

	my @explanation = (
		"A MESSAGE file should consist of a header line, having 75 \"=\"",
		"characters, followed by a line containing only the RCS Id, then an",
		"empty line, your text and finally the footer line, which is the",
		"same as the header line.");

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_MESSAGE()");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (@{$lines} < 3) {
		log_warning($fname, NO_LINE_NUMBER, "File too short.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
		return;
	}
	if ($lines->[0]->text ne "=" x 75) {
		$lines->[0]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
	}
	checkline_rcsid($lines->[1], "");
	foreach my $line (@{$lines}) {
		checkline_length($line, 80);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, regex_validchars);
		checkline_spellcheck($line);
	}
	if ($lines->[-1]->text ne "=" x 75) {
		$lines->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
	}
	checklines_trailing_empty_lines($lines);
}

sub checkfile_mk($) {
	my ($fname) = @_;
	my ($lines);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_mk()");

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	parselines_mk($lines);
	checklines_mk($lines);
	autofix($lines);
}

sub checkfile_package_Makefile($$$) {
	my ($fname, $whole, $lines) = @_;

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_package_Makefile(..., ...)");

	checkperms($fname);

	if (!exists($pkgctx_vardef->{"PLIST_SRC"})
	    && !exists($pkgctx_vardef->{"GENERATE_PLIST"})
	    && !exists($pkgctx_vardef->{"META_PACKAGE"})
	    && defined($pkgdir)
	    && !-f "${current_dir}/$pkgdir/PLIST"
	    && !-f "${current_dir}/$pkgdir/PLIST.common") {
		log_warning($fname, NO_LINE_NUMBER, "Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset. Are you sure PLIST handling is ok?");
	}

	if ((exists($pkgctx_vardef->{"NO_CHECKSUM"}) || $pkgctx_vardef->{"META_PACKAGE"}) && is_emptydir("${current_dir}/${patchdir}")) {
		if (-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM or META_PACKAGE is set.");
		}
	} else {
		if (!-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makesum'.");
		}
	}

	if ($whole =~ /etc\/rc\.d/) {
		log_warning($fname, NO_LINE_NUMBER, "Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	if (exists($pkgctx_vardef->{"REPLACE_PERL"}) && exists($pkgctx_vardef->{"NO_CONFIGURE"})) {
		$pkgctx_vardef->{"REPLACE_PERL"}->log_warning("REPLACE_PERL is ignored when ...");
		$pkgctx_vardef->{"NO_CONFIGURE"}->log_warning("... NO_CONFIGURE is set.");
	}

	if (exists($pkgctx_vardef->{"RESTRICTED"}) && !exists($pkgctx_vardef->{"LICENSE"})) {
		$pkgctx_vardef->{"RESTRICTED"}->log_error("Restricted packages must have a LICENSE.");
	}

	if (exists($pkgctx_vardef->{"GNU_CONFIGURE"}) && exists($pkgctx_vardef->{"USE_LANGUAGES"})) {
		my $languages_line = $pkgctx_vardef->{"USE_LANGUAGES"};
		my $value = $languages_line->get("value");

		if ($languages_line->has("comment") && $languages_line->get("comment") =~ qr"\b(?:c|empty|none)\b"i) {
			# Don't emit a warning, since the comment
			# probably contains a statement that C is
			# really not needed.

		} elsif ($value !~ qr"(?:^|\s+)(?:c|c99|objc)(?:\s+|$)") {
			$pkgctx_vardef->{"GNU_CONFIGURE"}->log_warning("GNU_CONFIGURE almost always needs a C compiler, ...");
			$languages_line->log_warning("... but \"c\" is not added to USE_LANGUAGES.");
		}
	}

	my $distname_line = $pkgctx_vardef->{"DISTNAME"};
	my $pkgname_line = $pkgctx_vardef->{"PKGNAME"};

	my $distname = defined($distname_line) ? $distname_line->get("value") : undef;
	my $pkgname = defined($pkgname_line) ? $pkgname_line->get("value") : undef;

	# Let's do some tricks to get the proper value of the package
	# name more often.
	if (defined($distname) && defined($pkgname)) {
		$pkgname =~ s/\$\{DISTNAME\}/$distname/;
	}

	if (defined($pkgname) && defined($distname) && ($pkgname eq $distname || $pkgname eq "\${DISTNAME}")) {
		$pkgname_line->log_note("PKGNAME is \${DISTNAME} by default. You don't need to define PKGNAME.");
	}

	if (!defined($pkgname) && defined($distname) && $distname !~ regex_unresolved && $distname !~ regex_pkgname) {
		$distname_line->log_warning("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.");
	}

	($effective_pkgname, $effective_pkgname_line, $effective_pkgbase, $effective_pkgversion)
		= (defined($pkgname) && $pkgname !~ regex_unresolved && $pkgname =~ regex_pkgname) ? ($pkgname, $pkgname_line, $1, $2)
		: (defined($distname) && $distname !~ regex_unresolved && $distname =~ regex_pkgname) ? ($distname, $distname_line, $1, $2)
		: (undef, undef, undef, undef);
	if (defined($effective_pkgname_line)) {
		$opt_debug_misc and $effective_pkgname_line->log_debug("Effective name=${effective_pkgname} base=${effective_pkgbase} version=${effective_pkgversion}.");
	}

	if (!exists($pkgctx_vardef->{"COMMENT"})) {
		log_warning($fname, NO_LINE_NUMBER, "No COMMENT given.");
	}

	if (exists($pkgctx_vardef->{"USE_IMAKE"}) && exists($pkgctx_vardef->{"USE_X11"})) {
		$pkgctx_vardef->{"USE_IMAKE"}->log_note("USE_IMAKE makes ...");
		$pkgctx_vardef->{"USE_X11"}->log_note("... USE_X11 superfluous.");
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
	my ($seen_comment, $current_fname, $current_ftype, $patched_files);
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

	use enum qw(:PST_
		START CENTER TEXT
		CFA CH CHD CLD0 CLD CLA0 CLA
		UFA UH UL
	);

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
		if (defined($current_fname)) {
			if ($current_ftype eq "shell" || $current_ftype eq "make") {
				my ($mm, $rest) = match_all($text, $regex_shellword);

				foreach my $m (@{$mm}) {
					my $shellword = $m->text(1);

					if ($shellword =~ qr"^#") {
						last;
					}
					checkline_mk_absolute_pathname($line, $shellword);
				}

			} elsif ($current_ftype eq "source") {
				checkline_source_absolute_pathname($line, $text);

			} elsif ($current_ftype eq "configure") {
				if ($text =~ qr": Avoid regenerating within pkgsrc$") {
					$line->log_error("This code must not be included in patches.");
					$line->explain_error(
						"It is generated automatically by pkgsrc after the patch phase.");
				}

			} elsif ($current_ftype eq "ignore") {
				# Ignore it.

			} else {
				checkline_other_absolute_pathname($line, $text);
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
						$opt_debug_patches and $line->log_warning("The hunk that ends here does not have as many leading (${leading_context_lines}) as trailing (${trailing_context_lines}) lines of context.");
					}
				}
				$nextstate = $newstate;
			}
		}
	};

	my $check_hunk_line = sub($$$$) {
		my ($deldelta, $adddelta, $newstate, $check_added) = @_;

		$check_contents->();
		$check_hunk_end->($deldelta, $adddelta, $newstate);
		if ($check_added) {
			$check_added_contents->();
		}
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
			$current_ftype = get_filetype($line, $current_fname);
			$opt_debug_patches and $line->log_debug("fname=$current_fname ftype=$current_ftype");
			$patched_files++;
			$hunks = 0;
		}], [PST_CH, re_patch_ch, PST_CHD, sub() {
			$hunks++;
		}], [PST_CHD, re_patch_chd, PST_CLD0, sub() {
			$dellines = ($m->has(2))
			    ? (1 + $m->text(2) - $m->text(1))
			    : ($m->text(1));
		}], [PST_CLD0, re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
		}], [PST_CLD0, re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
		}], [PST_CLD0, re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
		}], [PST_CLD, re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
		}], [PST_CLD, re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
		}], [PST_CLD, re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0, false);
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
			$check_hunk_line->(0, 1, PST_CH, true);
		}], [PST_CLA0, re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH, true);
		}], [PST_CLA0, re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH, true);
		}], [PST_CLA, re_patch_clc, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH, true);
		}], [PST_CLA, re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH, true);
		}], [PST_CLA, re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH, true);
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
			$current_ftype = get_filetype($line, $current_fname);
			$opt_debug_patches and $line->log_debug("fname=$current_fname ftype=$current_ftype");
			$patched_files++;
			$hunks = 0;
		}], [PST_UH, re_patch_uh, PST_UL, sub() {
			$dellines = ($m->has(1) ? $m->text(2) : 1);
			$addlines = ($m->has(3) ? $m->text(4) : 1);
			$check_text->($line->text);
			if ($line->text =~ qr"\r$") {
				$line->log_error("The hunk header must not end with a CR character.");
				$line->explain_error(
					"The MacOS X patch utility cannot handle these.");
			}
			$hunks++;
			$context_scanning_leading = (($m->has(1) && $m->text(1) ne "1") ? true : undef);
			$leading_context_lines = 0;
			$trailing_context_lines = 0;
		}], [PST_UL, re_patch_uld, PST_UL, sub() {
			$check_hunk_line->(1, 0, PST_UH, false);
		}], [PST_UL, re_patch_ula, PST_UL, sub() {
			$check_hunk_line->(0, 1, PST_UH, true);
		}], [PST_UL, re_patch_ulc, PST_UL, sub() {
			$check_hunk_line->(1, 1, PST_UH, true);
		}], [PST_UL, re_patch_ulnonl, PST_UL, sub() {
			#
		}], [PST_UL, re_patch_empty, PST_UL, sub() {
			$opt_warn_space and $line->log_note("Leading white-space missing in hunk.");
			$check_hunk_line->(1, 1, PST_UH, false);
		}], [PST_UL, undef, PST_UH, sub() {
			if ($dellines != 0 || $addlines != 0) {
				$line->log_warning("Unexpected end of hunk (-${dellines},+${addlines} expected).");
			}
		}], [PST_UH, undef, PST_TEXT, sub() {
			($hunks != 0) || $line->log_warning("No hunks for file ${current_fname}.");
		}]];

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_patch()");

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
	$current_ftype = undef;
	$hunks = undef;

	for (my $lineno = 0; $lineno <= $#{$strings}; ) {
		$s = $strings->[$lineno];
		$line = $s->line;
		my $text = $line->text;

		$opt_debug_patches and $line->log_debug("[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."] $text");

		my $found = false;
		foreach my $t (@{$transitions}) {
			if ($state == $t->[0]) {
				if (!defined($t->[1])) {
					$m = undef;
				} elsif ($text =~ $t->[1]) {
					$opt_debug_patches and $line->log_debug($t->[1]);
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
		$opt_debug_patches and log_debug($fname, "EOF", "[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."]");

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
	my ($lines, $last_file_seen);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_PLIST()");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}
	checkline_rcsid($lines->[0], "\@comment ");

	if (@$lines == 1) {
		$lines->[0]->log_warning("PLIST files shouldn't be empty.");
		$lines->[0]->explain_warning(

"One reason for empty PLISTs is that this is a newly created package",
"and that the author didn't run \"bmake print-PLIST\" after installing",
"the files.",
"",
"Another reason, common for Perl packages, is that the PLIST is",
"automatically generated. Since there is no use of the empty PLIST file,",
"it shouldn't be necessary.");
	}

	# Get the list of all files from the PLIST.
	my $all_files = {};
	my $all_dirs = {};
	my $extra_lines = [];
	if (basename($fname) eq "PLIST.common_end") {
		my $common_lines = load_file(dirname($fname) . "/PLIST.common");
		if ($common_lines) {
			$extra_lines = $common_lines;
		}
	}

	foreach my $line (@{$extra_lines}, @{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"\$\{([\w_]+)\}(.*)") {
			if (defined($pkgctx_plist_subst_cond) && exists($pkgctx_plist_subst_cond->{$1})) {
				$opt_debug_misc and $line->log_debug("Removed PLIST_SUBST conditional $1.");
				$text = $2;
			}
		}
		
		if ($text =~ qr"^[\w\$]") {
			$all_files->{$text} = $line;
			my $dir = $text;
			while ($dir =~ s,/[^/]+$,,) {
				$all_dirs->{$dir} = $line;
			}
		}
		if ($text =~ qr"^\@exec \$\{MKDIR\} %D/(.*)$") {
			my $dir = $1;
			do {
				$all_dirs->{$dir} = $line;
			} while ($dir =~ s,/[^/]+$,,);
		}
	}

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);

		# @foo directives.
		if ($text =~ /^(?:\$\{[\w_]+\})?\@([a-z-]+)\s+(.*)/) {
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

			} elsif ($cmd eq "comment") {
				# nothing to do

			} elsif ($cmd eq "dirrm") {
				my @ids = get_shared_dir_ids($line, $arg);
				if (@ids == 0) {
					# Nothing to do
				} elsif (@ids == 1) {
					$line->log_warning("Please add \"USE_DIRS+= $ids[0]\" to the package Makefile and remove this line.");
				} else {
					my $s = join(" or ", map { "\"USE_DIRS+= $_\"" } @ids);
					$line->log_warning("Please add $s to the package Makefile and remove this line.");
				}
				if (!exists($all_dirs->{$arg})) {
					$line->log_warning("The PLIST does not contain files for \"$arg\".");
					$line->explain_warning(
"A package should only remove those directories that it created. When",
"there are no files in the directory, it is unlikely that the package",
"created the directory.");
				}

			} elsif ($cmd eq "imake-man") {
				my (@args) = split(/\s+/, $arg);
				if (@args != 3) {
					$line->log_warning("Invalid number of arguments for imake-man.");
				} else {
					if ($args[2] eq "\${IMAKE_MANNEWSUFFIX}") {
						warn_about_PLIST_imake_mannewsuffix($line);
					}
				}

			} else {
				$line->log_warning("Unknown PLIST directive \"\@$cmd\".");
			}

		# Pathnames.
		} elsif ($text =~ qr"^([A-Za-z0-9\$].*)/([^/]+)$") {
			my ($dirname, $basename) = ($1, $2);

			if ($opt_warn_plist_sort && $text =~ qr"^\w" && $text !~ regex_unresolved) {
				if (defined($last_file_seen)) {
					if ($last_file_seen gt $text) {
						$line->log_warning("${text} should be sorted before ${last_file_seen}.");
					} elsif ($last_file_seen eq $text) {
						$line->log_warning("Duplicate filename.");
					}
				}
				$last_file_seen = $text;
			}

			if ($basename =~ qr"\$\{IMAKE_MANNEWSUFFIX\}") {
				warn_about_PLIST_imake_mannewsuffix($line);
			}

			if ($dirname =~ qr"^bin/") {
				$line->log_warning("The bin/ directory should not have subdirectories.");

			} elsif ($dirname eq "bin") {

				if (exists($all_files->{"man/man1/${basename}.1"})) {
					# Fine.
				} elsif (exists($all_files->{"man/man6/${basename}.6"})) {
					# Fine.
				} elsif (exists($all_files->{"\${IMAKE_MAN_DIR}/${basename}.\${IMAKE_MANNEWSUFFIX}"})) {
					# Fine.
				} else {
					$opt_warn_extra and $line->log_warning("Manual page missing for bin/${basename}.");
				}

			} elsif ($text =~ qr"^doc/") {
				$line->log_error("Documentation must be installed under share/doc, not doc.");

			} elsif ($text =~ qr"^etc/rc\.d/") {
				$line->log_error("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.");

			} elsif ($text =~ qr"^etc/") {
				my $f = "mk/pkginstall/bsd.pkginstall.mk";

				assert(-f "${cwd_pkgsrcdir}/${f}", "${cwd_pkgsrcdir}/${f} is not a regular file.");
				$line->log_error("Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in ${f}.");

			} elsif ($text =~ qr"^include/.*\.(?:h|hpp)$") {
				# Fine.

			} elsif ($text eq "info/dir") {
				$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

			} elsif ($text =~ qr"^info/.+$") {
				if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"INFO_FILES"})) {
					$line->log_warning("Packages that install info files should set INFO_FILES.");
				}

			} elsif (defined($effective_pkgbase) && $text =~ qr"^lib/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif ($text =~ qr"^lib/locale/") {
				$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^(lib/(?:.*/)*)([^/]+)\.(so|a|la)$") {
				my ($dir, $lib, $ext) = ($1, $2, $3);

				if ($dir eq "lib/" && $lib !~ qr"^lib") {
					$opt_warn_extra and $line->log_warning("Library filename does not start with \"lib\".");
				}
				if ($ext eq "la") {
					if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"USE_LIBTOOL"})) {
						$line->log_warning("Packages that install libtool libraries should define USE_LIBTOOL.");
					}
				}

			} elsif ($text =~ qr"^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$") {
				my ($cat_or_man, $section, $manpage, $ext, $gz) = ($1, $2, $3, $4, $5);

				if ($section !~ qr"^[\dln]$") {
					$line->log_warning("Unknown section \"${section}\" for manual page.");
				}

				if ($cat_or_man eq "cat" && !exists($all_files->{"man/man${section}/${manpage}.${section}"})) {
					$line->log_warning("Preformatted manual page without unformatted one.");
				}

				if ($cat_or_man eq "cat") {
					if ($ext ne "0") {
						$line->log_warning("Preformatted manual pages should end in \".0\".");
					}
				} else {
					if ($section ne $ext) {
						$line->log_warning("Mismatch between the section (${section}) and extension (${ext}) of the manual page.");
					}
				}

				if (defined($gz)) {
					$line->log_note("The .gz extension is unnecessary for manual pages.");
					$line->explain_note(
						"Whether the manual pages are installed in compressed form or not is",
						"configured by the pkgsrc user. Compression and decompression takes place",
						"automatically, no matter if the .gz extension is mentioned in the PLIST",
						"or not.");
				}

			} elsif ($text =~ qr"^man/cat") {
				$line->log_warning("Invalid filename \"${text}\" for preformatted manual page.");

			} elsif ($text =~ qr"^man/man") {
				$line->log_warning("Invalid filename \"${text}\" for unformatted manual page.");

			} elsif ($text =~ qr"^sbin/(.*)") {
				my ($binname) = ($1);

				if (!exists($all_files->{"man/man8/${binname}.8"})) {
					$opt_warn_extra and $line->log_warning("Manual page missing for sbin/${binname}.");
				}

			} elsif ($dirname eq "share/aclocal" && $basename =~ qr"\.m4$") {
				# Fine.

			} elsif ($text =~ qr"^share/doc/html/") {
				$opt_warn_plist_depr and $line->log_warning("Use of \"share/doc/html\" is deprecated. Use \"share/doc/\${PKGBASE}\" instead.");

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/doc/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/examples/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif (defined($effective_pkgbase) && $text =~ qr"^share/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif ($text =~ qr"^share/info/") {
				$line->log_warning("Info pages should be installed into info/, not share/info/.");
				$line->explain_warning(
"To fix this, you should add INFO_FILES=yes to the package Makefile.");

			} elsif ($text =~ qr"^share/locale/[\w\@_]+/LC_MESSAGES/[^/]+\.mo$") {
				# Fine.

			} elsif ($text =~ qr"^share/man/") {
				$line->log_warning("Man pages should be installed into man/, not share/man/.");

			} else {
				$opt_debug_unchecked and $line->log_debug("Unchecked pathname \"${text}\".");
			}

			if ($text =~ /\${PKGLOCALEDIR}/ && defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"USE_PKGLOCALEDIR"})) {
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

				if (exists($all_files->{"${basename}.la"})) {
					$line->log_warning("Redundant library found. The libtool library is in line " . $all_files->{"${basename}.la"}->lines . ".");
				}
			}

		} elsif ($text =~ qr"^\$\{[\w_]+\}$") {
			# A variable on its own line.

		} else {
			$line->log_error("Unknown line type.");
		}
	}
	checklines_trailing_empty_lines($lines);
	autofix($lines);
}

sub checkfile($) {
	my ($fname) = @_;
	my ($st, $basename);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile()");

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
		$opt_debug_unchecked and log_debug($fname, NO_LINE_NUMBER, "Unchecked file \"${fname}\".");

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

sub my_split($$) {
	my ($delimiter, $s) = @_;
	my ($pos, $next, @result);

	$pos = 0;
	for ($pos = 0; $pos != -1; $pos = $next) {
		$next = index($s, $delimiter, $pos);
		push @result, (($next == -1) ? substr($s, $pos) : substr($s, $pos, $next - $pos));
		if ($next != -1) {
			$next += length($delimiter);
		}
	}
	return @result;
}

# Checks that the files in the directory are in sync with CVS's status.
#
sub checkdir_CVS($) {
	my ($fname) = @_;

	my $cvs_entries = load_file("$fname/CVS/Entries");
	my $cvs_entries_log = load_file("$fname/CVS/Entries.Log");
	return unless $cvs_entries;

	foreach my $line (@$cvs_entries) {
		my ($type, $fname, $mtime, $date, $keyword_mode, $tag, $undef) = my_split("/", $line->text);
		next if ($type eq "D" && !defined($fname));
		assert($type eq "" || $type eq "D", "Unknown line format: " . $line->text);
		assert(defined($tag), "Unknown line format: " . $line->text);
		assert(defined($keyword_mode), "Unknown line format: " . $line->text);
		assert(!defined($undef), "Unknown line format: " . $line->text);
	}
}

#
# Procedures to check a directory including the files in it.
#

sub checkdir_root() {
	my ($fname) = "${current_dir}/Makefile";
	my ($lines, $prev_subdir, @subdirs);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkdir_root()");

	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	parselines_mk($lines);
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

	checklines_mk($lines);

	if ($opt_recursive) {
		push(@todo_items, @subdirs);
	}
}

sub checkdir_category() {
	my $fname = "${current_dir}/Makefile";
	my ($lines, $lineno);

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkdir_category()");

	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	parselines_mk($lines);

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

	expect_empty_line($lines, \$lineno);

	# And, last but not least, the .include line
	my $final_line = ".include \"../mk/bsd.pkg.subdir.mk\"";
	expect($lines, \$lineno, qr"\Q$final_line\E")
	|| expect_text($lines, \$lineno, ".include \"../mk/misc/category.mk\"");

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_error("The file should end here.");
	}

	checklines_mk($lines);

	autofix($lines);

	if ($opt_recursive) {
		unshift(@todo_items, @subdirs);
	}
}

sub checkdir_package() {
	my ($whole, $lines, $have_distinfo, $have_patches);

	# Initialize global variables
	$pkgdir = undef;
	$filesdir = "files";
	$patchdir = "patches";
	$distinfo_file = "distinfo";
	$effective_pkgname = undef;
	$effective_pkgbase = undef;
	$effective_pkgversion = undef;
	$effective_pkgname_line = undef;
	$seen_bsd_prefs_mk = false;
	$pkgctx_vardef = {%{get_userdefined_variables()}};
	$pkgctx_varuse = {};
	$pkgctx_bl3 = {};
	$pkgctx_plist_subst_cond = {};
	$seen_Makefile_common = false;

	# we need to handle the Makefile first to get some variables
	if (!load_package_Makefile("${current_dir}/Makefile", \$whole, \$lines)) {
		log_error("${current_dir}/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		goto cleanup;
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
			parselines_mk($lines);
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

cleanup:
	# Clean up global variables.
	$pkgdir = undef;
	$filesdir = undef;
	$patchdir = undef;
	$distinfo_file = undef;
	$effective_pkgname = undef;
	$effective_pkgbase = undef;
	$effective_pkgversion = undef;
	$effective_pkgname_line = undef;
	$seen_bsd_prefs_mk = undef;
	$pkgctx_vardef = undef;
	$pkgctx_varuse = undef;
	$pkgctx_bl3 = undef;
	$pkgctx_plist_subst_cond = undef;
	$seen_Makefile_common = undef;
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

	$current_dir = $is_dir ? $item : dirname($item);
	my $abs_current_dir = Cwd::abs_path($current_dir);
	$is_wip = !$opt_import && ($abs_current_dir =~ qr"/wip(?:/|$)");
	$is_internal = ($abs_current_dir =~ qr"/mk(?:/|$)");

	# Determine the root directory of pkgsrc. By only overwriting
	# the global variable $cwd_pkgsrcdir when we are checking inside
	# a pkgsrc tree, the user can specify a tree with the
	# --pkgsrcdir option and then check files outside of any pkgsrc
	# tree.
	$cur_pkgsrcdir = undef;
	foreach my $d (".", "..", "../..", "../../..") {
		if (-f "${current_dir}/${d}/mk/bsd.pkg.mk") {
			$cur_pkgsrcdir = $d;
		}
	}
	if (!defined($cwd_pkgsrcdir) && defined($cur_pkgsrcdir)) {
		$cwd_pkgsrcdir = "${current_dir}/${cur_pkgsrcdir}";
	}

	if (!defined($cwd_pkgsrcdir)) {
		log_error($item, NO_LINE_NUMBER, "Cannot determine the pkgsrc root directory.");
		return;
	}

	check_pkglint_version();	# (needs $cwd_pkgsrcdir)

	if ($is_dir) {
		checkdir_CVS($item);
	}

	if ($is_reg) {
		checkfile($item);

	} elsif (!defined($cur_pkgsrcdir)) {
		log_error($item, NO_LINES, "Cannot check directories outside a pkgsrc tree.");

	} elsif ($cur_pkgsrcdir eq "../..") {
		checkdir_package();

	} elsif ($cur_pkgsrcdir eq "..") {
		checkdir_category();

	} elsif ($cur_pkgsrcdir eq ".") {
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
