#! @PERL@ -w
#
# pkglint - lint for package directory
#
# implemented by:
#	Jun-ichiro itojun Hagino <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
#
# Copyright(c) 1997 by Jun-ichiro Hagino <itojun@itojun.org>.
# All rights reserved.
# Freely redistributable.  Absolutely no warranty.
#
# From Id: portlint.pl,v 1.64 1998/02/28 02:34:05 itojun Exp
# $NetBSD: pkglint.pl,v 1.412 2005/12/02 20:15:00 rillig Exp $
#
# This version contains lots of changes necessary for NetBSD packages
# done by:
#	Hubert Feyrer <hubertf@netbsd.org>,
#	Thorsten Frueauf <frueauf@netbsd.org>,
#	Thomas Klausner <wiz@netbsd.org>,
#	Roland Illig <rillig@NetBSD.org>
#	and others.
#

#==========================================================================
# Some comments on the overall structure: The @EXPORT clauses in the pack-
# ages must be in a BEGIN block, because otherwise the names starting with
# an uppercase letter are not recognized as subroutines but as file handles.
#==========================================================================

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
	@EXPORT_OK = qw(array_to_hash false print_table true);
}

use constant false	=> 0;
use constant true	=> 1;

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
# NO_LINE_NUMBER. Before printing, the filename is normalized, that is,
# "/foo/bar/../../" components are removed, as well as "." components.
# At the end of the program, the subroutine print_summary_and_exit should
# be called.
#
# Examples:
#   log_error(NO_FILE, NO_LINE_NUMBER, "Invalid command line.");
#   log_warning($fname, NO_LINE_NUMBER, "Not found.");
#   log_info($fname, $lineno, sprintf("invalid character (0x%02x).", $c));
#==========================================================================

use strict;
use warnings;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		NO_FILE NO_LINE_NUMBER
		log_fatal log_error log_warning log_note log_info log_debug
		explain
		print_summary_and_exit set_verbosity get_verbosity
		set_explain set_gcc_output_format
		get_show_source_flag set_show_source_flag
	);
	import PkgLint::Util qw(
		false true
	);
}

use constant NO_FILE		=> undef;
use constant NO_LINE_NUMBER	=> undef;

my $errors		= 0;
my $warnings		= 0;
my $verbosity		= 0;
my $gcc_output_format	= false;
my $explain_flag	= false;
my $show_source_flag	= false;
my $indent		= "";	# The width of the last diagnostics type.

sub log_message($$$$$) {
	my ($out, $file, $lineno, $type, $message) = @_;
	my ($text, $sep);

	if (defined($file)) {
		# strip "." path components
		$file =~ s,^(?:\./)+,,;
		$file =~ s,/(?:\./)+,/,g;
		$file =~ s,/+,/,g;

		# strip intermediate "../.." path components
		while ($file =~ s,/[^.][^/]*/[^.][^/]*/\.\./\.\./,/,) {
		}
	}

	$text = "";
	$sep = "";
	if (!$gcc_output_format && defined($type)) {
		$text .= "${sep}${type}:";
		$sep = " ";
		$indent = " " x length($type);
	}
	if (defined($file)) {
		$text .= defined($lineno)
		    ? "${sep}${file}:${lineno}"
		    : "${sep}${file}";
		$sep = ": ";
	}
	if ($gcc_output_format && defined($type)) {
		$text .= "${sep}${type}:";
		$sep = " ";
	}
	if (defined($message)) {
		$text .= "${sep}${message}";
		$sep = "";
	}

	print $out ("${text}\n");
}

sub log_fatal($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDERR, $file, $lineno, $gcc_output_format ? "fatal" : "FATAL", $msg);
	exit(1);
}

sub log_error($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, $lineno, $gcc_output_format ? "error" : "ERROR", $msg);
	$errors++;
}
sub log_warning($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, $lineno, $gcc_output_format ? "warning" : "WARN", $msg);
	$warnings++;
}
sub log_note($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, $lineno, $gcc_output_format ? "note" : "NOTE", $msg);
}
sub log_info($$$) {
	my ($file, $lineno, $msg) = @_;
	if ($verbosity >= 1) {
		log_message(*STDOUT, $file, $lineno, $gcc_output_format ? "info" : "OK", $msg);
	}
}
sub log_debug($$$) {
	my ($file, $lineno, $msg) = @_;
	if ($verbosity >= 2) {
		log_message(*STDOUT, $file, $lineno, $gcc_output_format ? "debug" : "DEBUG", $msg);
	}
}

sub explain($$@) {
	my ($file, $lines, @texts) = @_;

	if ($explain_flag) {
		foreach my $text (@texts) {
			print STDOUT ("${indent}  ${text}\n");
		}
	}
}

sub print_summary_and_exit($) {
	my ($quiet) = @_;

	if ($show_source_flag) {
		print("\n");
	}

	if (!$quiet) {
		if ($errors != 0 || $warnings != 0) {
			print("$errors errors and $warnings warnings found.\n");
		} else {
			print "looks fine.\n";
		}
	}
	exit($errors != 0);
}

sub get_verbosity() {
	return $verbosity;
}
sub set_verbosity($) {
	($verbosity) = @_;
}

sub set_explain() {
	$explain_flag = true;
}
sub set_gcc_output_format() {
	$gcc_output_format = true;
}

sub get_show_source_flag() {
	return $show_source_flag;
}
sub set_show_source_flag() {
	$show_source_flag = true;
}

#== End of PkgLint::Logging ===============================================

package PkgLint::FileUtil::Line;
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
BEGIN {
	import PkgLint::Util qw(
		false true
	);
}

use constant FILE	=> 0;
use constant LINES	=> 1;
use constant TEXT	=> 2;
use constant PHYSLINES	=> 3;
use constant CHANGED	=> 4;
use constant BEFORE	=> 5;
use constant AFTER	=> 6;

sub new($$$$) {
	my ($class, $file, $lines, $text, $physlines) = @_;
	my ($self) = ([$file, $lines, $text, $physlines, false, [], []]);
	bless($self, $class);
	return $self;
}
sub file($) {
	return shift(@_)->[FILE];
}
sub lines($) {
	return shift(@_)->[LINES];
}
sub text($) {
	return shift(@_)->[TEXT];
}
sub physlines($) {
	my ($self) = @_;
	return [@{$self->[BEFORE]}, @{$self->[PHYSLINES]}, @{$self->[AFTER]}];
}
sub is_changed($) {
	return shift(@_)->[CHANGED];
}

sub show_source($$) {
	my ($self, $out) = @_;

	if (PkgLint::Logging::get_show_source_flag()) {
		printf $out ("\n");
		foreach my $line (@{$self->physlines}) {
			printf $out ("> %s", $line->[1]);
		}
	}
}

sub log_fatal($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDERR);
	PkgLint::Logging::log_fatal($self->[FILE], $self->[LINES], $text);
}
sub log_error($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_error($self->[FILE], $self->[LINES], $text);
}
sub log_warning($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_warning($self->[FILE], $self->[LINES], $text);
}
sub log_note($$) {
	my ($self, $text) = @_;
	$self->show_source(*STDOUT);
	PkgLint::Logging::log_note($self->[FILE], $self->[LINES], $text);
}
sub log_info($$) {
	my ($self, $text) = @_;
	if (PkgLint::Logging::get_verbosity() >= 1) {
		$self->show_source(*STDOUT);
	}
	PkgLint::Logging::log_info($self->[FILE], $self->[LINES], $text);
}
sub log_debug($$) {
	my ($self, $text) = @_;
	if (PkgLint::Logging::get_verbosity() >= 2) {
		$self->show_source(*STDOUT);
	}
	PkgLint::Logging::log_debug($self->[FILE], $self->[LINES], $text);
}
sub explain($@) {
	my ($self, @texts) = @_;
	PkgLint::Logging::explain($self->[FILE], $self->[LINES], @texts);
}

sub to_string($) {
	my ($self) = @_;
	return sprintf("%s:%s: %s", $self->[FILE], $self->[LINES], $self->[TEXT]);
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
sub set_text($$) {
	my ($self, $text) = @_;
	$self->[PHYSLINES] = [[0, "$text\n"]];
	$self->[CHANGED] = true;
}

#== End of PkgLint::FileUtil::Line ========================================

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

	return PkgLint::FileUtil::Line->new($fname,
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
			push(@{$loglines}, PkgLint::FileUtil::Line->new($fname, $physline->[0], $text, [$physline]));
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

sub save_autofix_changes($) {
	my ($lines) = @_;

	my (%changed, %physlines);

	foreach my $line (@{$lines}) {
		if ($line->is_changed) {
			$changed{$line->file}++;
		}
		push(@{$physlines{$line->file}}, @{$line->physlines});
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
# Note: The order of subroutines in the file is mostly historical. One
# important property is that there are no back-references, that is, if
# you start reading the code from the top to the bottom you won't find a
# call to a subroutine you haven't yet seen.
#==========================================================================
use strict;
use warnings;

use Digest::SHA1;
use Getopt::Long qw(:config no_ignore_case bundling require_order);
use Fcntl qw(:mode);
use File::Basename;
use File::stat;
use Cwd;

BEGIN {
	import PkgLint::Util qw(
		array_to_hash false true
	);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER
		log_fatal log_error log_warning log_note log_info log_debug
		explain
	);
	import PkgLint::FileUtil qw(
		load_file load_lines
		save_autofix_changes
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
my $opt_warn_order	= true;
my $opt_warn_plist_sort	= false;
my $opt_warn_types	= true;
my (%warnings) = (
	"absname"	=> [\$opt_warn_absname, "warn about use of absolute file names"],
	"directcmd"	=> [\$opt_warn_directcmd, "warn about use of direct command names instead of Make variables"],
	"order"		=> [\$opt_warn_order, "warn if Makefile entries are unordered"],
	"plist-sort"	=> [\$opt_warn_plist_sort, "warn about unsorted entries in PLISTs"],
	"types"		=> [\$opt_warn_types, "do some simple type checking in Makefiles"],
);

my $opt_autofix		= false;
my $opt_dumpmakefile	= false;
my $opt_import		= false;
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
		printf("%s\n", conf_distver);
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
	  } ]
);

#
# Commonly used regular expressions.
#

use constant regex_gnu_configure_volatile_vars
				=> qr"^(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$";
use constant regex_mk_dependency=> qr"^([^\s:]+(?:\s*[^\s:]+)*):\s*([^#]*?)(?:\s*#.*)?$";
use constant regex_mk_include	=> qr"^\.\s*s?include\s+\"([^\"]+)\"(?:\s*#.*)?$";
use constant regex_pkgname	=> qr"^((?:[\w.+]|-[^\d])+)-(\d(?:\w|\.\d)*)$";
use constant regex_shellcmd	=> qr"^\t(.*)$";
use constant regex_unresolved	=> qr"\$\{";
use constant regex_validchars	=> qr"[\011\040-\176]";
use constant regex_varassign	=> qr"^([-*+A-Z_a-z0-9.\${}\[]+?)\s*(=|\?=|\+=|:=|!=)\s*((?:\\#|[^#])*?)(?:\s*(#.*))?$";

# This "constant" is often used in contexts where interpolation comes
# handy, so it is a variable. Nevertheless it is not modified. Of course
# it cannot parse all kinds of shell programs, but this pattern will
# catch all shell programs that are portable enough to be used in pkgsrc.
my $regex_shellword		=  qr"\s*(
	(?:	'[^']*'
	|	\"(?:\\.|[^\"\\])*\"
	|	\`[^\`]*\`
	|	\\.
	|	[^'\"\\\s;&\|<>\#]
	)+ | ;;? | &&? | \|\|? | <<? | >>? | \#.*)"sx;

#
# Commonly used explanations for diagnostics.
#

use constant expl_relative_dirs	=> (
	"Directories in the form \"category/package\" make it easier to move",
	"a package around in pkgsrc, for example from pkgsrc-wip to the main",
	"pkgsrc repository.");

#
# Global variables.
#

my $current_dir;		# The currently checked directory.
my $is_wip;			# Is the current directory from pkgsrc-wip?

my $pkgsrcdir;			# The pkgsrc root directory
my $pkgdir;			# PKGDIR from the package Makefile
my $filesdir;			# FILESDIR from the package Makefile
my $patchdir;			# PATCHDIR from the package Makefile
my $distinfo_file;		# DISTINFO_FILE from the package Makefile
my $pkgname;			# PKGNAME from the package Makefile
my $hack_php_patches;		# Ignore non-existing patches in distinfo

my $makevar;			# Table of variables and values
my $seen_Makefile_common;	# Does the package have any .includes?

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
				printf STDERR ("Invalid option: ${opt}\n");
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
# Loading pkglint-specific data from files, part 1.
#

sub load_make_vars_typemap() {
	my ($vartypes);
	my ($fname);

	$vartypes = {};

	$fname = conf_datadir."/makevars.map";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^(?:#.*|\s*)$") {
				# ignore empty and comment lines

			} elsif ($line->text =~ qr"^([\w\d_.]+)\s+([-!\+.\w\d_ \{\}]+)$") {
				$vartypes->{$1} = $2;

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
	$fname = "${pkgsrcdir}/mk/defaults/mk.conf";
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

	return $vartypes;
}

my $load_dist_sites_url2name = undef;
my $load_dist_sites_names = undef;
sub load_dist_sites() {
	my ($fname) = ("${pkgsrcdir}/mk/bsd.sites.mk");
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

	log_info($fname, NO_LINE_NUMBER, sprintf("Loaded %d MASTER_SITE_* definitions.", scalar(keys(%{$url2name}))));
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

sub resolve_relative_path($) {
	my ($relpath) = @_;

	$relpath =~ s,\$\{PKGSRCDIR\},$pkgsrcdir,;
	$relpath =~ s,\$\{\.CURDIR\},.,;
	$relpath =~ s,\$\{PHPPKGSRCDIR\},../../lang/php5,;
	$relpath =~ s,\$\{SUSE_DIR_PREFIX\},suse91,;
	$relpath =~ s,\$\{PYPKGSRCDIR\},../../lang/python23,;
	if (defined($pkgdir)) {
		$relpath =~ s,\$\{PKGDIR\},$pkgdir,g;
	}

	return $relpath;
}

#
# Subroutines to check a single line.
#

sub checkline_length($$) {
	my ($line, $maxlength) = @_;

	if (length($line->text) > $maxlength) {
		$line->log_warning("Line too long (should be no more than $maxlength characters).");
		$line->explain(
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
		$line->log_warning(sprintf("Line contains invalid characters (%s).", join(", ", @chars)));
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
		$line->log_warning(sprintf("${varname} contains invalid characters (%s).", join(", ", @chars)));
	}
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;
	if ($line->text =~ /\s+$/) {
		$line->log_note("Trailing white-space.");
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

	if (!$is_wip && $path =~ qr"/wip/") {
		$line->log_error("A pkgsrc package must not depend on any outside package.");
	}
	$path = resolve_relative_path($path);
	if ($path =~ regex_unresolved) {
		$line->log_info("Unresolved path: \"${path}\".");
	} elsif (!-e "${current_dir}/${path}") {
		$line->log_error("\"${path}\" does not exist.");
	}
}

#
# Procedures to check an array of lines, part 1.
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

#
# Procedures to check a file, part 1.
#

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
	}
	checklines_trailing_empty_lines($descr);

	if (@{$descr} > $maxlines) {
		my $line = $descr->[$maxlines];

		$line->log_warning("File too long (should be no more than $maxlines lines).");
		$line->explain(
			"A common terminal size is 80x25 characters. The DESCR file should",
			"fit on one screen. It is also intended to give a _brief_ summary",
			"about the package's contents.");
	}
}

sub checkfile_distinfo($) {
	my ($fname) = @_;
	my ($lines, %in_distinfo, %sums);

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
		$lines->[1]->log_warning("Empty line expected.");
		$lines->[1]->explain("This is merely for aesthetical purposes.");
	}

	foreach my $line (@{$lines}[2..$#{$lines}]) {
		if ($line->text !~ /^(MD5|SHA1|RMD160|Size) \(([^)]+)\) = (.*)(?: bytes)?$/) {
			$line->log_error("Unknown line type.");
			next;
		}

		my ($alg, $file, $sum) = ($1, $2, $3);

		if ($file =~ /^patch-[A-Za-z0-9]+$/) {
			if (open(PATCH, "< ${current_dir}/${patchdir}/${file}")) {
				my $data = "";
				foreach my $patchline (<PATCH>) {
					$data .= $patchline unless $patchline =~ qr"\$NetBSD.*\$";
				}
				close(PATCH);
				my $chksum = Digest::SHA1::sha1_hex($data);
				if ($sum ne $chksum) {
					$line->log_error("${alg} checksum of $file differs (expected ${sum}, got ${chksum}). Rerun '".conf_make." makepatchsum'.");
				}
			} elsif (!$hack_php_patches) {
				$line->log_warning("$file does not exist.");
				$line->explain(
					"All patches that are mentioned in a distinfo file should actually exist.",
					"What's the use of a checksum if there is no file to check?");
			}
		} else {
			$sums{$alg}->{$file} = $line;
		}
		$in_distinfo{$file} = true;
	}
	checklines_trailing_empty_lines($lines);

	# Check for distfiles that have SHA1, but not RMD160 checksums
	foreach my $sha1_file (sort(keys(%{$sums{"SHA1"}}))) {
		if (!exists($sums{"RMD160"}->{$sha1_file})) {
			$sums{"SHA1"}->{$sha1_file}->log_error("RMD160 checksum missing for \"${sha1_file}\".");
		}
	}

	foreach my $patch (<${current_dir}/$patchdir/patch-*>) {
		$patch = basename($patch);
		if (!exists($in_distinfo{$patch})) {
			log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '".conf_make." makepatchsum'.");
		}
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
		explain($fname, NO_LINE_NUMBER, @explanation);
		return;
	}
	if ($message->[0]->text ne "=" x 75) {
		$message->[0]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain($fname, NO_LINE_NUMBER, @explanation);
	}
	checkline_rcsid($message->[1], "");
	foreach my $line (@{$message}) {
		checkline_length($line, 80);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, regex_validchars);
	}
	if ($message->[-1]->text ne "=" x 75) {
		$message->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain($fname, NO_LINE_NUMBER, @explanation);
	}
	checklines_trailing_empty_lines($message);
}

sub checkfile_PLIST($) {
	my ($fname) = @_;
	my ($plist, $last_file_seen);

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

	line:
	foreach my $line (@{$plist}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);

		if ($text =~ /^\@([a-z]+)\s+(.*)/) {
			my ($cmd, $arg) = ($1, $2);

			if ($cmd eq "unexec" && $arg =~ qr"^(rmdir|\$\{RMDIR\})(.*)") {
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

			if ($text =~ qr"^doc/") {
				$line->log_error("Documentation must be installed under share/doc, not doc.");

			} elsif ($text =~ qr"^etc/rc\.d/") {
				$line->log_error("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.");

			} elsif ($text =~ qr"^etc/") {
				$line->log_error("Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in mk/install/bsd.pkginstall.mk.");

			} elsif ($text eq "info/dir") {
				$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

			} elsif ($text =~ qr"^lib/locale/") {
				$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^share/locale/") {
				$line->log_warning("Use of \"share/locale\" is deprecated.  Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^share/man/") {
				$line->log_warning("Man pages should be installed into man/, not share/man/.");
			}

			if ($text =~ /\${PKGLOCALEDIR}/ && defined($makevar) && !exists($makevar->{"USE_PKGLOCALEDIR"})) {
				$line->log_warning("PLIST contains \${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.");
			}

			if ($text =~ qr"/CVS/") {
				$line->log_warning("CVS files should not be in the PLIST.");
			}

		} else {
			$line->log_error("Unknown line type.");
		}
	}
	checklines_trailing_empty_lines($plist);
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

#
# Procedures to check an array of lines, part 2.
#

sub checklines_multiple_patches($) {
	my ($lines) = @_;
	my ($files_in_patch, $patch_state, $line_type, $dellines);

	$files_in_patch = 0;
	$patch_state = "";
	$dellines = 0;
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"^@@ -\d+,(\d+) \+\d+,\d+ @@") {
			$line_type = "";
			$dellines = $1;

		} elsif ($dellines == 0 && index($text, "--- ") == 0 && $text !~ qr"^--- \d+(?:,\d+|) ----$") {
			$line_type = "-";

		} elsif (index($text, "*** ") == 0 && $text !~ qr"^\*\*\* \d+(?:,\d+|) \*\*\*\*$") {
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
			$line_type = "*";

		} elsif (index($text, "+++ ") == 0) {
			$line_type = "+";

		} elsif ($dellines > 0 && $text =~ qr"^(?:-|\s)") {
			$line_type = "";
			$dellines--;

		} else {
			$line_type = "";
		}

		if ($patch_state eq "*") {
			if ($line_type eq "-") {
				$files_in_patch++;
				$patch_state = "";
			} else {
				$line->log_error("[internal] Unknown patch format.");
			}

		} elsif ($patch_state eq "-") {
			if ($line_type eq "+") {
				$files_in_patch++;
				$patch_state = "";
			} else {
				$line->log_error("[internal] Unknown patch format.");
			}

		} elsif ($patch_state eq "") {
			$patch_state = $line_type;
		}
	}

	if ($files_in_patch > 1) {
		log_warning($lines->[0]->file, NO_LINE_NUMBER, "Contains patches for $files_in_patch files, should be only one.");

	} elsif ($files_in_patch == 0) {
		log_error($lines->[0]->file, NO_LINE_NUMBER, "Contains no patch.");
	}
}

#
# Procedures to check a file, part 2.
#

sub checkfile_patches_patch($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_patches_patch]");

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}
	checkline_rcsid($lines->[0], "");

	foreach my $line (@{$lines}[1..$#{$lines}]) {
		if ($line->text =~ qr"\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|$opt_rcsidstring)[:\$]") {
			my ($tag) = ($1);
			if ($line->text =~ qr"^(\@\@.*?\@\@)") {
				$line->log_warning("Patches should not contain RCS tags.");
				$line->set_text($1);
			} else {
				$line->log_warning("Possible RCS tag \"\$${tag}\$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".");
			}
		}

		if ($line->text =~ qr"^\+") {
			use constant good_macros => PkgLint::Util::array_to_hash(qw(
				__STDC__

				__GNUC__ __GNUC_MINOR__
				__SUNPRO_C

				__i386
				__mips
				__sparc

				__DragonFly__
				__FreeBSD__
				__INTERIX
				__linux__
				__NetBSD__
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
			my $rest = $line->text;
			my $re_ifdef = qr"defined\((__[\w_]+)\)";

			while ($rest =~ s/$re_ifdef//) {
				my ($macro) = ($1);

				if (exists(good_macros->{$macro})) {
					$line->log_debug("Found good macro \"${macro}\".");
				} elsif (exists(bad_macros->{$macro})) {
					$line->log_warning("The macro \"${macro}\" is unportable. Please use \"".bad_macros->{$macro}."\" instead.");
					$line->explain("See the pkgsrc guide, section \"CPP defines\" for details.");
				} else {
					$line->log_info("Found unknown macro \"${macro}\".");
				}
			}
		}
	}
	checklines_trailing_empty_lines($lines);

	checklines_multiple_patches($lines);

	autofix($lines);
}

#
# Loading package-specific data from files.
#

sub readmakefile($$$$);
sub readmakefile($$$$) {
	my ($file, $main_lines, $all_lines, $seen_Makefile_include) = @_;
	my $contents = "";
	my ($includefile, $dirname, $lines, $is_main_Makefile);

	$lines = load_lines($file, true);
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
			$includefile = resolve_relative_path($1);
			if ($includefile =~ regex_unresolved) {
				if ($file !~ qr"/mk/") {
					$line->log_warning("Skipping include file \"${includefile}\". This may result in false warnings.");
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
				$line->explain(expl_relative_dirs);
			}
			if ($includefile =~ qr"(?:^|/)Makefile.common$"
			    || ($includefile =~ qr"^(?:\.\./(?:\.\./[^/]+/)?[^/]+/)?([^/]+)$" && $1 ne "buildlink3.mk")) {
				$seen_Makefile_common = true;
			}
			if ($includefile =~ qr"/mk/") {
				# skip these files
				$contents .= $text . "\n";
			} else {
				$dirname = dirname($file);
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
				$makevar->{$varname} = $line;
			}
			$contents .= $text . "\n";

		} else {
			$contents .= $text . "\n";
		}
	}
	return $contents;
}

#
# Loading data from pkglint-specific files, part 2.
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
		BUILDLINK_RECOMMENDED
		COMMENT
		EXTRACT_ONLY
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
		FIX_RPATH
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

my $get_tool_names_value = undef;
sub get_tool_names() {

	if (defined($get_tool_names_value)) {
		return $get_tool_names_value;
	}

	my $tools = {};
	foreach my $file (qw(autoconf automake defaults ldconfig make replace rpcgen texinfo)) {
		my $fname = "${pkgsrcdir}/mk/tools/${file}.mk";
		my $lines = load_lines($fname, true);

		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
			next;
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);
				if ($varname eq "TOOLS_CREATE" && $value =~ qr"^([-\w.]+)$") {
					$tools->{$value} = true;

				} elsif ($varname =~ qr"^(?:TOOLS_PATH|_TOOLS_DEPMETHOD|_TOOLS_VARNAME)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;

				} elsif ($varname =~ qr"^_TOOLS\.") {
					foreach my $tool (split(qr"\s+", $value)) {
						$tools->{$tool} = true;
					}
				}
			}
		}
	}
	log_debug(NO_FILE, NO_LINE_NUMBER, "Known tools: ".join(" ", sort(keys(%{$tools}))));

	$get_tool_names_value = $tools;
	return $get_tool_names_value;
}

#
# Procedures to check a single line, part 3.
#

sub checkline_basic_vartype($$$$$) {
	my ($line, $varname, $type, $value, $comment) = @_;
	my ($value_novar);

	$value_novar = $value;
	while ($value_novar =~ s/\$\{[^{}]*\}//g) {
	}

	if ($type eq "Category") {
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

	} elsif ($type eq "Comment") {
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
			$line->explain(
				"Typical dependencies have the form \"package>=2.5\", \"package-[0-9]*\"",
				"or \"package-3.141\".");
		}

	} elsif ($type eq "DependencyWithPath") {
		if ($value =~ regex_unresolved) {
			# don't even try to check anything
		} elsif ($value =~ qr":(\.\./\.\./([^/]+)/([^/]+))$") {
			my ($relpath, $cat, $pkg) = ($1, $2, $3);

			checkline_relative_path($line, $relpath);

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
			$line->explain(expl_relative_dirs);

		} else {
			$line->log_warning("Unknown dependency format.");
			$line->explain(
				"Examples for valid dependencies are:",
				"  package-[0-9]*:../../category/package",
				"  package>=3.41:../../category/package",
				"  package-2.718:../../category/package");
		}

	} elsif ($type eq "DistSuffix") {
		if ($value eq ".tar.gz") {
			$line->log_note("\"${varname} is \".tar.gz\" by default, so this definition may be redundant.");
		}

	} elsif ($type eq "Filename") {
		if ($value_novar !~ qr"^[-0-9\@A-Za-z.,_~+%]*$") {
			$line->log_warning("\"${value}\" is not a valid filename.");
		}

	} elsif ($type eq "Filemask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?]*$") {
			$line->log_warning("\"${value}\" is not a valid filename mask.");
		}

	} elsif ($type eq "Mail_Address") {
		if ($value =~ qr"^([-\w\d_.]+)\@([-\w\d.]+)$") {
			my (undef, $domain) = ($1, $2);
			if ($domain =~ qr"^NetBSD.org"i && $domain ne "NetBSD.org") {
				$line->log_warning("Please write NetBSD.org instead of ${domain}.");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid mail address.");
		}

	} elsif ($type eq "Option") {
		if ($value_novar !~ qr"^-?[a-z][-0-9a-z]*$") {
			$line->log_warning("\"${value}\" is not a valid option name.");
		}

	} elsif ($type eq "Pathname") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname.");
		}

	} elsif ($type eq "Pathmask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname mask.");
		}

	} elsif ($type eq "Perl5Packlist") {
		if ($value ne $value_novar) {
			$line->log_warning("${varname} should not depend on other variables.");
		}

	} elsif ($type eq "PkgName") {
		if ($value eq $value_novar && $value !~ regex_pkgname) {
			$line->log_warning("\"${value}\" is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.");
		}

	} elsif ($type eq "PkgRevision") {
		if ($value !~ qr"^\d+$") {
			$line->log_warning("\"${value}\" is not a valid Integer.");
		}
		if ($line->file !~ qr"(?:^|/)Makefile$") {
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
			$line->explain(
				"A platform triple has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
				"Each of these components may be a shell globbing expression.",
				"Examples: NetBSD-*-i386, *-*-*, Linux-*-*.");
		}

	} elsif ($type eq "Readonly") {
		$line->log_error("\"${varname}\" is a read-only variable and therefore must not be modified.");

	} elsif ($type eq "RelativePkgDir") {
		if ($value !~ qr"^\.\./\.\./[^/]+/[^/]+$") {
			$line->log_warning("\"${value}\" is not a valid relative package directory.");
			$line->explain(
				"A relative package directory always starts with \"../../\", followed",
				"by a category, a slash and a the directory name of the package.",
				"For example, \"../../misc/screen\" is a relative package directory.");
		}

	} elsif ($type eq "ShellWord") {
		if ($value =~ qr"^([\w_]+)=(([\"']?)\$\{([\w_]+)\}\3)$") {
			my ($key, $vexpr, undef, $vname) = ($1, $2, $3, $4);
			my $mod = ($vname =~ regex_gnu_configure_volatile_vars) ? ":M*:Q" : ":Q";
			my $fixed_vexpr = "\${${vname}${mod}}";
			$line->log_warning("Please use ${fixed_vexpr} instead of ${vexpr}.");
			$line->replace($value, "${key}=${fixed_vexpr}");

		} elsif ($value =~ qr"^([\w_]+)=(\$\{([\w_]+):Q\})$") {
			my ($key, $vexpr, $vname) = ($1, $2, $3);
			my $fixed_vexpr = "\${${vname}:M*:Q}";
			if ($vname =~ regex_gnu_configure_volatile_vars) {
				$line->log_warning("Please use ${fixed_vexpr} instead of ${vexpr}.");
				$line->replace($value, "${key}=${fixed_vexpr}");
			}

		} elsif ($value ne "" && $value !~ qr"^${regex_shellword}$") {
			$line->log_warning("Invalid shell word \"${value}\".");
		}

	} elsif ($type eq "Stage") {
		if ($value !~ qr"^(?:pre|do|post)-(?:extract|patch|configure|build|install)$") {
			$line->log_warning("Invalid stage name. Use one of {pre,do,post}-{extract,patch,configure,build,install}.");
		}

	} elsif ($type eq "Tool") {
# FIXME: There are two different kinds of tools in pkgsrc.
# I've asked jlam for appropriate checks. Until I get a
# definite answer, this check will be disabled.
if (false) {
		if ($value =~ qr"^([-\w]+|\[)(?::(\w+))?$") {
			my ($toolname, $tooldep) = ($1, $2);
			if (!exists(get_tool_names()->{$toolname})) {
				$line->log_error("Unknown tool \"${toolname}\".");
			}
			if (defined($tooldep) && $tooldep !~ qr"^(?:build|pkgsrc|run)$") {
				$line->log_error("Unknown tool dependency \"${tooldep}\".");
			}
		} else {
			$line->log_error("Invalid tool syntax: \"${value}\".");
		}
}

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

		} elsif ($value =~ qr"^(?:http://|ftp://|gopher://)[-0-9A-Za-z.]+(?::\d+)?/~?([-%&+,./0-9:=?\@A-Z_a-z]|\\#)*?$") {
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

	} elsif ($type eq "Userdefined") {
		$line->log_error("\"${varname}\" may only be set by the user, not the package.");

	} elsif ($type eq "Varname") {
		if ($value ne "" && $value_novar eq "") {
			# The value of another variable

		} elsif ($value_novar !~ qr"^[A-Z_][0-9A-Z_]*(?:[.].*)?$") {
			$line->log_warning("\"${value}\" is not a valid variable name.");
		}

	} elsif ($type eq "WrkdirSubdirectory") {
		# TODO: check for ${WRKDIR}/${DISTNAME}/foo

	} elsif ($type eq "WrksrcSubdirectory") {
		if ($value =~ qr"^(\$\{WRKSRC\}(?:/|$))") {
			my ($prefix) = ($1);
			# TODO: uncomment after 2005Q4
			#$line->log_note("The \"${prefix}\" prefix is not needed here.");

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

	} elsif ($type =~ qr"^\{\s*(.*?)\s*\}$") {
		my ($values) = ($1);
		my @enum = split(qr"\s+", $values);
		my $found = false;

		foreach my $v (@enum) {
			if ($v eq $value) {
				$found = true;
			}
		}
		if (!$found) {
			$line->log_warning("\"${value}\" is not valid for ${varname}. Use one of ${type} instead.");
		}

	} else {
		$line->log_fatal("Type ${type} unknown.");
	}
}

sub checkline_Makefile_vartype($$) {
	my ($line, $vartypes) = @_;
	if ($line->text =~ regex_varassign) {
		my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);
		my $varbase = ($varname =~ qr"(.+?)\..*") ? $1 : $varname;
		my $type = exists($vartypes->{$varname}) ? $vartypes->{$varname}
			: exists($vartypes->{$varbase}) ? $vartypes->{$varbase}
			: undef;

		if ($op eq "+=") {
			if ($varbase !~ qr"^_" && $varbase !~ get_regex_plurals()) {
				$line->log_warning("As ${varname} is modified using \"+=\", its name should indicate plural.");
			}
		}

		if (!defined($type)) {
			if ($varname !~ qr"_MK$") {
				$line->log_info("[checkline_Makefile_vartype] Unchecked variable ${varname}.");
			}

		} elsif ($type =~ qr"^List(!?)(\+?)(?: of (.*))?$") {
			my ($internal_list, $append_only, $element_type) = ($1 eq "!", $2 eq "+", $3);
			my (@words, $rest);

			if ($append_only && $op ne "+=" && $op ne "?=" && !($value eq "" && defined($comment) && $comment =~ qr"^#")) {
				$line->log_warning("${varname} should be modified using \"+=\".");
			}

			if ($internal_list) {
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
				if (defined($element_type)) {
					checkline_basic_vartype($line, $varname, $element_type, $word, $comment);
				}
			}

			if ($rest !~ qr"^\s*$") {
				$line->log_warning("Invalid shell word \"${value}\" at the end.");
			}

		} else {
			checkline_basic_vartype($line, $varname, $type, $value, $comment);
		}
	}
}

#
# Procedures to check an array of lines, part 3.
#

my $checklines_Makefile_varuse_map = undef;
sub checklines_Makefile_varuse($) {
	my ($lines) = @_;

	# Check variable name quoting
	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^[^#]*[^\$]\$(\w+)") {
			my ($varname) = ($1);
			$line->log_warning("\$$varname is ambiguous. Use \${$varname} if you mean a Makefile variable or \$\$$varname if you mean a shell variable.");
		}
	}

	return if (!$opt_warn_types);

	# Load variable type definitions
	if (!defined($checklines_Makefile_varuse_map)) {
		$checklines_Makefile_varuse_map = load_make_vars_typemap();
	}
	return if (!$checklines_Makefile_varuse_map);

	# Check variable types
	foreach my $line (@{$lines}) {
		checkline_Makefile_vartype($line, $checklines_Makefile_varuse_map);
	}
}

sub checklines_deprecated_variables($) {
	my ($lines) = @_;
	my ($fname) = (conf_datadir."/deprecated.map");
	my ($deprecated, $varnames, $varuse_regex, %vars);

	if (!($deprecated = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	%vars = ();
	foreach my $line (@{$deprecated}) {
		if ($line->text =~ qr"^#" || $line->text =~ qr"^\s*$") {
			next;

		} elsif ($line->text =~ qr"^(\S+)\s+(.*)$") {
			$vars{$1} = $2;

		} else {
			$line->log_fatal("Unknown line format.");
		}
	}
	$varnames = join("|", sort(keys(%vars)));
	$varuse_regex = qr"\$\{(${varnames})[:}]";

	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_varassign) {
			my ($varname, undef, $value) = ($1, $2, $3);
			if (exists($vars{$varname})) {
				$line->log_warning("${varname} is deprecated. $vars{$varname}");
			}

			if ($value =~ $varuse_regex) {
				my ($varuse_name) = ($1);
				$line->log_warning("Use of ${varuse_name} is deprecated. $vars{$varuse_name}");
			}
		}
	}
}

sub checklines_direct_tools($) {
	my ($subr) = "checklines_direct_tools";
	my ($lines) = @_;

	return if (!$opt_warn_directcmd);

	log_info(NO_FILE, NO_LINE_NUMBER, "Checking direct use of tool names.");

	my @tools = qw(
		awk
		basename
		cat chgrp chmod chown cmp cp cut
		digest dirname
		echo egrep
		false file find
		gmake grep gtar gzcat
		id ident install
		ldconfig ln
		md5 mkdir mtree mv
		patch pax pkg_add pkg_create pkg_delete pkg_info
		rm rmdir sed setenv sh sort su
		tail test touch tr true type
		wc
		xmkmf
	);
	my @cmd_tools = qw(
		file gunzip gzip);
	my $tools = join("|", @tools, @cmd_tools);
	my $regex_tools = qr"${tools}";
	my $regex_tools_with_context = qr"(?:^|\s|/)($regex_tools)(?:\s|$)";

	my @ok_vars = qw(
		BUILDLINK_TRANSFORM BUILD_DEPENDS
		CFLAGS CPPFLAGS COMMENT CONFLICTS
		DEPENDS DISTNAME
		EXTRACT_SUFX EXTRACT_USING
		INTERACTIVE_STAGE
		MANSOURCEPATH MASTER_SITES
		PKGNAME PKGSRC_USE_TOOLS PKG_FAIL_REASON
		SUBST_CLASSES
		SUBST_MESSAGE\\..*
		.*_TARGET
		USE_TOOLS);
	my @valid_shellcmds = (
		qr"for file in",
		qr"[.}]/${regex_tools}\b",
		qr"(?:\./Build|\$\{(?:BJAM_CMD|JAM_COMMAND)\})\s+(?:install|test)",
		qr"\$\{(?:GMAKE|MAKE_PROGRAM)\}\s+(?:install)",
		qr"\"[^\"]*${regex_tools}[^\"]*\"",
		qr"\'[^\']*${regex_tools}[^\']*\'",
		qr"#.*",
	);

	my %toolvar = ();
	foreach my $tool (@tools) {
		$toolvar{$tool} = uc($tool);
	}
	foreach my $tool (@cmd_tools) {
		$toolvar{$tool} = uc($tool)."_CMD";
	}

	my $ok_vars = join("|", @ok_vars);
	my $regex_ok_vars = qr"^(?:${ok_vars})$";
	my $valid_shellcmds = join("|", @valid_shellcmds);
	my $regex_valid_shellcmds = qr"(?:${valid_shellcmds})";

	log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] regex_tools=${regex_tools}");
	log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] regex_ok_vars=${regex_ok_vars}");
	log_debug(NO_FILE, NO_LINE_NUMBER, "[${subr}] regex_valid_shellcmds=${regex_valid_shellcmds}");

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		next unless ($text =~ $regex_tools_with_context);
		my ($tool) = ($1);

		# skip comments
		if ($text =~ qr"^#") {

		# process variable assignments
		} elsif ($text =~ regex_varassign) {
			my ($varname, undef, $varvalue) = ($1, $2, $3);

			if ($varname =~ $regex_ok_vars) {
				$line->log_info("Legitimate direct use of tool \"${tool}\" in variable ${varname}.");
			} elsif ($varvalue =~ $regex_tools_with_context) {
				$line->log_warning("Possible direct use of tool \"${tool}\" in variable ${varname}. Please use \$\{$toolvar{$tool}\} instead.");
			} else {
				# the tool name has appeared in the comment
			}

		# process shell commands
		} elsif ($text =~ regex_shellcmd) {
			my ($shellcmd) = ($1);
			my ($short_shellcmd, $remaining_shellcmd) = ($shellcmd, $shellcmd);

			# Remove known legitimate uses from the string
			$remaining_shellcmd =~ s,$regex_valid_shellcmds,,g;

			# As shell commands tend to become long, extract
			# the relevant part only.
			if ($short_shellcmd =~ qr"(.{0,15})\Q${tool}\E(.{0,15})") {
				my ($before, $after) = ($1, $2);

				if (length($before) == 15) {
					$before = "...${before}";
				}
				if (length($after) == 15) {
					$after = "${after}...";
				}
				$short_shellcmd = "${before}${tool}${after}";
			}

			if ($remaining_shellcmd =~ $regex_tools_with_context) {
				$line->log_warning("Possible direct use of tool \"${tool}\" in shell command \"${short_shellcmd}\". Please use \$\{$toolvar{$tool}\} instead.");
			} else {
				$line->log_info("Legitimate direct use of tool \"${tool}\" in shell command \"${short_shellcmd}\".");
			}

		# skip processing directives
		} elsif ($text =~ qr"^\.") {

		# skip dependency specifications
		} elsif ($text =~ qr"^([-\w.]+):") {

		} else {
			$line->log_error("[internal:checklines_direct_tools] unknown line format.");
		}
	}
}

sub checklines_package_Makefile_varorder($) {
	my ($lines) = @_;

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
				[ "DISTFILES", optional ],
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
				$line->log_warning(sprintf("Expected %s, but found %s.", $vars->[$varindex]->[0], $varname));
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
					$line->log_warning(sprintf("%s should be set here.", $vars->[$varindex]->[0]));
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

# This subroutine contains "local" checks that can be made looking only
# at a single line at a time. The other checks are in
# checkfile_package_Makefile.
sub checklines_package_Makefile($) {
	my ($lines) = @_;
	my ($allowed_targets, $for_variables) = ({}, {});

	foreach my $prefix (qw(pre do post)) {
		foreach my $action (qw(fetch extract patch tools wrapper configure build test install package clean)) {
			$allowed_targets->{"${prefix}-${action}"} = true;
		}
	}

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($line->lines eq "1") {
			checkline_rcsid_regex($line, qr"#\s+", "# ");
		}

		checkline_trailing_whitespace($line);

		if ($text =~ /^\040{8}/) {
			$line->log_warning("Please use tab (not spaces) to make indentation.");
		}

		if ($text =~ qr"\$\{WRKSRC\}/\.\./") {
			$line->log_error("Using \"\${WRKSRC}/..\" is conceptually wrong. Use a combination of WRKSRC, CONFIGURE_DIRS and BUILD_DIRS instead.");
		}

		if ($text =~ qr"^\s*$" || $text =~ qr"^#") {
			# Ignore empty lines and comments

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			if ($varname =~ qr"^_") {
				$line->log_error("Variable names starting with an underscore are reserved for internal pkgsrc use.");
			}

			if ($varname eq "PERL5_PACKLIST" && defined($pkgname) && $pkgname !~ regex_unresolved && $pkgname =~ qr"^p5-(.*)-[0-9].*") {
				my ($guess) = ($1);
				$guess =~ s/-/\//g;
				$guess = "auto/${guess}/.packlist";

				my ($ucvalue, $ucguess) = (uc($value), uc($guess));
				if ($ucvalue ne $ucguess && $ucvalue ne "\${PERL5_SITEARCH\}/${ucguess}") {
					$line->log_warning("Unusual value for PERL5_PACKLIST -- \"${guess}\" expected.");
				}
			}

			if ($varname eq "SVR4_PKGNAME") {
				if ($value =~ regex_unresolved) {
					$line->log_error("SVR4_PKGNAME must not contain references to other variables.");
				} elsif (length($value) > 5) {
					$line->log_error("SVR4_PKGNAME must not be longer than 5 characters.");
				}
			}

			if (defined($comment) && $comment eq "# defined" && $varname !~ qr".*(?:_MK|_COMMON)$") {
				$line->log_warning("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
			}

			if ($varname =~ qr"^NO_(.*)_ON_(.*)$") {
				my ($what, $where) = ($1, $2);
				if (($what ne "SRC" && $what ne "BIN") || ($where ne "FTP" && $where ne "CDROM")) {
					$line->log_error("Misspelled variable: Valid names are USE_{BIN,SRC}_ON_{FTP,CDROM}.");
				}
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

		} elsif ($text =~ regex_shellcmd) {
			my ($shellcmd) = ($1);
			my ($rest, $state);

			use constant SCST_START		=>  0;
			use constant SCST_INSTALL	=> 10;
			use constant SCST_INSTALL_D	=> 11;
			use constant SCST_MKDIR		=> 20;
			use constant SCST_PAX		=> 30;
			use constant SCST_PAX_S		=> 31;
			use constant SCST_SED		=> 40;
			use constant SCST_SED_E		=> 41;

			if ($shellcmd =~ qr"^\@*-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)") {
				my ($mkdir_cmd) = ($1);

				$line->log_note("You don't need to use \"-\" before ${mkdir_cmd}.");
			}

			$rest = $shellcmd;
			$state = SCST_START;
			while ($rest =~ s/^$regex_shellword//) {
				my ($shellword) = ($1);

				#
				# Actions associated with the current state
				# and the symbol on the "input tape".
				#

				if (($state != SCST_PAX_S && $state != SCST_SED_E) && $shellword =~ qr"^/" && $shellword ne "/dev/null") {
					$line->log_warning("Found absolute pathname: ${shellword}");
					$line->explain(
						"Absolute pathnames are often an indicator for unportable code. As",
						"pkgsrc aims to be a portable system, absolute pathnames should be",
						"avoided whenever possible.");
				}

				if (($state == SCST_INSTALL_D || $state == SCST_MKDIR) && $shellword =~ qr"^\$\{PREFIX\}/") {
					$line->log_warning("Please use one of the INSTALL_*_DIR commands instead of "
						. (($state == SCST_MKDIR) ? "\${MKDIR}" : "\${INSTALL} -d")
						. ".");
					$line->explain(
						"Choose one of INSTALL_PROGRAM_DIR, INSTALL_SCRIPT_DIR, INSTALL_LIB_DIR,",
						"INSTALL_MAN_DIR, INSTALL_DATA_DIR.");
				}

				#
				# State transition.
				#

				if ($shellword =~ qr"^[;&\|]+$") {
					$state = SCST_START;

				} elsif ($state == SCST_START) {
					if ($shellword eq "\${INSTALL}") {
						$state = SCST_INSTALL;
					} elsif ($shellword eq "\${MKDIR}") {
						$state = SCST_MKDIR;
					} elsif ($shellword eq "\${PAX}") {
						$state = SCST_PAX;
					} elsif ($shellword eq "\${SED}") {
						$state = SCST_SED;
					}

				} elsif ($state == SCST_INSTALL && $shellword eq "-d") {
					$state = SCST_INSTALL_D;

				} elsif (($state == SCST_INSTALL || $state == SCST_INSTALL_D) && $shellword =~ qr"^-[ogm]$") {
					$state = SCST_START;

				} elsif ($state == SCST_PAX && $shellword eq "-s") {
					$state = SCST_PAX_S;

				} elsif ($state == SCST_PAX_S) {
					$state = SCST_PAX;

				} elsif ($state == SCST_SED && $shellword eq "-e") {
					$state = SCST_SED_E;

				} elsif ($state == SCST_SED_E) {
					$state = SCST_SED;

				}
			}

			if ($rest !~ qr"^\s*$") {
				$line->log_warning("Invalid shell word \"${shellcmd}\".");
			}

		} elsif ($text =~ regex_mk_include) {
			my ($includefile) = ($1);

			$line->log_debug("includefile=${includefile}");
			checkline_relative_path($line, $includefile);

		} elsif ($text =~ qr"^\.\s*(if|ifdef|ifndef|else|elif|endif|for|endfor|undef)(?:\s+([^\s#][^#]*?))?\s*(?:#.*)?$") {
			my ($directive, $args) = ($1, $2);

			use constant regex_directives_with_args => qr"^(?:if|ifdef|ifndef|elif|for|undef)$";

			if ($directive =~ regex_directives_with_args && !defined($args)) {
				$line->log_error("\".${directive}\" must be given some arguments.");

			} elsif ($directive !~ regex_directives_with_args && defined($args)) {
				$line->log_error("\".${directive}\" does not take arguments.");

				if ($directive eq "else") {
					$line->log_note("If you meant \"else if\", use \".elif\".");
				}

			} elsif ($directive eq "if" || $directive eq "elif") {
				# TODO

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

					foreach my $var ($vars) {
						$for_variables->{$var} = true;
					}
				}

			} elsif ($directive eq "undef" && defined($args)) {
				my $all_unnecessary = true;
				foreach my $var (split(qr"\s+", $args)) {
					if (exists($for_variables->{$var})) {
						$line->log_note("Using \".undef\" after a \".for\" loop is unnecessary.");
					} else {
						$all_unnecessary = false;
					}
				}
				if ($all_unnecessary) {
					$line->delete();
				}
			}

		} elsif ($text =~ regex_mk_dependency) {
			my ($targets, $dependencies) = ($1, $2);

			$line->log_debug("targets=${targets}, dependencies=${dependencies}");
			foreach my $target (split(/\s+/, $targets)) {
				if ($target eq ".PHONY") {
					foreach my $dep (split(qr"\s+", $dependencies)) {
						$allowed_targets->{$dep} = true;
					}

				} elsif (!exists($allowed_targets->{$target})) {
					$line->log_warning("Unusual target \"${target}\".");
					$line->explain(
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
			$line->explain(
				"If you want this line to contain a shell program, use a tab",
				"character for indentation. Otherwise please remove the leading",
				"white-space.");

		} else {
			$line->log_error("[Internal] Unknown line format: $text");
		}
	}

	checklines_trailing_empty_lines($lines);
}

#
# Miscellaneous procedures.
#

sub expand_variable($$) {
	my ($whole, $varname) = @_;
	my ($value, $re);

	$re = qr"\n${varname}([+:?]?)=[ \t]*([^\n#]*)";
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

	$value = resolve_relative_path($value);
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

#
# Loading data from package-specific files, part 2.
#

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
			printf("%s\n", $line->to_string());
		}
	}

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
# Procedures to check a file, part 3.
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

sub checkfile_mk($) {
	my ($fname) = @_;
	my ($lines);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_mk]");

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	checklines_deprecated_variables($lines);
	checklines_direct_tools($lines);
	checklines_package_Makefile($lines);
	checklines_Makefile_varuse($lines);
	autofix($lines);
}

sub checkfile_package_Makefile($$$) {
	my ($fname, $whole, $lines) = @_;
	my ($distname, $distfiles);

	log_info($fname, NO_LINE_NUMBER, "[checkfile_package_Makefile]");

	checkperms($fname);

	# TODO: "Please use \${VARIABLE} instead of \$(VARIABLE)."

	checklines_deprecated_variables($lines);

	if (!exists($makevar->{"PLIST_SRC"})
	    && !exists($makevar->{"NO_PKG_REGISTER"})
	    && !-f "${current_dir}/$pkgdir/PLIST"
	    && !-f "${current_dir}/$pkgdir/PLIST.common") {
		log_warning($fname, NO_LINE_NUMBER, "Neither PLIST nor PLIST.common exist, and PLIST_SRC and NO_PKG_REGISTER are unset. Are you sure PLIST handling is ok?");
	}

	if (exists($makevar->{"NO_CHECKSUM"})) {
		if (-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM is set.");
		}
	} else {
		if (!-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makesum'.");
		}
	}

	checklines_direct_tools($lines);

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

	# check DISTFILES and related items.
	$distname     = expand_variable($whole, "DISTNAME");
	$pkgname      = expand_variable($whole, "PKGNAME");
	$distfiles    = expand_variable($whole, "DISTFILES");

	if (defined($pkgname) && defined($distname) && ($pkgname eq $distname || $pkgname eq "\${DISTNAME}")) {
		log_note($fname, NO_LINE_NUMBER, "PKGNAME is \${DISTNAME} by default. You don't need to define PKGNAME.");
	}

	if (!defined($pkgname) && defined($distname) && $distname !~ regex_unresolved && $distname !~ regex_pkgname) {
		log_warning($fname, NO_LINE_NUMBER, "As DISTNAME ist not a valid package name, please define the PKGNAME explicitly.");
	}

	if (!defined($pkgname)) {
		$pkgname = $distname;
	}

	if (!exists($makevar->{"COMMENT"})) {
		log_warning($fname, NO_LINE_NUMBER, "No COMMENT given.");
	}

	if (exists($makevar->{"USE_IMAKE"}) && exists($makevar->{"USE_X11"})) {
		$makevar->{"USE_IMAKE"}->log_note("USE_IMAKE makes ...");
		$makevar->{"USE_X11"}->log_note("... USE_X11 superfluous.");
	}

	checklines_package_Makefile($lines);
	# Disabled, as I don't like the current ordering scheme.
	#checklines_package_Makefile_varorder($lines);
	checklines_Makefile_varuse($lines);
	autofix($lines);
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

	} elsif (!S_ISREG($st->mode)) {
		log_error($fname, NO_LINE_NUMBER, "Only files and directories are allowed in pkgsrc.");

	} elsif ($basename eq "ALTERNATIVES") {
		$opt_check_ALTERNATIVES and checkfile_ALTERNATIVES($fname);

	} elsif ($basename eq "buildlink3.mk") {
		$opt_check_bl3 and checkfile_mk($fname);

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
		$opt_check_patches and checkfile_patches_patch($fname);

	} elsif ($fname =~ qr"(?:^|/)patches/[^/]*$") {
		log_warning($fname, NO_LINE_NUMBER, "Patch files should be named \"patch-\", followed by letters and digits only.");

	} elsif ($basename =~ qr"^PLIST") {
		$opt_check_PLIST and checkfile_PLIST($fname);

	} elsif ($basename eq "TODO") {
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
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

	# Then comes the COMMENT line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^COMMENT=\t*(.*)") {
		my ($comment) = ($1);

		checkline_valid_characters_in_variable($lines->[$lineno], qr"[-\040'(),/0-9A-Za-z]");
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("COMMENT= line expected.");
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

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
	$pkgdir			= ".";
	$filesdir		= "files";
	$patchdir		= "patches";
	$distinfo_file		= "distinfo";
	$makevar		= undef;
	$seen_Makefile_common	= undef;
	$pkgname		= undef;
	$hack_php_patches	= false;

	$current_dir = $is_dir ? $item : dirname($item);
	$is_wip = !$opt_import && (Cwd::abs_path($current_dir) =~ qr"/wip(?:/|$)");

	if (-f "${current_dir}/../../mk/bsd.pkg.mk") {
		$pkgsrcdir = "${current_dir}/../..";
		if ($is_dir) {
			checkdir_package();
		}

	} elsif (-f "${current_dir}/../mk/bsd.pkg.mk") {
		$pkgsrcdir = "${current_dir}/..";
		if ($is_dir) {
			checkdir_category();
		}

	} elsif (-f "${current_dir}/mk/bsd.pkg.mk") {
		$pkgsrcdir = $current_dir;
		if ($is_dir) {
			checkdir_root();
		}
	} else {
		log_error($item, NO_LINE_NUMBER, sprintf("Don't know how to check this %s.", ($is_dir) ? "directory" : "file"));
		return;
	}

	if ($is_reg) {
		checkfile($item);
	}
}

#
# The main program
#

sub main() {

	parse_command_line();

	@todo_items = (@ARGV != 0) ? @ARGV : (".");
	while (@todo_items != 0) {
		checkitem(shift(@todo_items));
	}

	PkgLint::Logging::print_summary_and_exit($opt_quiet);
}

main();
