#! @PERL@
# $NetBSD: pkglint.pl,v 1.8 2019/10/06 10:46:18 rillig Exp $
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

# To get an overview of the code, run:
#    sed -n -e 's,^\(sub .*\) {.*,  \1,p' -e '/^package/p' pkglint.pl

#==========================================================================
# Note: The @EXPORT clauses in the packages must be in a BEGIN block,
# because otherwise the names starting with an uppercase letter are not
# recognized as subroutines but as file handles.
#==========================================================================

use v5.12;
use warnings;

#include PkgLint/Util.pm
#include PkgLint/Logging.pm
#include PkgLint/SimpleMatch.pm
#include PkgLint/Line.pm
#include PkgLint/FileUtil.pm
#include PkgLint/Type.pm
#include PkgLint/VarUseContext.pm
#include PkgLint/SubstContext.pm
#include PkgLint/CVS_Entry.pm
#include PkgLint/Change.pm

package pkglint;
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

use Data::Dumper;
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
our $opt_warn_extra	= false;	# used by PkgLint::SubstContext
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
);

our $program		= $0;

#
# Commonly used regular expressions.
#

use constant regex_dependency_lge => qr"^((?:\$\{[\w_]+\}|[\w_\.+]|-[^\d])+)[<>]=?(\d[^-*?\[\]]*)$";
use constant regex_dependency_wildcard
				=> qr"^((?:\$\{[\w_]+\}|[\w_\.+]|-[^\d\[])+)-(?:\[0-9\]\*|\d[^-]*)$";
use constant regex_gnu_configure_volatile_vars
				=> qr"^(?:.*_)?(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$";
use constant regex_mk_comment	=> qr"^ *\s*#(.*)$";
use constant regex_mk_cond	=> qr"^\.(\s*)(if|ifdef|ifndef|else|elif|endif|for|endfor|undef)(?:\s+([^\s#][^#]*?))?\s*(?:#.*)?$";
use constant regex_mk_dependency=> qr"^([^\s:]+(?:\s*[^\s:]+)*)(\s*):\s*([^#]*?)(?:\s*#.*)?$";
use constant regex_mk_include	=> qr"^\.\s*(s?include)\s+\"([^\"]+)\"\s*(?:#.*)?$";
use constant regex_mk_sysinclude=> qr"^\.\s*s?include\s+<([^>]+)>\s*(?:#.*)?$";
use constant regex_mk_shellvaruse => qr"(?:^|[^\$])\$\$\{?(\w+)\}?"; # XXX: not perfect
use constant regex_pkgname	=> qr"^([\w\-.+]+)-(\d(?:\w|\.\d)*)$";
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
	|	\$\$\$\$		# the special pid shell variable
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
my %ipc_used_licenses;		# { license name => true }
my $ipc_checking_root_recursively; # For checking unused licenses

# Context of the package that is currently checked.
my $pkgpath;			# The relative path to the package within PKGSRC
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
my $pkgctx_bl3;			# { buildlink3.mk name => line } (contains
				# only buildlink3.mk files that are directly
				# included)
my $pkgctx_plist_subst_cond;	# { varname => 1 } list of all variables
				# that are used as conditionals (@comment
				# or nothing) in PLISTs.
my $pkgctx_included;		# { fname => line }
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
my $mkctx_plist_vars;		# The same for PLIST_VARS.
my $mkctx_tools;		# Set of tools that are declared to be used.

my @todo_items;			# The list of directory entries that still need
				# to be checked. Mostly relevant with
				# --recursive.

#
# Command line parsing and handling.
#

sub help($$$) {
	my ($out, $exitval, $show_all) = @_;
	my ($prog) = (basename($program, '.pl'));
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
sub get_regex_plurals() {
	state $result = undef;
	return $result if defined($result);

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
		BROKEN_EXCEPT_ON_PLATFORM
		BROKEN_ON_PLATFORM
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

	$result = qr"^(?:${plurals})$";
	return $result;
}

#
# Loading pkglint-specific data from files.
#

sub load_existing_lines($$) {
	my ($fname, $fold_backslash_lines) = @_;

	my $lines = load_lines($fname, $fold_backslash_lines)
		or log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	return $lines;
}

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

sub get_vartypes_basictypes() {
	state $result = undef;
	return $result if defined($result);

	my $lines = load_file($program);
	my $types = {};
	assert($lines, "Couldn't load pkglint.pl from $program");
	foreach my $line (@$lines) {
		if ($line->text =~ m"^\s+(\w+) => sub \{$") {
			# XXX lookup in %type_dispatch instead
			$types->{$1} = 1;
		}
	}
	return ($result = $types);
}

sub get_vartypes_map() {
	state $result = undef;
	return $result if defined($result);

	my ($fname, $vartypes);

	use constant re_acl_def => qr"^
		acl \s+
		(\w+) \s+				# ACL name
		= \s+
		\[ ([^\]]*) \]				# ACL value
		(?:\s*\#.*)?				# optional comment
		$"x;

	use constant re_vartypedef => qr"^
		([\w\d_.]+?)				# $1 = variable name
		(\*|\.\*|) \s+				# $2 = parameterized?
		(?:(InternalList|List) \s+ of \s+)?	# $3 ?= kind of list
		(?:([\w\d_]+)				# $4 ?= basic type
		  | \{\s*([\w\d_+,\-.\s]+?)\s*\})	# $5 ?= enumeration values
		(?:\s+ \[ ([^\]]*) \])?			# $6 ?= optional ACL
		(?:\s*\#.*)?				# $7 ?= optional comment
		$"x;

	$fname = conf_datadir."/makevars.map";
	$vartypes = {};

	my $lines = load_existing_lines($fname, true);
	foreach my $line (@{$lines}) {
		if ($line->text =~ m"^(?:#.*|\s*)$") {
			# ignore empty and comment lines

		} elsif ($line->text =~ re_acl_def) {
			my ($aclname, $aclvalue) = ($1, $2);

			$acl_definitions->{$aclname} = parse_acls($line, $aclvalue);

		} elsif ($line->text =~ re_vartypedef) {
			my ($varname, $par, $kind_of_list_text, $typename, $enums, $acltext) = ($1, $2, $3, $4, $5, $6);
			my $kind_of_list = !defined($kind_of_list_text) ? LK_NONE
			    : ($kind_of_list_text eq "List") ? LK_EXTERNAL
			    : LK_INTERNAL;

			if (defined($typename) && !exists(get_vartypes_basictypes()->{$typename})) {
				$line->log_fatal("Unknown basic type \"$typename\" for variable $varname. "
					. "Valid basic types are "
					. join(", ", sort keys %{get_vartypes_basictypes()})
					. ".");
			}

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

# TODO: Enable when the time is ripe.
if (false) {
	# Additionally, scan mk/defaults/mk.conf for variable
	# definitions. All these variables are reserved for the user and
	# must not be set within packages.
	$fname = "${cwd_pkgsrcdir}/mk/defaults/mk.conf";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ m"^#?([\w_]+)\?=") {
				my ($varname) = ($1);
				$opt_debug_misc and $line->log_debug("Found user-definable variable ${varname}.");
				$vartypes->{$varname} = "Userdefined"; # FIXME: type error
			}
		}
	} else {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}
}

	return ($result = $vartypes);
}

sub get_deprecated_map() {
	state $result = undef;
	return $result if defined($result);

	my ($fname, $lines, $vars);

	$fname = conf_datadir."/deprecated.map";
	if (!($lines = load_file($fname))) {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

	$vars = {};
	foreach my $line (@{$lines}) {
		if ($line->text =~ m"^#" || $line->text =~ m"^\s*$") {
			# Ignore empty and comment lines.

		} elsif ($line->text =~ m"^(\S+)\s+(.*)$") {
			$vars->{$1} = $2;

		} else {
			$line->log_fatal("Unknown line format.");
		}
	}
	return ($result = $vars);
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

		if ($text =~ m"^(MASTER_SITE_\w+)\+=\s*\\$"o) {
			$varname = $1;
			$names->{$varname} = true;
			$ignoring = false;

		} elsif ($text eq "MASTER_SITE_BACKUP?=\t\\") {
			$ignoring = true;

		} elsif ($text =~ m"^\t((?:http://|https://|ftp://)\S+/)(?:|\s*\\)$"o) {
			if (!$ignoring) {
				if (defined($varname)) {
					$url2name->{$1} = $varname;
				} else {
					$line->log_error("Lonely URL found.");
				}
			}

		} elsif ($text =~ m"^(?:#.*|\s*)$") {
			# ignore empty and comment lines

		} elsif ($text =~ m"BSD_SITES_MK") {
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

sub get_pkg_options() {
	state $result = undef;
	return $result if defined($result);

	my ($fname) = ("${cwd_pkgsrcdir}/mk/defaults/options.description");
	my ($lines, $options);

	if (!($lines = load_file($fname))) {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

	$options = {};
	foreach my $line (@{$lines}) {
		if ($line->text =~ m"^([-0-9a-z_+]+)(?:\s+(.*))?$") {
			my ($optname, $optdescr) = ($1, $2);

			$options->{$optname} = defined($optdescr)
			    ? $optdescr
			    : "";
		} else {
			$line->log_error("Unknown line format.");
		}
	}

	return ($result = $options);
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
		my $lines = load_existing_lines($fname, true);
		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_mk_include) {
				my (undef, $includefile) = ($1, $2);
				if ($includefile =~ m"^(?:\$\{PKGSRCDIR\}/mk/tools/)?([^/]+)$") {
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
		my $lines = load_existing_lines($fname, true);
		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);
				if ($varname eq "TOOLS_CREATE" && $value =~ m"^([-\w.]+|\[)$") {
					$tools->{$value} = true;

				} elsif ($varname =~ m"^(?:_TOOLS_VARNAME)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;
					$vartools->{$1} = $value;
					$varname_to_toolname->{$value} = $1;

				} elsif ($varname =~ m"^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;

				} elsif ($varname =~ m"^_TOOLS\.(.*)") {
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
		my $cond_depth = 0;

		my $lines = load_existing_lines($fname, true);
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

				if ($cond =~ m"^(?:if|ifdef|ifndef|for)$") {
					$cond_depth++;
				} elsif ($cond =~ m"^(?:endif|endfor)$") {
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
	foreach my $bdvar (qw(DISTDIR FETCH_CMD FETCH_OUTPUT_ARGS GAMES_USER GAMES_GROUP GAMEDATAMODE GAMEDIRMODE GAMEMODE GAMEOWN GAMEGRP )) {
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
			if ($text =~ m"^\to\s(\S+)(?:\s*(.+))?$") {
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

sub get_doc_TODO_updates() {
	state $result = load_doc_TODO_updates("${cwd_pkgsrcdir}/doc/TODO");
	return $result;
}

sub get_wip_TODO_updates() {
	state $result = load_doc_TODO_updates("${cwd_pkgsrcdir}/wip/TODO");
	return $result;
}

sub load_doc_CHANGES($) {
	my ($fname) = @_;
	my $lines = load_file($fname) or die;

	my $changes = {}; # { pkgpath -> @changes }
	foreach my $line (@$lines) {
		my $text = $line->text;
		next unless $text =~ m"^\t[A-Z]";

		if ($text =~ m"^\t(Updated) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$") {
			push(@{$changes->{$2}}, PkgLint::Change->new($line, $1, $2, $3, $4, $5));
		} elsif ($text =~ m"^\t(Added) (\S+) version (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$") {
			push(@{$changes->{$2}}, PkgLint::Change->new($line, $1, $2, $3, $4, $5));
		} elsif ($text =~ m"^\t(Removed) (\S+) (?:successor (\S+) )?\[(\S+) (\d\d\d\d-\d\d-\d\d)\]$") {
			push(@{$changes->{$2}}, PkgLint::Change->new($line, $1, $2, undef, $3, $4));
		} elsif ($text =~ m"^\t(Downgraded) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$") {
			push(@{$changes->{$2}}, PkgLint::Change->new($line, $1, $2, $3, $4, $5));
		} elsif ($text =~ m"^\t(Renamed|Moved) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$") {
			push(@{$changes->{$2}}, PkgLint::Change->new($line, $1, $2, $3, $4, $5));
		} else {
			$line->log_warning("Unknown doc/CHANGES line: " . $line->text);
			$line->explain_warning(
"Maybe some developer didn't stick to the conventions that have been",
"established by mk/misc/developer.mk?");
		}
	}
	return $changes;
}

my $get_doc_CHANGES_docs = undef; # [ $fname, undef or { pkgpath -> @changes } ]
sub get_doc_CHANGES($) {
	my ($pkgpath) = @_;

	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "get_doc_CHANGES(\"$pkgpath\")");

	# Make a reversed list of all the CHANGES-* files, but don't load
	# them yet.
	if (!defined($get_doc_CHANGES_docs)) {
		opendir(DIR, "${cwd_pkgsrcdir}/doc") or die;
		my @files = readdir(DIR);
		closedir(DIR) or die;
		foreach my $file (reverse sort @files) {
			if ($file =~ m"^CHANGES-(\d+)$" && (0 + $1 >= 2008)) {
				push(@$get_doc_CHANGES_docs, [ $file, undef ]);
			}
		}
		$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "Found " . (scalar @$get_doc_CHANGES_docs) . " changes files.");
	}

	# Scan the *-CHANGES files in reverse order until some action
	# matches the package directory.
	my @result = ();
	foreach my $doc (@$get_doc_CHANGES_docs) {
		if (!defined($doc->[1])) {
			$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "loading $doc->[0]");
			$doc->[1] = load_doc_CHANGES("${cwd_pkgsrcdir}/doc/$doc->[0]");
		}

		foreach my $change (@{$doc->[1]->{$pkgpath}}) {
			next unless $pkgpath eq $change->pkgpath;
			push(@result, $change);
		}
		if (@result != 0) {
			return @result;
		}
	}
	return ();
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
	my $vars = {};

	my $lines = load_existing_lines($fname, true);
	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			$vars->{$varname} = $line;
		}
	}

	return $vars;
}

sub get_userdefined_variables() {
	state $result = load_userdefined_variables();
	return $result;
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
		if ($entry->text =~ m"^/\Q${basename}\E/") {
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
	my @subdirs = readdir(DIR);
	closedir(DIR) or die;

	$rv = true;
	foreach my $subdir (@subdirs) {
		next if $subdir eq "." || $subdir eq ".." || $subdir eq "CVS";
		next if -d "${dir}/${subdir}" && is_emptydir("${dir}/${subdir}");

		$rv = false;
		last;
	}

	return $rv;
}

# Returns the list of subdirectories of a directory, except "CVS".
sub get_subdirs($) {
	my ($dir) = @_;
	my (@result) = ();

	if (opendir(DIR, $dir)) {
		my @subdirs = readdir(DIR);
		closedir(DIR) or die;
		foreach my $subdir (@subdirs) {
			if ($subdir ne "." && $subdir ne ".." && $subdir ne "CVS" && -d "${dir}/${subdir}" && !is_emptydir("${dir}/${subdir}")) {
				push(@result, $subdir);
			}
		}
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
	$relpath =~ s,\$\{LUA_PKGSRCDIR\},../../lang/lua52,;
	$relpath =~ s,\$\{PHPPKGSRCDIR\},../../lang/php55,;
	$relpath =~ s,\$\{SUSE_DIR_PREFIX\},suse100,;
	$relpath =~ s,\$\{PYPKGSRCDIR\},../../lang/python27,;
	$relpath =~ s,\$\{FILESDIR\},$filesdir, if defined($filesdir);
	if ($adjust_depth && $relpath =~ m"^\.\./\.\./([^.].*)$") {
		$relpath = "${cur_pkgsrcdir}/$1";
	}
	if (defined($pkgdir)) {
		$relpath =~ s,\$\{PKGDIR\},$pkgdir,g;
	}

	$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "resolve_relative_path: $arg => $relpath");
	return $relpath;
}

# Takes two pathnames and returns the relative pathname to get from
# the first to the second.
sub relative_path($$) {
	my ($from, $to) = @_;

	my $abs_from = Cwd::abs_path($from);
	my $abs_to = Cwd::abs_path($to);
	if ($abs_to =~ m"^\Q$abs_from/\E(.*)$") {
		return $1;
	} elsif ($abs_to eq $abs_from) {
		return ".";
	} else {
		assert(false, "$abs_from is not a prefix of $abs_to");
	}
}

sub resolve_variable_rec1($$);
sub resolve_variable_rec2($$);

sub resolve_variable_rec1($$) {
	my ($varname, $visited) = @_;
	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "resolve_variable_rec1($varname)");

	if (!exists($visited->{$varname})) {
		$visited->{$varname} = true;
		if (defined($pkgctx_vardef) && exists($pkgctx_vardef->{$varname})) {
			return resolve_variable_rec2($pkgctx_vardef->{$varname}->get("value"), $visited);
		}
		if (defined($mkctx_vardef) && exists($mkctx_vardef->{$varname})) {
			return resolve_variable_rec2($mkctx_vardef->{$varname}->get("value"), $visited);
		}
	}
	return "\${$varname}";
}

sub resolve_variable_rec2($$) {
	my ($string, $visited) = @_;
	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "resolve_variable_rec2(\"$string\")");

	my $expanded = $string;
	$expanded =~ s/\$\{(\w+)\}/resolve_variable_rec1($1, $visited)/eg;
	return $expanded;
}

sub expand_variable($) {
	my ($varname) = @_;

	return unless exists($pkgctx_vardef->{$varname});
	my $line = $pkgctx_vardef->{$varname};
	my $value = $line->get("value");

	$value = resolve_relative_path($value, true);
	if ($value =~ regex_unresolved) {
		$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "[expand_variable] Trying harder to resolve variable references in ${varname}=\"${value}\".");
		$value = resolve_variable_rec2($value, {});
		if ($value =~ regex_unresolved) {
			$opt_debug_misc and log_debug(NO_FILE, NO_LINES, "[expand_variable] Failed to resolve ${varname}=\"${value}\".");
		}
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

# Removes all uses of make variables from a string.
sub remove_variables($) {
	my ($text) = @_;

	while ($text =~ s/\$\{([^{}]*)\}//g) {
	}
	return $text;
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
	return (($text =~ m"^\s*$") ? $words : false);
}

sub varname_base($) {
	my ($varname) = @_;

	return ($varname =~ m"^(.*?)\..*$") ? $1 : $varname;
}

sub varname_canon($) {
	my ($varname) = @_;

	return ($varname =~ m"^(.*?)\..*$") ? "$1.*" : $varname;
}

sub varname_param($) {
	my ($varname) = @_;

	return ($varname =~ m"^.*?\.(.*)$") ? $2 : undef;
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

sub def_var($$) {
	my ($line, $varname) = @_;
	my $varcanon = varname_canon($varname);

	if (defined($mkctx_vardef)) {
		$mkctx_vardef->{$varname} = $line;
		$mkctx_vardef->{$varcanon} = $line;
	}

	if (defined($pkgctx_vardef)) {
		$pkgctx_vardef->{$varname} = $line;
		$pkgctx_vardef->{$varcanon} = $line;
	}
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
		while ($rest =~ s/(?:\$\{|\$\(|defined\(|empty\()([0-9+.A-Z_a-z]+)[:})]//) {
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

sub get_nbpart() {
	my $line = $pkgctx_vardef->{"PKGREVISION"};
	return "" unless defined($line);
	my $pkgrevision = $line->get("value");
	return "" unless $pkgrevision =~ m"^\d+$";
	return "" unless $pkgrevision + 0 != 0;
	return "nb$pkgrevision";
}

# When processing a file using the expect* subroutines below, it may
# happen that $lineno points past the end of the file. In that case,
# print the warning without associated source code.
sub lines_log_warning($$$) {
	my ($lines, $lineno, $msg) = @_;

	assert(false, "The line number is negative (${lineno}).")
		unless 0 <= $lineno;
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
		return PkgLint::SimpleMatch->new($lines->[$lineno]->text, \@-, \@+);
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

	my $rv = expect($lines, $lineno_ref, qr"^\Q${text}\E$");
	$rv or lines_log_warning($lines, ${$lineno_ref}, "Expected \"${text}\".");
	return $rv;
}

sub expect_re($$$) {
	my ($lines, $lineno_ref, $re) = @_;

	my $rv = expect($lines, $lineno_ref, $re);
	$rv or lines_log_warning($lines, ${$lineno_ref}, "Expected text matching $re.");
	return $rv;
}

# Returns an object of type Pkglint::Type that represents the type of
# the variable (maybe guessed based on the variable name), or undef if
# the type cannot even be guessed.
#
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

	if ($varname =~ m"^TOOLS_(.*)" && exists(get_varname_to_toolname()->{$1})) {
		return PkgLint::Type->new(LK_NONE, "Pathname", [[ qr".*", "u" ]], NOT_GUESSED);
	}

	use constant allow_all => [[ qr".*", "adpsu" ]];
	use constant allow_runtime => [[ qr".*", "adsu" ]];

	# Guess the datatype of the variable based on
	# naming conventions.
	$type =	  ($varname =~ m"DIRS$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", allow_runtime, GUESSED)
		: ($varname =~ m"(?:DIR|_HOME)$") ? PkgLint::Type->new(LK_NONE, "Pathname", allow_runtime, GUESSED)
		: ($varname =~ m"FILES$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathmask", allow_runtime, GUESSED)
		: ($varname =~ m"FILE$") ? PkgLint::Type->new(LK_NONE, "Pathname", allow_runtime, GUESSED)
		: ($varname =~ m"PATH$") ? PkgLint::Type->new(LK_NONE, "Pathlist", allow_runtime, GUESSED)
		: ($varname =~ m"PATHS$") ? PkgLint::Type->new(LK_EXTERNAL, "Pathname", allow_runtime, GUESSED)
		: ($varname =~ m"_USER$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", allow_all, GUESSED)
		: ($varname =~ m"_GROUP$") ? PkgLint::Type->new(LK_NONE, "UserGroupName", allow_all, GUESSED)
		: ($varname =~ m"_ENV$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ m"_CMD$") ? PkgLint::Type->new(LK_NONE, "ShellCommand", allow_runtime, GUESSED)
		: ($varname =~ m"_ARGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ m"_(?:C|CPP|CXX|LD|)FLAGS$") ? PkgLint::Type->new(LK_EXTERNAL, "ShellWord", allow_runtime, GUESSED)
		: ($varname =~ m"_MK$") ? PkgLint::Type->new(LK_NONE, "Unchecked", allow_all, GUESSED)
		: ($varname =~ m"^PLIST.") ? PkgLint::Type->new(LK_NONE, "Yes", allow_all, GUESSED)
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
		UserGroupName
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
			return doesnt_matter;

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

# Checks whether $tree matches $pattern, and if so, instanciates the
# variables in $pattern. If they don't match, some variables may be
# instanciated nevertheless, but the exact behavior is unspecified.
#
sub tree_match($$);
sub tree_match($$) {
	my ($tree, $pattern) = @_;

	my $d1 = Data::Dumper->new([$tree, $pattern])->Terse(true)->Indent(0);
	my $d2 = Data::Dumper->new([$pattern])->Terse(true)->Indent(0);
	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, sprintf("tree_match(%s, %s)", $d1->Dump, $d2->Dump));

	return true if (!defined($tree) && !defined($pattern));
	return false if (!defined($tree) || !defined($pattern));
	my $aref = ref($tree);
	my $pref = ref($pattern);
	if ($pref eq "SCALAR" && !defined($$pattern)) {
		$$pattern = $tree;
		return true;
	}
	if ($aref eq "" && ($pref eq "" || $pref eq "SCALAR")) {
		return $tree eq $pattern;
	}
	if ($aref eq "ARRAY" && $pref eq "ARRAY") {
		return false if scalar(@$tree) != scalar(@$pattern);
		for (my $i = 0; $i < scalar(@$tree); $i++) {
			return false unless tree_match($tree->[$i], $pattern->[$i]);
		}
		return true;
	}
	return false;
}

# TODO: Needs to be redesigned to handle more complex expressions.
sub parse_mk_cond($$);
sub parse_mk_cond($$) {
	my ($line, $cond) = @_;

	$opt_debug_trace and $line->log_debug("parse_mk_cond(\"${cond}\")");

	my $re_simple_varname = qr"[A-Z_][A-Z0-9_]*(?:\.[\w_+\-]+)?";
	while ($cond ne "") {
		if ($cond =~ s/^!//) {
			return ["not", parse_mk_cond($line, $cond)];
		} elsif ($cond =~ s/^defined\((${re_simple_varname})\)$//) {
			return ["defined", $1];
		} elsif ($cond =~ s/^empty\((${re_simple_varname})\)$//) {
			return ["empty", $1];
		} elsif ($cond =~ s/^empty\((${re_simple_varname}):M([^\$:{})]+)\)$//) {
			return ["empty", ["match", $1, $2]];
		} elsif ($cond =~ s/^\$\{(${re_simple_varname})\}\s+(==|!=)\s+"([^"\$\\]*)"$//) {
			return [$2, ["var", $1], ["string", $3]];
		} else {
			$opt_debug_unchecked and $line->log_debug("parse_mk_cond: ${cond}");
			return ["unknown", $cond];
		}
	}
}

sub parse_licenses($) {
	my ($licenses) = @_;

	$licenses =~ s,\$\{PERL5_LICENSE},gnu-gpl-v2 OR artistic,g;
	$licenses =~ s,[()]|AND|OR,,g; # XXX: treats OR like AND
	my @licenses = split(/\s+/, $licenses);
	return \@licenses;
}

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
		if ($rest !~ m"^\s*$") {
			$line->set("shellwords_rest", $rest);
		}

	} elsif ($text =~ regex_mk_comment) {
		my ($comment) = ($1);

		$line->set("is_comment", true);
		$line->set("comment", $comment);

	} elsif ($text =~ m"^\s*$") {

		$line->set("is_empty", true);

	} elsif ($text =~ regex_mk_cond) {
		my ($indent, $directive, $args, $comment) = ($1, $2, $3, $4);

		$line->set("is_cond", true);
		$line->set("indent", $indent);
		$line->set("directive", $directive);
		defined($args) and $line->set("args", $args);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_include) {
		my (undef, $includefile, $comment) = ($1, $2, $3);

		$line->set("is_include", true);
		$line->set("includefile", $includefile);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_sysinclude) {
		my ($includefile, $comment) = ($1, $2);

		$line->set("is_sysinclude", true);
		$line->set("includefile", $includefile);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_mk_dependency) {
		my ($targets, $whitespace, $sources, $comment) = ($1, $2, $3, $4);

		$line->set("is_dependency", true);
		$line->set("targets", $targets);
		$line->set("sources", $sources);
		$line->log_warning("Space before colon in dependency line: " . $line->to_string()) if ($whitespace);
		defined($comment) and $line->set("comment", $comment);

	} elsif ($text =~ regex_rcs_conflict) {
		# This line is useless

	} else {
		$line->log_fatal("Unknown line format: " . $line->to_string());
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
		if ($text =~ m"^\.\s*include\s+\"(.*)\"$") {
			$includefile = resolve_relative_path($1, true);
			if ($includefile =~ regex_unresolved) {
				if ($fname !~ m"/mk/") {
					$line->log_note("Skipping include file \"${includefile}\". This may result in false warnings.");
				}

			} else {
				$is_include_line = true;
			}
		}

		if ($is_include_line) {
			if ($fname !~ m"buildlink3\.mk$" && $includefile =~ m"^\.\./\.\./(.*)/buildlink3\.mk$") {
				my ($bl3_file) = ($1);

				$pkgctx_bl3->{$bl3_file} = $line;
				$opt_debug_misc and $line->log_debug("Buildlink3 file in package: ${bl3_file}");
			}
		}

		if ($is_include_line && !exists($seen_Makefile_include->{$includefile})) {
			$seen_Makefile_include->{$includefile} = true;

			if ($includefile =~ m"^\.\./[^./][^/]*/[^/]+") {
				$line->log_warning("Relative directories should look like \"../../category/package\", not \"../package\".");
				$line->explain_warning(expl_relative_dirs);
			}
			if ($includefile =~ m"(?:^|/)Makefile.common$"
			    || ($includefile =~ m"^(?:\.\./(\.\./[^/]+/)?[^/]+/)?([^/]+)$"
				&& (!defined($1) || $1 ne "../mk")
				&& $2 ne "buildlink3.mk"
				&& $2 ne "options.mk")) {
				$opt_debug_include and $line->log_debug("including ${includefile} sets seen_Makefile_common.");
				$seen_Makefile_common = true;
			}
			if ($includefile =~ m"/mk/") {
				# skip these files

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
					my $last_lineno = $#{$all_lines};
					readmakefile("$dirname/$includefile", $main_lines, $all_lines, $seen_Makefile_include) or return false;

					# Check that there is a comment in each
					# Makefile.common that says which files
					# include it.
					if ($includefile =~ m"/Makefile\.common$") {
						my @mc_lines = @{$all_lines}[$last_lineno+1 .. $#{$all_lines}];
						my $expected = "# used by " . relative_path($cwd_pkgsrcdir, $fname);

						if (!(grep { $_->text eq $expected } @mc_lines)) {
							my $lineno = 0;
							while ($lineno < $#mc_lines && $mc_lines[$lineno]->has("is_comment")) {
								$lineno++;
							}
							my $iline = $mc_lines[$lineno];
							$iline->log_warning("Please add a line \"$expected\" here.");
							$iline->explain_warning(
"Since Makefile.common files usually don't have any comments and",
"therefore not a clearly defined interface, they should at least contain",
"references to all files that include them, so that it is easier to see",
"what effects future changes may have.",
"",
"If there are more than five packages that use a Makefile.common,",
"you should think about giving it a proper name (maybe plugin.mk) and",
"documenting its interface.");
							$iline->append_before($expected);
							autofix(\@mc_lines);
						}
					}
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
		}
	}

	return true;
}

sub load_package_Makefile($$) {
	my ($fname, $ref_lines) = @_;
	my ($subr) = "load_package_Makefile";
	my ($lines, $all_lines, $seen_php_pecl_version);

	$opt_debug_trace and log_debug($fname, NO_LINES, "load_package_Makefile()");

	if (!readmakefile($fname, $lines = [], $all_lines = [], $pkgctx_included = {})) {
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

	$pkgdir = expand_variable("PKGDIR");
	set_default_value(\$pkgdir, ".");
	$distinfo_file = expand_variable("DISTINFO_FILE");
	set_default_value(\$distinfo_file, "distinfo");
	$filesdir = expand_variable("FILESDIR");
	set_default_value(\$filesdir, "files");
	$patchdir = expand_variable("PATCHDIR");
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

sub check_unused_licenses() {

	for my $licensefile (glob("${cwd_pkgsrcdir}/licenses/*")) {
		if (-f $licensefile) {
			my $licensename = basename($licensefile);
			if (!exists($ipc_used_licenses{$licensename})) {
				log_warning($licensefile, NO_LINES, "This license seems to be unused.");
			}
		}
	}
}

sub checkpackage_possible_downgrade() {

	$opt_debug_trace and log_debug(NO_FILE, NO_LINES, "checkpackage_possible_downgrade");

	return unless defined $effective_pkgname;
	return unless $effective_pkgname =~ regex_pkgname;
	my ($pkgbase, $pkgversion) = ($1, $2);
	my $line = $effective_pkgname_line;

	my @changes = get_doc_CHANGES($pkgpath);
	if (@changes == 0) {
		$opt_debug_misc and $line->log_debug("No changes have been recorded for package $pkgpath.");
		return;
	}

	my $last_change = $changes[-1];
	return unless $last_change->action eq "Updated";

	my $last_version = $last_change->version;

	if (dewey_cmp($pkgversion, "<", $last_version)) {
		$line->log_warning("The package is being downgraded from $last_version to $pkgversion.");
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
		my @chars = map { sprintf("0x%02x", ord($_)); } split(//, $rest);
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
		my @chars = map { sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning("${varname} contains invalid characters (" . join(", ", @chars) . ").");
	}
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;

	$opt_debug_trace and $line->log_debug("checkline_trailing_whitespace()");

	if ($line->text =~ /\s+$/) {
		$line->log_note("Trailing white-space.");
		$line->explain_note(
"When a line ends with some white-space, that space is in most cases",
"irrelevant and can be removed, leading to a \"normal form\" syntax.",
"",
"Note: This is mostly for aesthetic reasons.");
		$line->replace_regex(qr"\s+\n$", "\n");
	}
}

sub checkline_rcsid_regex($$$) {
	my ($line, $prefix_regex, $prefix) = @_;
	my ($id) = ($opt_rcsidstring . ($is_wip ? "|Id" : ""));

	$opt_debug_trace and $line->log_debug("checkline_rcsid_regex(${prefix_regex}, ${prefix})");

	if ($line->text !~ m"^${prefix_regex}\$(${id})(?::[^\$]+|)\$$") {
		$line->log_error("\"${prefix}\$${opt_rcsidstring}\$\" expected.");
		$line->explain_error(
"Several files in pkgsrc must contain the CVS Id, so that their current",
"version can be traced back later from a binary package. This is to",
"ensure reproducible builds, for example for finding bugs.",
"",
"Please insert the text from the above error message (without the quotes)",
"at this position in the file.");
		return false;
	}
	return true;
}

sub checkline_rcsid($$) {
	my ($line, $prefix) = @_;

	checkline_rcsid_regex($line, quotemeta($prefix), $prefix);
}

sub checkline_relative_path($$$) {
	my ($line, $path, $must_exist) = @_;
	my ($res_path);

	if (!$is_wip && $path =~ m"/wip/") {
		$line->log_error("A pkgsrc package must not depend on any outside package.");
	}
	$res_path = resolve_relative_path($path, true);
	if ($res_path =~ regex_unresolved) {
		$opt_debug_unchecked and $line->log_debug("Unchecked path: \"${path}\".");
	} elsif (!-e ((($res_path =~ m"^/") ? "" : "${current_dir}/") . $res_path)) {
		$must_exist and $line->log_error("\"${res_path}\" does not exist.");
	} elsif ($path =~ m"^\.\./\.\./([^/]+)/([^/]+)(.*)") {
		my ($cat, $pkg, $rest) = ($1, $2, $3);
	} elsif ($path =~ m"^\.\./\.\./mk/") {
		# There need not be two directory levels for mk/ files.
	} elsif ($path =~ m"^\.\./mk/" && $cur_pkgsrcdir eq "..") {
		# That's fine for category Makefiles.
	} elsif ($path =~ m"^\.\.") {
		$line->log_warning("Invalid relative path \"${path}\".");
	}
}

sub checkline_relative_pkgdir($$) {
	my ($line, $path) = @_;

	checkline_relative_path($line, $path, true);
	$path = resolve_relative_path($path, false);

	if ($path =~ m"^(?:\./)?\.\./\.\./([^/]+/[^/]+)$") {
		my $otherpkgpath = $1;
		if (! -f "$cwd_pkgsrcdir/$otherpkgpath/Makefile") {
			$line->log_error("There is no package in $otherpkgpath.");
		}

	} else {
		$line->log_warning("\"${path}\" is not a valid relative package directory.");
		$line->explain_warning(
"A relative pathname always starts with \"../../\", followed",
"by a category, a slash and a the directory name of the package.",
"For example, \"../../misc/screen\" is a valid relative pathname.");
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

	} elsif (var_is_used($varname)) {
		# Fine.

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

		} elsif ($context->time == VUC_TIME_LOAD && $perms !~ m"p") {
			$is_load_time = true;
			$is_indirect = false;

		} elsif (defined($context->type) && $context->type->perms_union() =~ m"p" && $perms !~ m"p") {
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

		if ($perms !~ m"p" && $perms !~ m"u") {
			$line->log_warning("${varname} may not be used in this file.");
		}
	}

	if ($varname eq "LOCALBASE" && !$is_internal) {
		$line->log_warning("The LOCALBASE variable should not be used by packages.");
		$line->explain_warning(
# from jlam via private mail.
"Currently, LOCALBASE is typically used in these cases:",
"",
"(1) To locate a file or directory from another package.",
"(2) To refer to own files after installation.",
"",
"In the first case, the example is:",
"",
"	STRLIST=        \${LOCALBASE}/bin/strlist",
"	do-build:",
"		cd \${WRKSRC} && \${STRLIST} *.str",
"",
"This should really be:",
"",
"	EVAL_PREFIX=    STRLIST_PREFIX=strlist",
"	STRLIST=        \${STRLIST_PREFIX}/bin/strlist",
"	do-build:",
"		cd \${WRKSRC} && \${STRLIST} *.str",
"",
"In the second case, the example is:",
"",
"	CONFIGURE_ENV+= --with-datafiles=\${LOCALBASE}/share/battalion",
"",
"This should really be:",
"",
"	CONFIGURE_ENV+= --with-datafiles=\${PREFIX}/share/battalion");
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

	if ($opt_warn_quoting && $context->shellword != VUC_SHELLWORD_UNKNOWN && $needs_quoting != dont_know) {

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

		my $stripped_mod = ($mod =~ m"(.*?)(?::M\*)?(?::Q)?$") ? $1 : $mod;
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

		if ($mod =~ m":Q$") {
			my @expl = (
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

			if ($needs_quoting == false) {
				$line->log_warning("The :Q operator should not be used for \${${varname}} here.");
				$line->explain_warning(@expl);
			} elsif ($needs_quoting == doesnt_matter) {
				$line->log_note("The :Q operator isn't necessary for \${${varname}} here.");
				$line->explain_note(@expl);
			}
		}
	}

	assert(defined($mkctx_build_defs), "The build_defs variable must be defined here.");
	if (exists(get_userdefined_variables()->{$varname}) && !exists(get_system_build_defs()->{$varname}) && !exists($mkctx_build_defs->{$varname})) {
		$line->log_warning("The user-defined variable ${varname} is used but not added to BUILD_DEFS.");
		$line->explain_warning(
"When a pkgsrc package is built, many things can be configured by the",
"pkgsrc user in the mk.conf file. All these configurations should be",
"recorded in the binary package, so the package can be reliably rebuilt.",
"The BUILD_DEFS variable contains a list of all these user-settable",
"variables, so please add your variable to it, too.");
	}
}

sub checkline_mk_text($$) {
	my ($line, $text) = @_;
	my ($rest, $state, $vartools, $depr_map);

	if ($text =~ m"^(?:[^#]*[^\$])?\$(\w+)") {
		my ($varname) = ($1);
		$line->log_warning("\$$varname is ambiguous. Use \${$varname} if you mean a Makefile variable or \$\$$varname if you mean a shell variable.");
	}

	if ($line->lines eq "1") {
		checkline_rcsid_regex($line, qr"#\s+", "# ");
	}

	if ($text =~ m"\$\{WRKSRC\}/\.\./") {
		$line->log_warning("Using \"\${WRKSRC}/..\" is conceptually wrong. Please use a combination of WRKSRC, CONFIGURE_DIRS and BUILD_DIRS instead.");
		$line->explain_warning(
"You should define WRKSRC such that all of CONFIGURE_DIRS, BUILD_DIRS",
"and INSTALL_DIRS are subdirectories of it.");
	}

	if ($text =~ m"\b(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R)\b") {
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

	# Don't enforce purely aesthetic changes before more correct behaviour is implemented:
	# $rest = $text;
	# while ($rest =~ s/(?:^|[^\$])\$\(([-A-Z0-9a-z_]+)(?::[^\}]+)?\)//) {
	# 	my ($varname) = ($1);

	# 	$line->log_warning("Please use \${${varname}\} instead of \$(${varname}).");
	# }

}

#include PkgLint/Shell.pm

sub expand_permission($) {
    my ($perm) = @_;
    my %fullperm = ( "a" => "append", "d" => "default", "p" => "preprocess", "s" => "set", "u" => "runtime", "?" => "unknown" );
    my $result = join(", ", map { $fullperm{$_} } split //, $perm);
    $result =~ s/, $//g;

    return $result;
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
		$line->log_warning("Permission [" . expand_permission($needed) . "] requested for ${varname}, but only [" . expand_permission($perms) . "] is allowed.");
		$line->explain_warning(
"The available permissions are:",
"\tappend\t\tappend something using +=",
"\tdefault\t\tset a default value using ?=",
"\tpreprocess\tuse a variable during preprocessing",
"\truntime\t\tuse a variable at runtime",
"\tset\t\tset a variable using :=, =, !=",
"",
"A \"?\" means that it is not yet clear which permissions are allowed",
"and which aren't.");
	}
}

# @param $op
#	The operator that is used for reading or writing to the variable.
#	One of: "=", "+=", ":=", "!=", "?=", "use", "pp-use", "".
#	For some variables (like BuildlinkDepth or BuildlinkPackages), the
#	operator influences the valid values.
# @param $comment
#	In assignments, a part of the line may be commented out. If there
#	is no comment, pass C<undef>.
#
sub checkline_mk_vartype_basic($$$$$$$$);
sub checkline_mk_vartype_basic($$$$$$$$) {
	my ($line, $varname, $type, $op, $value, $comment, $list_context, $is_guessed) = @_;
	my ($value_novar);

	$opt_debug_trace and $line->log_debug(sprintf("checkline_mk_vartype_basic(%s, %s, %s, %s, %s, %s, %s)",
	    $varname, $type, $op, $value, defined($comment) ? $comment : "<undef>", $list_context, $is_guessed));

	$value_novar = $value;
	while ($value_novar =~ s/\$\{([^{}]*)\}//g) {
		my ($varuse) = ($1);
		if (!$list_context && $varuse =~ m":Q$") {
			$line->log_warning("The :Q operator should only be used in lists and shell commands.");
		}
	}

	my %type_dispatch = (
		AwkCommand => sub {
			$opt_debug_unchecked and $line->log_debug("Unchecked AWK command: ${value}");
		},

		BrokenIn => sub {
			if ($value ne $value_novar) {
				$line->log_error("${varname} must not refer to other variables.");

			} elsif ($value =~ m"^pkgsrc-(\d\d\d\d)Q(\d)$") {
				my ($year, $quarter) = ($1, $2);

				# Fine.

			} else {
				$line->log_warning("Invalid value \"${value}\" for ${varname}.");
			}
			$line->log_note("Please remove this line if the package builds for you.");
		},

		BuildlinkDepmethod => sub {
			# Note: this cannot be replaced with { build full } because
			# enumerations may not contain references to other variables.
			if ($value ne $value_novar) {
				# No checks yet.
			} elsif ($value ne "build" && $value ne "full") {
				$line->log_warning("Invalid dependency method \"${value}\". Valid methods are \"build\" or \"full\".");
			}
		},

		BuildlinkDepth => sub {
			if (!($op eq "use" && $value eq "+")
			    && $value ne "\${BUILDLINK_DEPTH}+"
			    && $value ne "\${BUILDLINK_DEPTH:S/+\$//}") {
				$line->log_warning("Invalid value for ${varname}.");
			}
		},

		BuildlinkPackages => sub {
			my $re_del = qr"\$\{BUILDLINK_PACKAGES:N(?:[+\-.0-9A-Z_a-z]|\$\{[^\}]+\})+\}";
			my $re_add = qr"(?:[+\-.0-9A-Z_a-z]|\$\{[^\}]+\})+";

			if (($op eq ":=" && $value =~ m"^${re_del}$") ||
			    ($op eq ":=" && $value =~ m"^${re_del}\s+${re_add}$") ||
			    ($op eq "+=" && $value =~ m"^${re_add}$")) {
				# Fine.

			} else {
				$line->log_warning("Invalid value for ${varname}.");
			}
		},

		Category => sub {
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
			if ($value !~ m"^(?:${allowed_categories})$") {
				$line->log_error("Invalid category \"${value}\".");
			}
		},

		CFlag => sub {
			if ($value =~ m"^-D([0-9A-Z_a-z]+)=(.*)") {
				my ($macname, $macval) = ($1, $2);

				# No checks needed, since the macro definitions
				# are usually directory names, which don't need
				# any quoting.

			} elsif ($value =~ m"^-[DU]([0-9A-Z_a-z]+)") {
				my ($macname) = ($1);

				$opt_debug_unchecked and $line->log_debug("Unchecked macro ${macname} in ${varname}.");

			} elsif ($value =~ m"^-I(.*)") {
				my ($dirname) = ($1);

				$opt_debug_unchecked and $line->log_debug("Unchecked directory ${dirname} in ${varname}.");

			} elsif ($value eq "-c99") {
				# Only works on IRIX, but is usually enclosed with
				# the proper preprocessor conditional.

			} elsif ($value =~ m"^-[OWfgm]|^-std=.*") {
				$opt_debug_unchecked and $line->log_debug("Unchecked compiler flag ${value} in ${varname}.");

			} elsif ($value =~ m"^-.*") {
				$line->log_warning("Unknown compiler flag \"${value}\".");

			} elsif ($value =~ regex_unresolved) {
				$opt_debug_unchecked and $line->log_debug("Unchecked CFLAG: ${value}");

			} else {
				$line->log_warning("Compiler flag \"${value}\" does not start with a dash.");
			}
		},

		Comment => sub {
			if ($value eq "SHORT_DESCRIPTION_OF_THE_PACKAGE") {
				$line->log_error("COMMENT must be set.");
			}
			if ($value =~ m"^(a|an)\s+"i) {
				$line->log_warning("COMMENT should not begin with '$1'.");
			}
			if ($value =~ m"^[a-z]") {
				$line->log_warning("COMMENT should start with a capital letter.");
			}
			if ($value =~ m"\.$") {
				$line->log_warning("COMMENT should not end with a period.");
			}
			if (length($value) > 70) {
				$line->log_warning("COMMENT should not be longer than 70 characters.");
			}
		},

		Dependency => sub {
			if ($value =~ m"^(${regex_pkgbase})(<|=|>|<=|>=|!=|-)(${regex_pkgversion})$") {
				my ($depbase, $depop, $depversion) = ($1, $2, $3);

			} elsif ($value =~ m"^(${regex_pkgbase})-(?:\[(.*)\]\*|(\d+(?:\.\d+)*(?:\.\*)?)(\{,nb\*\}|\*|)|(.*))?$") {
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
					$line->log_error("Unknown dependency pattern \"${value}\".");
				}

			} elsif ($value =~ m"\{") {
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
		},

		DependencyWithPath => sub {
			if ($value =~ regex_unresolved) {
				# don't even try to check anything
			} elsif ($value =~ m"(.*):(\.\./\.\./([^/]+)/([^/]+))$") {
				my ($pattern, $relpath, $cat, $pkg) = ($1, $2, $3, $4);

				checkline_relative_pkgdir($line, $relpath);

				if ($pkg eq "msgfmt" || $pkg eq "gettext") {
					$line->log_warning("Please use USE_TOOLS+=msgfmt instead of this dependency.");

				} elsif ($pkg =~ m"^perl\d+") {
					$line->log_warning("Please use USE_TOOLS+=perl:run instead of this dependency.");

				} elsif ($pkg eq "gmake") {
					$line->log_warning("Please use USE_TOOLS+=gmake instead of this dependency.");

				}

				if ($pattern =~ regex_dependency_lge) {
#				($abi_pkg, $abi_version) = ($1, $2);
				} elsif ($pattern =~ regex_dependency_wildcard) {
#				($abi_pkg) = ($1);
				} else {
					$line->log_error("Unknown dependency pattern \"${pattern}\".");
				}

			} elsif ($value =~ m":\.\./[^/]+$") {
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
		},

		DistSuffix => sub {
			if ($value eq ".tar.gz") {
				$line->log_note("${varname} is \".tar.gz\" by default, so this definition may be redundant.");
			}
		},

		EmulPlatform => sub {
			if ($value =~ m"^(\w+)-(\w+)$") {
				my ($opsys, $arch) = ($1, $2);

				if ($opsys !~ m"^(?:bitrig|bsdos|cygwin|darwin|dragonfly|freebsd|haiku|hpux|interix|irix|linux|mirbsd|netbsd|openbsd|osf1|sunos|solaris)$") {
					$line->log_warning("Unknown operating system: ${opsys}");
				}
				# no check for $os_version
				if ($arch !~ m"^(?:i386|alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|hpcmips|hpcsh|hppa|ia64|m68k|m88k|mips|mips64|mipsel|mipseb|mipsn32|ns32k|pc532|pmax|powerpc|rs6000|s390|sparc|sparc64|vax|x86_64)$") {
					$line->log_warning("Unknown hardware architecture: ${arch}");
				}

			} else {
				$line->log_warning("\"${value}\" is not a valid emulation platform.");
				$line->explain_warning(
"An emulation platform has the form <OPSYS>-<MACHINE_ARCH>.",
"OPSYS is the lower-case name of the operating system, and MACHINE_ARCH",
"is the hardware architecture.",
"",
"Examples: linux-i386, irix-mipsel.");
			}
		},

		FetchURL => sub {
			checkline_mk_vartype_basic($line, $varname, "URL", $op, $value, $comment, $list_context, $is_guessed);

			my $sites = get_dist_sites();
			foreach my $site (keys(%{$sites})) {
				if (index($value, $site) == 0) {
					my $subdir = substr($value, length($site));
					my $is_github = $value =~ m"^https://github\.com/";
					if ($is_github) {
						$subdir =~ s|/.*|/|;
					}
					$line->log_warning(sprintf("Please use \${%s:=%s} instead of \"%s\".", $sites->{$site}, $subdir, $value));
					if ($is_github) {
						$line->log_warning("Run \"".conf_make." help topic=github\" for further tips.");
					}
					last;
				}
			}
		},

		Filename => sub {
			if ($value_novar =~ m"/") {
				$line->log_warning("A filename should not contain a slash.");

			} elsif ($value_novar !~ m"^[-0-9\@A-Za-z.,_~+%]*$") {
				$line->log_warning("\"${value}\" is not a valid filename.");
			}
		},

		Filemask => sub {
			if ($value_novar !~ m"^[-0-9A-Za-z._~+%*?]*$") {
				$line->log_warning("\"${value}\" is not a valid filename mask.");
			}
		},

		FileMode => sub {
			if ($value ne "" && $value_novar eq "") {
				# Fine.
			} elsif ($value =~ m"^[0-7]{3,4}") {
				# Fine.
			} else {
				$line->log_warning("Invalid file mode ${value}.");
			}
		},

		Identifier => sub {
			if ($value ne $value_novar) {
				#$line->log_warning("Identifiers should be given directly.");
			}
			if ($value_novar =~ m"^[+\-.0-9A-Z_a-z]+$") {
				# Fine.
			} elsif ($value ne "" && $value_novar eq "") {
				# Don't warn here.
			} else {
				$line->log_warning("Invalid identifier \"${value}\".");
			}
		},

		Integer => sub {
			if ($value !~ m"^\d+$") {
				$line->log_warning("${varname} must be a valid integer.");
			}
		},

		LdFlag => sub {
			if ($value =~ m"^-L(.*)") {
				my ($dirname) = ($1);

				$opt_debug_unchecked and $line->log_debug("Unchecked directory ${dirname} in ${varname}.");

			} elsif ($value =~ m"^-l(.*)") {
				my ($libname) = ($1);

				$opt_debug_unchecked and $line->log_debug("Unchecked library name ${libname} in ${varname}.");

			} elsif ($value =~ m"^(?:-static)$") {
				# Assume that the wrapper framework catches these.

			} elsif ($value =~ m"^(-Wl,(?:-R|-rpath|--rpath))") {
				my ($rpath_flag) = ($1);
				$line->log_warning("Please use \${COMPILER_RPATH_FLAG} instead of ${rpath_flag}.");

			} elsif ($value =~ m"^-.*") {
				$line->log_warning("Unknown linker flag \"${value}\".");

			} elsif ($value =~ regex_unresolved) {
				$opt_debug_unchecked and $line->log_debug("Unchecked LDFLAG: ${value}");

			} else {
				$line->log_warning("Linker flag \"${value}\" does not start with a dash.");
			}
		},

		License => sub {

			use constant deprecated_licenses => array_to_hash(qw(
				fee-based-commercial-use
				no-commercial-use no-profit no-redistribution
				shareware
			));

			my $licenses = parse_licenses($value);
			foreach my $license (@$licenses) {
				my $license_file = "${cwd_pkgsrcdir}/licenses/${license}";
				if (defined($pkgctx_vardef) && exists($pkgctx_vardef->{"LICENSE_FILE"})) {
					my $license_file_line = $pkgctx_vardef->{"LICENSE_FILE"};

					$license_file = "${current_dir}/" . resolve_relative_path($license_file_line->get("value"), false);
				} else {
					$ipc_used_licenses{$license} = true;
				}

				if (!-f $license_file) {
					$line->log_warning("License file ".normalize_pathname($license_file)." does not exist.");
				}

				if (exists(deprecated_licenses->{$license})) {
					$line->log_warning("License ${license} is deprecated.");
				}
			}
		},

		Mail_Address => sub {
			if ($value =~ m"^([+\-.0-9A-Z_a-z]+)\@([-\w\d.]+)$") {
				my ($localpart, $domain) = ($1, $2);
				if ($domain =~ m"^NetBSD.org"i && $domain ne "NetBSD.org") {
					$line->log_warning("Please write NetBSD.org instead of ${domain}.");
				}
				if ("${localpart}\@${domain}" =~ m"^(tech-pkg|packages)\@NetBSD\.org$"i) {
					$line->log_warning("${localpart}\@${domain} is deprecated. Use pkgsrc-users\@NetBSD.org instead.");
				}

			} else {
				$line->log_warning("\"${value}\" is not a valid mail address.");
			}
		},

		Message => sub {
			if ($value =~ m"^[\"'].*[\"']$") {
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
		},

		Option => sub {
			if ($value ne $value_novar) {
				$opt_debug_unchecked and $line->log_debug("Unchecked option name \"${value}\".");

			} elsif ($value_novar =~ m"^-?([a-z][-0-9a-z\+]*)$") {
				my ($optname) = ($1);

				if (!exists(get_pkg_options()->{$optname})) {
					$line->log_warning("Unknown option \"${value}\".");
					$line->explain_warning(
"This option is not documented in the mk/defaults/options.description",
"file. If this is not a typo, please think of a brief but precise",
"description and either update that file yourself or ask on the",
"tech-pkg\@NetBSD.org mailing list.");
				}

			} elsif ($value_novar =~ m"^-?([a-z][-0-9a-z_\+]*)$") {
				my ($optname) = ($1);

				$line->log_warning("Use of the underscore character in option names is deprecated.");

			} else {
				$line->log_error("\"${value}\" is not a valid option name.");
			}
		},

		Pathlist => sub {

			if ($value !~ m":" && $is_guessed) {
				checkline_mk_vartype_basic($line, $varname, "Pathname", $op, $value, $comment, $list_context, $is_guessed);

			} else {

				# XXX: The splitting will fail if $value contains any
				# variables with modifiers, for example :Q or :S/././.
				foreach my $p (split(qr":", $value)) {
					my $p_novar = remove_variables($p);

					if ($p_novar !~ m"^[-0-9A-Za-z._~+%/]*$") {
						$line->log_warning("\"${p}\" is not a valid pathname.");
					}

					if ($p !~ m"^[\$/]") {
						$line->log_warning("All components of ${varname} (in this case \"${p}\") should be an absolute path.");
					}
				}
			}
		},

		Pathmask => sub {
			if ($value_novar !~ m"^[#\-0-9A-Za-z._~+%*?/\[\]]*$") {
				$line->log_warning("\"${value}\" is not a valid pathname mask.");
			}
		},

		Pathname => sub {
			if ($value_novar !~ m"^[#\-0-9A-Za-z._~+%/]*$") {
				$line->log_warning("\"${value}\" is not a valid pathname.");
			}
		},

		Perl5Packlist => sub {
			if ($value ne $value_novar) {
				$line->log_warning("${varname} should not depend on other variables.");
			}
		},

		PkgName => sub {
			if ($value eq $value_novar && $value !~ regex_pkgname) {
				$line->log_warning("\"${value}\" is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.");
			}
		},

		PkgPath => sub {
			checkline_relative_pkgdir($line, "$cur_pkgsrcdir/$value");
		},

		PkgOptionsVar => sub {
			checkline_mk_vartype_basic($line, $varname, "Varname", $op, $value, $comment, false, $is_guessed);
			if ($value =~ m"\$\{PKGBASE[:\}]") {
				$line->log_error("PKGBASE must not be used in PKG_OPTIONS_VAR.");
				$line->explain_error(
"PKGBASE is defined in bsd.pkg.mk, which is included as the",
"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
"Use \${PKGNAME:C/-[0-9].*//} instead.");
			}
		},

		PkgRevision => sub {
			if ($value !~ m"^[1-9]\d*$") {
				$line->log_warning("${varname} must be a positive integer number.");
			}
			if ($line->fname !~ m"(?:^|/)Makefile$") {
				$line->log_error("${varname} only makes sense directly in the package Makefile.");
				$line->explain_error(
"Usually, different packages using the same Makefile.common have",
"different dependencies and will be bumped at different times (e.g. for",
"shlib major bumps) and thus the PKGREVISIONs must be in the separate",
"Makefiles. There is no practical way of having this information in a",
"commonly used Makefile.");
			}
		},

		PlatformTriple => sub {
			my $part = qr"(?:\[[^\]]+\]|[^-\[])+";
			if ($value =~ m"^(${part})-(${part})-(${part})$") {
				my ($opsys, $os_version, $arch) = ($1, $2, $3);

				if ($opsys !~ m"^(?:\*|BSDOS|Cygwin|Darwin|DragonFly|FreeBSD|Haiku|HPUX|Interix|IRIX|Linux|NetBSD|OpenBSD|OSF1|QNX|SunOS)$") {
					$line->log_warning("Unknown operating system: ${opsys}");
				}
				# no check for $os_version
				if ($arch !~ m"^(?:\*|i386|alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|hpcmips|hpcsh|hppa|ia64|m68k|m88k|mips|mips64|mipsel|mipseb|mipsn32|ns32k|pc532|pmax|powerpc|rs6000|s390|sparc|sparc64|vax|x86_64)$") {
					$line->log_warning("Unknown hardware architecture: ${arch}");
				}

			} else {
				$line->log_warning("\"${value}\" is not a valid platform triple.");
				$line->explain_warning(
"A platform triple has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
"Each of these components may be a shell globbing expression.",
"Examples: NetBSD-*-i386, *-*-*, Linux-*-*.");
			}
		},

		PrefixPathname => sub {
			if ($value =~ m"^man/(.*)") {
				my ($mansubdir) = ($1);

				$line->log_warning("Please use \"\${PKGMANDIR}/${mansubdir}\" instead of \"${value}\".");
			}
		},

		PythonDependency => sub {
			if ($value ne $value_novar) {
				$line->log_warning("Python dependencies should not contain variables.");
			}
			if ($value_novar !~ m"^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$") {
				$line->log_warning("Invalid Python dependency \"${value}\".");
				$line->explain_warning(
"Python dependencies must be an identifier for a package, as specified",
"in lang/python/versioned_dependencies.mk. This identifier may be",
"followed by :build for a build-time only dependency, or by :link for",
"a run-time only dependency.");
			}
		},

		RelativePkgDir => sub {
			checkline_relative_pkgdir($line, $value);
		},

		RelativePkgPath => sub {
			checkline_relative_path($line, $value, true);
		},

		Restricted => sub {
			if ($value ne "\${RESTRICTED}") {
				$line->log_warning("The only valid value for ${varname} is \${RESTRICTED}.");
				$line->explain_warning(
"These variables are used to control which files may be mirrored on FTP",
"servers or CD-ROM collections. They are not intended to mark packages",
"whose only MASTER_SITES are on ftp.NetBSD.org.");
			}
		},

		SedCommand => sub {
		},

		SedCommands => sub {
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

					} elsif ($i == 0 && $word =~ m"^([\"']?)(?:\d*|/.*/)s(.).*\2g?\1$") {
						$line->log_warning("Please always use \"-e\" in sed commands, even if there is only one substitution.");

					} else {
						$line->log_warning("Unknown sed command ${word}.");
					}
				}
			}
		},

		ShellCommand => sub {
			checkline_mk_shelltext($line, $value);
		},

		ShellWord => sub {
			if (!$list_context) {
				checkline_mk_shellword($line, $value, true);
			}
		},

		Stage => sub {
			if ($value !~ m"^(?:pre|do|post)-(?:extract|patch|configure|build|install)$") {
				$line->log_warning("Invalid stage name. Use one of {pre,do,post}-{extract,patch,configure,build,install}.");
			}
		},

		String => sub {
			# No further checks possible.
		},

		Tool => sub {
			if ($varname eq "TOOLS_NOOP" && $op eq "+=") {
				# no warning for package-defined tool definitions

			} elsif ($value =~ m"^([-\w]+|\[)(?::(\w+))?$") {
				my ($toolname, $tooldep) = ($1, $2);
				if (!exists(get_tool_names()->{$toolname})) {
					$line->log_error("Unknown tool \"${toolname}\".");
				}
				if (defined($tooldep) && $tooldep !~ m"^(?:bootstrap|build|pkgsrc|run)$") {
					$line->log_error("Unknown tool dependency \"${tooldep}\". Use one of \"build\", \"pkgsrc\" or \"run\".");
				}
			} else {
				$line->log_error("Invalid tool syntax: \"${value}\".");
			}
		},

		Unchecked => sub {
			# Do nothing, as the name says.
		},

		URL => sub {
			if ($value eq "" && defined($comment) && $comment =~ m"^#") {
				# Ok

			} elsif ($value =~ m"\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$") {
				my ($name, $subdir) = ($1, $2);

				if (!exists(get_dist_sites_names()->{$name})) {
					$line->log_error("${name} does not exist.");
				}
				if ($subdir !~ m"/$") {
					$line->log_error("The subdirectory in ${name} must end with a slash.");
				}

			} elsif ($value =~ regex_unresolved) {
				# No further checks

			} elsif ($value =~ m"^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:=?\@A-Z_a-z~]|#)*$") {
				my ($proto, $host, $port, $path) = ($1, $2, $3, $4);

				if ($host =~ m"\.NetBSD\.org$"i && $host !~ m"\.NetBSD\.org$") {
					$line->log_warning("Please write NetBSD.org instead of ${host}.");
				}

			} elsif ($value =~ m"^([0-9A-Za-z]+)://([^/]+)(.*)$") {
				my ($scheme, $host, $abs_path) = ($1, $2, $3);

				if ($scheme ne "ftp" && $scheme ne "http" && $scheme ne "https" && $scheme ne "gopher") {
					$line->log_warning("\"${value}\" is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.");

				} elsif ($abs_path eq "") {
					$line->log_note("For consistency, please add a trailing slash to \"${value}\".");

				} else {
					$line->log_warning("\"${value}\" is not a valid URL.");
				}

			} else {
				$line->log_warning("\"${value}\" is not a valid URL.");
			}
		},

		UserGroupName => sub {
			if ($value ne $value_novar) {
				# No checks for now.
			} elsif ($value !~ m"^[0-9_a-z]+$") {
				$line->log_warning("Invalid user or group name \"${value}\".");
			}
		},

		Varname => sub {
			if ($value ne "" && $value_novar eq "") {
				# The value of another variable

			} elsif ($value_novar !~ m"^[A-Z_][0-9A-Z_]*(?:[.].*)?$") {
				$line->log_warning("\"${value}\" is not a valid variable name.");
			}
		},

		Version => sub {
			if ($value !~ m"^([\d.])+$") {
				$line->log_warning("Invalid version number \"${value}\".");
			}
		},

		WrapperReorder => sub {
			if ($value =~ m"^reorder:l:([\w\-]+):([\w\-]+)$") {
				my ($lib1, $lib2) = ($1, $2);
				# Fine.
			} else {
				$line->log_warning("Unknown wrapper reorder command \"${value}\".");
			}
		},

		WrapperTransform => sub {
			if ($value =~ m"^rm:(?:-[DILOUWflm].*|-std=.*)$") {
				# Fine.

			} elsif ($value =~ m"^l:([^:]+):(.+)$") {
				my ($lib, $replacement_libs) = ($1, $2);
				# Fine.

			} elsif ($value =~ m"^'?(?:opt|rename|rm-optarg|rmdir):.*$") {
				# FIXME: This is cheated.
				# Fine.

			} elsif ($value eq "-e" || $value =~ m"^\"?'?s[|:,]") {
				# FIXME: This is cheated.
				# Fine.

			} else {
				$line->log_warning("Unknown wrapper transform command \"${value}\".");
			}
		},

		WrkdirSubdirectory => sub {
			checkline_mk_vartype_basic($line, $varname, "Pathname", $op, $value, $comment, $list_context, $is_guessed);
			if ($value eq "\${WRKDIR}") {
				# Fine.
			} else {
				$opt_debug_unchecked and $line->log_debug("Unchecked subdirectory \"${value}\" of \${WRKDIR}.");
			}
		},

		WrksrcSubdirectory => sub {
			if ($value =~ m"^(\$\{WRKSRC\})(?:/(.*))?") {
				my ($prefix, $rest) = ($1, $2);
				$line->log_note("You can use \"" . (defined($rest) ? $rest : ".") . "\" instead of \"${value}\".");

			} elsif ($value ne "" && $value_novar eq "") {
				# The value of another variable

			} elsif ($value_novar !~ m"^(?:\.|[0-9A-Za-z_\@][-0-9A-Za-z_\@./+]*)$") {
				$line->log_warning("\"${value}\" is not a valid subdirectory of \${WRKSRC}.");
			}
		},

		Yes => sub {
			if ($value !~ m"^(?:YES|yes)(?:\s+#.*)?$") {
				$line->log_warning("${varname} should be set to YES or yes.");
				$line->explain_warning(
"This variable means \"yes\" if it is defined, and \"no\" if it is",
"undefined. Even when it has the value \"no\", this means \"yes\".",
"Therefore when it is defined, its value should correspond to its",
"meaning.");
			}
		},

		YesNo => sub {
			if ($value !~ m"^(?:YES|yes|NO|no)(?:\s+#.*)?$") {
				$line->log_warning("${varname} should be set to YES, yes, NO, or no.");
			}
		},

		YesNo_Indirectly => sub {
			if ($value_novar ne "" && $value !~ m"^(?:YES|yes|NO|no)(?:\s+#.*)?$") {
				$line->log_warning("${varname} should be set to YES, yes, NO, or no.");
			}
		},
	);

	if (ref($type) eq "HASH") {
		if (!exists($type->{$value})) {
			$line->log_warning("\"${value}\" is not valid for ${varname}. Use one of { ".join(" ", sort(keys(%{$type})))." } instead.");
		}

	} elsif (defined $type_dispatch{$type}) {
		$type_dispatch{$type}->();

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
	if ($ver !~ m"^\d+$") {
		$line->log_error("All values for ${varname} must be numeric.");
		return;
	}

	while (@pyver) {
		my $nextver = shift(@pyver);
		if ($nextver !~ m"^\d+$") {
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
		} elsif ($varbase !~ m"^_" && $varbase !~ get_regex_plurals()) {
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
				last if ($word =~ m"^#");
				push(@words, $1);
			}
		}

		foreach my $word (@words) {
			checkline_mk_vartype_basic($line, $varname, $type->basic_type, $op, $word, $comment, true, $type->is_guessed);
			if ($type->kind_of_list != LK_INTERNAL) {
				checkline_mk_shellword($line, $word, true);
			}
		}

		if ($rest !~ m"^\s*$") {
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
			$opt_warn_extra and $line->explain_warning(
"The ?= operator is used to provide a default value to a variable. In",
"pkgsrc, many variables can be set by the pkgsrc user in the mk.conf",
"file. This file must be included explicitly. If a ?= operator appears",
"before mk.conf has been included, it will not care about the user's",
"preferences, which can result in unexpected behavior. The easiest way",
"to include the mk.conf file is by including the bsd.prefs.mk file,",
"which will take care of everything.");
		}
	}

	checkline_mk_text($line, $value);
	checkline_mk_vartype($line, $varname, $op, $value, $comment);

	# If the variable is not used and is untyped, it may be a
	# spelling mistake.
	if ($op eq ":=" && $varname eq lc($varname)) {
		$opt_debug_unchecked and $line->log_debug("${varname} might be unused unless it is an argument to a procedure file.");
		# TODO: check $varname against the list of "procedure files".

	} elsif (!var_is_used($varname)) {
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

	if ($value =~ m"/etc/rc\.d") {
		$line->log_warning("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	if (!$is_internal && $varname =~ m"^_") {
		$line->log_warning("Variable names starting with an underscore are reserved for internal pkgsrc use.");
	}

	if ($varname eq "PERL5_PACKLIST" && defined($effective_pkgbase) && $effective_pkgbase =~ m"^p5-(.*)") {
		my ($guess) = ($1);
		$guess =~ s/-/\//g;
		$guess = "auto/${guess}/.packlist";

		my ($ucvalue, $ucguess) = (uc($value), uc($guess));
		if ($ucvalue ne $ucguess && $ucvalue ne "\${PERL5_SITEARCH\}/${ucguess}") {
			$line->log_warning("Unusual value for PERL5_PACKLIST -- \"${guess}\" expected.");
		}
	}

	if ($varname eq "EVAL_PREFIX" && $value =~ m"^([\w_]+)=") {
		my ($eval_varname) = ($1);

		# The variables mentioned in EVAL_PREFIX will later be
		# defined by find-prefix.mk. Therefore, they are marked
		# as known in the current file.
		$mkctx_vardef->{$eval_varname} = $line;
	}

	if ($varname eq "PYTHON_VERSIONS_ACCEPTED") {
		checkline_decreasing_order($line, $varname, $value);
	}

	if (defined($comment) && $comment eq "# defined" && $varname !~ m".*(?:_MK|_COMMON)$") {
		$line->log_note("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
		$line->explain_note(
"The value #defined says something about the state of the variable, but",
"not what that _means_. In some cases a variable that is defined means",
"\"yes\", in other cases it is an empty list (which is also only the",
"state of the variable), whose meaning could be described with \"none\".",
"It is this meaning that should be described.");
	}

	if ($value =~ m"\$\{(PKGNAME|PKGVERSION)[:\}]") {
		my ($pkgvarname) = ($1);
		if ($varname =~ m"^PKG_.*_REASON$") {
			# ok
		} elsif ($varname =~ m"^(?:DIST_SUBDIR|WRKSRC)$") {
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

	if ($varname =~ m"^SITES_") {
		$line->log_warning("SITES_* is deprecated. Please use SITES.* instead.");
	}

	if ($value =~ m"^[^=]\@comment") {
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
	if (defined($pkgctx_plist_subst_cond) && $value =~ m"(.+)=.*\@comment.*") {
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
	my ($op, $varname, $match, $value);

	$opt_debug_trace and $line->log_debug("checkline_mk_cond($cond)");
	my $tree = parse_mk_cond($line, $cond);
	if (tree_match($tree, ["not", ["empty", ["match", \$varname, \$match]]])) {
		#$line->log_note("tree_match: varname=$varname, match=$match");

		my $type = get_variable_type($line, $varname);
		my $btype = defined($type) ? $type->basic_type : undef;
		if (defined($btype) && ref($type->basic_type) eq "HASH") {
			if ($match !~ m"[\$\[*]" && !exists($btype->{$match})) {
				$line->log_warning("Invalid :M value \"$match\". Only { " . join(" ", sort keys %$btype) . " } are allowed.");
			}
		}

		# Currently disabled because the valid options can also be defined in PKG_OPTIONS_GROUP.*.
		# Additionally, all these variables may have multiple assigments (+=).
		if (false && $varname eq "PKG_OPTIONS" && defined($pkgctx_vardef) && exists($pkgctx_vardef->{"PKG_SUPPORTED_OPTIONS"})) {
			my $options = $pkgctx_vardef->{"PKG_SUPPORTED_OPTIONS"}->get("value");

			if ($match !~ m"[\$\[*]" && index(" $options ", " $match ") == -1) {
				$line->log_warning("Invalid option \"$match\". Only { $options } are allowed.");
			}
		}

		# TODO: PKG_BUILD_OPTIONS. That requires loading the
		# complete package definitition for the package "pkgbase"
		# or some other database. If we could confine all option
		# definitions to options.mk, this would become easier.

	} elsif (tree_match($tree, [\$op, ["var", \$varname], ["string", \$value]])) {
		checkline_mk_vartype($line, $varname, "use", $value, undef);

	}
	# XXX: When adding new cases, be careful that the variables may have
	# been partially initialized by previous calls to tree_match.
	# XXX: Maybe it is better to clear these references at the beginning
	# of tree_match.
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
				[ "DISTNAME", optional ],
				[ "PKGNAME",  optional ],
				[ "PKGREVISION", optional ],
				[ "CATEGORIES", once ],
				[ "MASTER_SITES", optional ],
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
				[ "MAINTAINER", optional ],
				[ "OWNER", optional ],
				[ "HOMEPAGE", optional ],
				[ "COMMENT", once ],
				[ "LICENSE", once ],
			]
		],
		[ "Legal issues", optional,
			[
				[ "LICENSE_FILE", optional ],
				[ "RESTRICTED", optional ],
				[ "NO_BIN_ON_CDROM", optional ],
				[ "NO_BIN_ON_FTP", optional ],
				[ "NO_SRC_ON_CDROM", optional ],
				[ "NO_SRC_ON_FTP", optional ],
			]
		],
		[ "Technical restrictions", optional,
			[
				[ "BROKEN_EXCEPT_ON_PLATFORM", many ],
				[ "BROKEN_ON_PLATFORM", many ],
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
				[ "TOOL_DEPENDS", many ],
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

		if ($text =~ m"^#") {
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
	$mkctx_plist_vars = {};
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

		} elsif ($varcanon eq "PLIST_VARS") {
			foreach my $id (split(qr"\s+", $line->get("value"))) {
				$mkctx_plist_vars->{"PLIST.$id"} = true;
				$opt_debug_misc and $line->log_debug("PLIST.${id} is added to PLIST_VARS.");
				use_var($line, "PLIST.$id");
			}

		} elsif ($varcanon eq "USE_TOOLS") {
			foreach my $tool (split(qr"\s+", $line->get("value"))) {
				$tool =~ s/:(build|run)//;
				$mkctx_tools->{$tool} = true;
				$opt_debug_misc and $line->log_debug("${tool} is added to USE_TOOLS.");
			}

		} elsif ($varcanon eq "SUBST_VARS.*") {
			foreach my $svar (split(/\s+/, $line->get("value"))) {
				use_var($svar, varname_canon($svar));
				$opt_debug_misc and $line->log_debug("varuse $svar");
			}

		} elsif ($varcanon eq "OPSYSVARS") {
			foreach my $osvar (split(/\s+/, $line->get("value"))) {
				use_var($line, "$osvar.*");
				def_var($line, $osvar);
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

		if ($line->has("is_empty")) {
			$substcontext->check_end($line);

		} elsif ($line->has("is_comment")) {
			# No further checks.

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, undef, $comment) = ($1, $2, $3, $4);
			my $space1 = substr($text, $+[1], $-[2] - $+[1]);
			my $align = substr($text, $+[2], $-[3] - $+[2]);
			my $value = $line->get("value");

			if ($align !~ m"^(\t*|[ ])$") {
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
			my ($include, $includefile) = ($1, $2);

			$opt_debug_include and $line->log_debug("includefile=${includefile}");
			checkline_relative_path($line, $includefile, $include eq "include");

			if ($includefile =~ m"../Makefile$") {
				$line->log_error("Other Makefiles must not be included directly.");
				$line->explain_warning(
"If you want to include portions of another Makefile, extract",
"the common parts and put them into a Makefile.common. After",
"that, both this one and the other package should include the",
"Makefile.common.");
			}

			if ($includefile eq "../../mk/bsd.prefs.mk") {
				if ($line->fname =~ m"buildlink3\.mk$") {
					$line->log_note("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.");
				}
				$seen_bsd_prefs_mk = true;
			} elsif ($includefile eq "../../mk/bsd.fast.prefs.mk") {
				$seen_bsd_prefs_mk = true;
			}

			if ($includefile =~ m"/x11-links/buildlink3\.mk$") {
				$line->log_error("${includefile} must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.");
			}
			if ($includefile =~ m"/jpeg/buildlink3\.mk$") {
				$line->log_error("${includefile} must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.");
			}
			if ($includefile =~ m"/intltool/buildlink3\.mk$") {
				$line->log_warning("Please say \"USE_TOOLS+= intltool\" instead of this line.");
			}
			if ($includefile =~ m"(.*)/builtin\.mk$") {
				my ($dir) = ($1);
				$line->log_error("${includefile} must not be included directly. Include \"${dir}/buildlink3.mk\" instead.");
			}

		} elsif ($text =~ regex_mk_sysinclude) {
			my ($includefile, $comment) = ($1, $2);

			# No further action.

		} elsif ($text =~ regex_mk_cond) {
			my ($indent, $directive, $args, $comment) = ($1, $2, $3, $4);

			use constant regex_directives_with_args => qr"^(?:if|ifdef|ifndef|elif|for|undef)$";

			if ($directive =~ m"^(?:endif|endfor|elif|else)$") {
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

			if ($directive eq "if" && $args =~ m"^!defined\([\w]+_MK\)$") {
				push(@{$mkctx_indentations}, $mkctx_indentations->[-1]);

			} elsif ($directive =~ m"^(?:if|ifdef|ifndef|for|elif|else)$") {
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
				if ($args =~ m"\s") {
					$line->log_error("The \".${directive}\" directive can only handle _one_ argument.");
				} else {
					$line->log_warning("The \".${directive}\" directive is deprecated. Please use \".if "
						. (($directive eq "ifdef" ? "" : "!"))
						. "defined(${args})\" instead.");
				}

			} elsif ($directive eq "for") {
				if ($args =~ m"^(\S+(?:\s*\S+)*?)\s+in\s+(.*)$") {
					my ($vars, $values) = ($1, $2);

					foreach my $var (split(qr"\s+", $vars)) {
						if (!$is_internal && $var =~ m"^_") {
							$line->log_warning("Variable names starting with an underscore are reserved for internal pkgsrc use.");
						}

						if ($var =~ m"^[_a-z][_a-z0-9]*$") {
							# Fine.
						} elsif ($var =~ m"[A-Z]") {
							$line->log_warning(".for variable names should not contain uppercase letters.");
						} else {
							$line->log_error("Invalid variable name \"${var}\".");
						}

						$mkctx_for_variables->{$var} = true;
					}

					# Check if any of the value's types is not guessed.
					my $guessed = true;
					foreach my $value (split(qr"\s+", $values)) { # XXX: too simple
						if ($value =~ m"^\$\{(.*)\}") {
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
			my ($targets, $whitespace, $dependencies, $comment) = ($1, $2, $3, $4);

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

		} elsif ($text =~ m"^\.\s*(\S*)") {
			my ($directive) = ($1);

			$line->log_error("Unknown directive \".${directive}\".");

		} elsif ($text =~ m"^ ") {
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
	$mkctx_plist_vars = undef;
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
			my (undef, $file, $comment) = ($1, $2, $3);

			if ($file =~ m"^\.\./\.\./(.*)/buildlink3\.mk") {
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
	while ($lineno <= $#{$lines} && (my $text = $lines->[$lineno]->text) =~ m"^#") {
		if ($text =~ m"^# XXX") {
			$lines->[$lineno]->log_note("Please read this comment and remove it if appropriate.");
		}
		$lineno++;
	}
	expect_empty_line($lines, \$lineno);

	if (expect($lines, \$lineno, qr"^BUILDLINK_DEPMETHOD\.(\S+)\?=.*$")) {
		$lines->[$lineno - 1]->log_warning("This line belongs inside the .ifdef block.");
		while ($lines->[$lineno]->text eq "") {
			$lineno++;
		}
	}

	if (!($m = expect($lines, \$lineno, qr"^BUILDLINK_TREE\+=\s*(\S+)$"))) {
		$lines->[$lineno]->log_warning("Expected a BUILDLINK_TREE line.");
		return;
	}

	checklines_buildlink3_mk($lines, $lineno, $m->text(1));
}

sub checklines_buildlink3_mk($$$) {
	my ($lines, $lineno, $pkgid) = @_;
	my ($m);
	my ($bl_PKGBASE_line, $bl_PKGBASE);
	my ($bl_pkgbase_line, $bl_pkgbase);
	my ($abi_line, $abi_pkg, $abi_version);
	my ($api_line, $api_pkg, $api_version);

	# First paragraph: Introduction of the package identifier
	$bl_pkgbase_line = $lines->[$lineno - 1];
	$bl_pkgbase = $pkgid;
	$opt_debug_misc and $bl_pkgbase_line->log_debug("bl_pkgbase=${bl_pkgbase}");
	expect_empty_line($lines, \$lineno);

	# Second paragraph: multiple inclusion protection and introduction
	# of the uppercase package identifier.
	return unless ($m = expect_re($lines, \$lineno, qr"^\.if !defined\((\S+)_BUILDLINK3_MK\)$"));
	$bl_PKGBASE_line = $lines->[$lineno - 1];
	$bl_PKGBASE = $m->text(1);
	$opt_debug_misc and $bl_PKGBASE_line->log_debug("bl_PKGBASE=${bl_PKGBASE}");
	expect_re($lines, \$lineno, qr"^\Q$bl_PKGBASE\E_BUILDLINK3_MK:=$");
	expect_empty_line($lines, \$lineno);

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

	# Third paragraph: Package information.
	my $if_level = 1; # the first .if is from the second paragraph.
	while (true) {

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
				if ($value =~ regex_dependency_lge) {
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
				if ($value =~ regex_dependency_lge) {
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

			if ($varname =~ m"^BUILDLINK_[\w_]+\.(.*)$") {
				my ($varparam) = ($1);

				if ($varparam ne $bl_pkgbase) {
					$line->log_warning("Only buildlink variables for ${bl_pkgbase}, not ${varparam} may be set in this file.");
				}
			}

			if ($varname eq "pkgbase") {
				expect_re($lines, \$lineno, qr"^\.\s*include \"../../mk/pkg-build-options.mk\"$");
			}

			# TODO: More checks.

		} elsif (expect($lines, \$lineno, qr"^(?:#.*)?$")) {
			# Comments and empty lines are fine here.

		} elsif (expect($lines, \$lineno, qr"^\.\s*include \"\.\./\.\./([^/]+/[^/]+)/buildlink3\.mk\"$")
			|| expect($lines, \$lineno, qr"^\.\s*include \"\.\./\.\./mk/(\S+)\.buildlink3\.mk\"$")) {
			# TODO: Maybe check dependency lines.

		} elsif (expect($lines, \$lineno, qr"^\.if\s")) {
			$if_level++;

		} elsif (expect($lines, \$lineno, qr"^\.endif.*$")) {
			$if_level--;
			last if $if_level == 0;

		} else {
			$opt_debug_unchecked and lines_log_warning($lines, $lineno, "Unchecked line in third paragraph.");
			$lineno++;
		}
	}
	if (!defined($api_line)) {
		$lines->[$lineno - 1]->log_warning("Definition of BUILDLINK_API_DEPENDS is missing.");
	}
	expect_empty_line($lines, \$lineno);

	# Fourth paragraph: Cleanup, corresponding to the first paragraph.
	return unless expect_re($lines, \$lineno, qr"^BUILDLINK_TREE\+=\s*-\Q$bl_pkgbase\E$");

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
		if ($line->text =~ m"\$\{") {
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
	my ($lines, %in_distinfo, $patches_dir, $di_is_committed, $current_fname, $is_patch, @seen_algs);

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
	}

	my $on_filename_change = sub($$) {
		my ($line, $new_fname) = @_;

		if (defined($current_fname)) {
			my $seen_algs = join(", ", @seen_algs);
			$opt_debug_misc and $line->log_debug("File ${current_fname} has checksums ${seen_algs}.");
			if ($is_patch) {
				if ($seen_algs ne "SHA1") {
					$line->log_error("Expected SHA1 checksum for ${current_fname}, got ${seen_algs}.");
				}
			} else {
				if ($seen_algs ne "SHA1, RMD160, Size" && $seen_algs ne "SHA1, RMD160, SHA512, Size") {
					$line->log_error("Expected SHA1, RMD160, Size checksums for ${current_fname}, got ${seen_algs}.");
				}
			}
		}

		$is_patch = defined($new_fname) && $new_fname =~ m"^patch-.+$" && -f "${current_dir}/${patches_dir}/${new_fname}";
		$current_fname = $new_fname;
		@seen_algs = ();
	};

	foreach my $line (@{$lines}[2..$#{$lines}]) {
		if ($line->text !~ m"^(\w+) \(([^)]+)\) = (.*)(?: bytes)?$") {
			$line->log_error("Unknown line type.");
			next;
		}
		my ($alg, $chksum_fname, $sum) = ($1, $2, $3);

		if (!defined($current_fname) || $chksum_fname ne $current_fname) {
			$on_filename_change->($line, $chksum_fname);
		}

		if ($chksum_fname !~ m"^\w") {
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

		push(@seen_algs, $alg);

		if ($is_patch && defined($patches_dir) && !(defined($distinfo_file) && $distinfo_file eq "./../../lang/php5/distinfo")) {
			my $fname = "${current_dir}/${patches_dir}/${chksum_fname}";
			if ($di_is_committed && !is_committed($fname)) {
				$line->log_warning("${patches_dir}/${chksum_fname} is registered in distinfo but not added to CVS.");
			}

			if (open(my $patchfile, "<", $fname)) {
				my $sha1 = Digest::SHA1->new();
				while (defined(my $patchline = <$patchfile>)) {
					$sha1->add($patchline) unless $patchline =~ m"\$[N]etBSD";
				}
				close($patchfile);
				my $chksum = $sha1->hexdigest();
				if ($sum ne $chksum) {
					$line->log_error("${alg} checksum of ${chksum_fname} differs (expected ${sum}, got ${chksum}). Rerun '".conf_make." makepatchsum'.");
				}
			} else {
				$line->log_warning("${chksum_fname} does not exist.");
				$line->explain_warning(
"All patches that are mentioned in a distinfo file should actually exist.",
"What's the use of a checksum if there is no file to check?");
			}
		}
		$in_distinfo{$chksum_fname} = true;

	}
	$on_filename_change->(PkgLint::Line->new($fname, NO_LINE_NUMBER, "", []), undef);
	checklines_trailing_empty_lines($lines);

	if (defined($patches_dir)) {
		foreach my $patch (glob("${current_dir}/${patches_dir}/patch-*")) {
			$patch = basename($patch);
			if (!exists($in_distinfo{$patch})) {
				log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '".conf_make." makepatchsum'.");
			}
		}
	}
}

sub checkfile_extra($) {
	my ($fname) = @_;

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_extra()");

	my $lines = load_file($fname) or return log_error($fname, NO_LINE_NUMBER, "Could not be read.");
	checklines_trailing_empty_lines($lines);
	checkperms($fname);
}

sub checkfile_INSTALL($) {
	my ($fname) = @_;

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_INSTALL()");

	checkperms($fname);
	my $lines = load_file($fname) or return log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
}

sub checkfile_MESSAGE($) {
	my ($fname) = @_;

	my @explanation = (
		"A MESSAGE file should consist of a header line, having 75 \"=\"",
		"characters, followed by a line containing only the RCS Id, then an",
		"empty line, your text and finally the footer line, which is the",
		"same as the header line.");

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_MESSAGE()");

	checkperms($fname);
	my $lines = load_file($fname) or return log_error($fname, NO_LINE_NUMBER, "Cannot be read.");

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
	}
	if ($lines->[-1]->text ne "=" x 75) {
		$lines->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
		explain_warning($fname, NO_LINE_NUMBER, @explanation);
	}
	checklines_trailing_empty_lines($lines);
}

sub checkfile_mk($) {
	my ($fname) = @_;

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_mk()");

	checkperms($fname);
	my $lines = load_lines($fname, true) or return log_error($fname, NO_LINE_NUMBER, "Cannot be read.");

	parselines_mk($lines);
	checklines_mk($lines);
	autofix($lines);
}

sub checkfile_package_Makefile($$) {
	my ($fname, $lines) = @_;

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

	if (exists($pkgctx_vardef->{"REPLACE_PERL"}) && exists($pkgctx_vardef->{"NO_CONFIGURE"})) {
		$pkgctx_vardef->{"REPLACE_PERL"}->log_warning("REPLACE_PERL is ignored when ...");
		$pkgctx_vardef->{"NO_CONFIGURE"}->log_warning("... NO_CONFIGURE is set.");
	}

	if (!exists($pkgctx_vardef->{"LICENSE"})) {
		log_error($fname, NO_LINE_NUMBER, "Each package must define its LICENSE.");
	}

	if (exists($pkgctx_vardef->{"GNU_CONFIGURE"}) && exists($pkgctx_vardef->{"USE_LANGUAGES"})) {
		my $languages_line = $pkgctx_vardef->{"USE_LANGUAGES"};
		my $value = $languages_line->get("value");

		if ($languages_line->has("comment") && $languages_line->get("comment") =~ m"\b(?:c|empty|none)\b"i) {
			# Don't emit a warning, since the comment
			# probably contains a statement that C is
			# really not needed.

		} elsif ($value !~ m"(?:^|\s+)(?:c|c99|objc)(?:\s+|$)") {
			$pkgctx_vardef->{"GNU_CONFIGURE"}->log_warning("GNU_CONFIGURE almost always needs a C compiler, ...");
			$languages_line->log_warning("... but \"c\" is not added to USE_LANGUAGES.");
		}
	}

	my $distname_line = $pkgctx_vardef->{"DISTNAME"};
	my $pkgname_line = $pkgctx_vardef->{"PKGNAME"};

	my $distname = defined($distname_line) ? $distname_line->get("value") : undef;
	my $pkgname = defined($pkgname_line) ? $pkgname_line->get("value") : undef;
	my $nbpart = get_nbpart();

	# Let's do some tricks to get the proper value of the package
	# name more often.
	if (defined($distname) && defined($pkgname)) {
		$pkgname =~ s/\$\{DISTNAME\}/$distname/;

		if ($pkgname =~ m"^(.*)\$\{DISTNAME:S(.)([^:]*)\2([^:]*)\2(g?)\}(.*)$") {
			my ($before, $separator, $old, $new, $mod, $after) = ($1, $2, $3, $4, $5, $6);
			my $newname = $distname;
			$old = quotemeta($old);
			$old =~ s/^\\\^/^/;
			$old =~ s/\\\$$/\$/;
			if ($mod eq "g") {
				$newname =~ s/$old/$new/g;
			} else {
				$newname =~ s/$old/$new/;
			}
			$opt_debug_misc and $pkgname_line->log_debug("old pkgname=$pkgname");
			$pkgname = $before . $newname . $after;
			$opt_debug_misc and $pkgname_line->log_debug("new pkgname=$pkgname");
		}
	}

	if (defined($pkgname) && defined($distname) && $pkgname eq $distname) {
		$pkgname_line->log_note("PKGNAME is \${DISTNAME} by default. You probably don't need to define PKGNAME.");
	}

	if (!defined($pkgname) && defined($distname) && $distname !~ regex_unresolved && $distname !~ regex_pkgname) {
		$distname_line->log_warning("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.");
	}

	($effective_pkgname, $effective_pkgname_line, $effective_pkgbase, $effective_pkgversion)
		= (defined($pkgname) && $pkgname !~ regex_unresolved && $pkgname =~ regex_pkgname) ? ($pkgname.$nbpart, $pkgname_line, $1, $2)
		: (defined($distname) && $distname !~ regex_unresolved && $distname =~ regex_pkgname) ? ($distname.$nbpart, $distname_line, $1, $2)
		: (undef, undef, undef, undef);
	if (defined($effective_pkgname_line)) {
		$opt_debug_misc and $effective_pkgname_line->log_debug("Effective name=${effective_pkgname} base=${effective_pkgbase} version=${effective_pkgversion}.");
		# XXX: too many false positives
		if (false && $pkgpath =~ m"/([^/]+)$" && $effective_pkgbase ne $1) {
			$effective_pkgname_line->log_warning("Mismatch between PKGNAME ($effective_pkgname) and package directory ($1).");
		}
	}

	checkpackage_possible_downgrade();

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
				$effective_pkgname_line->explain_warning(
"The wishlist for package updates in doc/TODO mentions that a newer",
"version of this package is available.");
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

#include PkgLint/Patches.pm

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
"Another reason, common for Perl packages, is that the final PLIST is",
"automatically generated. Since the source PLIST is not used at all,",
"you can remove it.",
"",
"Meta packages also don't need a PLIST file.");
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

		if (index($text, '${') != -1 && $text =~ m"\$\{([\w_]+)\}(.*)") {
			if (defined($pkgctx_plist_subst_cond) && exists($pkgctx_plist_subst_cond->{$1})) {
				$opt_debug_misc and $line->log_debug("Removed PLIST_SUBST conditional $1.");
				$text = $2;
			}
		}

		if ($text =~ m"^[\w\$]") {
			$all_files->{$text} = $line;
			my $dir = $text;
			while ($dir =~ s,/[^/]+$,,) {
				$all_dirs->{$dir} = $line;
			}
		}
		if (substr($text, 0, 1) eq '@' && $text =~ m"^\@exec \$\{MKDIR\} %D/(.*)$") {
			my $dir = $1;
			do {
				$all_dirs->{$dir} = $line;
			} while ($dir =~ s,/[^/]+$,,);
		}
	}

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ /\s$/) {
			$line->log_error("pkgsrc does not support filenames ending in white-space.");
			$line->explain_error(
"Each character in the PLIST is relevant, even trailing white-space.");
		}

		# @foo directives.
		if (index($text, '@') != -1 && $text =~ /^(?:\$\{[\w_]+\})?\@([a-z-]+)\s+(.*)/) {
			my ($cmd, $arg) = ($1, $2);

			if ($cmd eq "unexec" && $arg =~ m"^(rmdir|\$\{RMDIR\} \%D/)(.*)") {
				my ($rmdir, $rest) = ($1, $2);
				if ($rest !~ m"(?:true|\$\{TRUE\})") {
					$line->log_warning("Please remove this line. It is no longer necessary.");
				}

			} elsif (($cmd eq "exec" || $cmd eq "unexec")) {
				if ($arg =~ /(?:install-info|\$\{INSTALL_INFO\})/) {
					$line->log_warning("\@exec/unexec install-info is deprecated.");

				} elsif ($arg =~ /ldconfig/ && $arg !~ m"/usr/bin/true") {
					$line->log_error("ldconfig must be used with \"||/usr/bin/true\".");
				}

			} elsif ($cmd eq "comment") {
				# nothing to do

			} elsif ($cmd eq "dirrm") {
				$line->log_warning("\@dirrm is obsolete. Please remove this line.");
				$line->explain_warning(
"Directories are removed automatically when they are empty.",
"When a package needs an empty directory, it can use the \@pkgdir",
"command in the PLIST");
			} elsif ($cmd eq "imake-man") {
				my (@args) = split(/\s+/, $arg);
				if (@args != 3) {
					$line->log_warning("Invalid number of arguments for imake-man.");
				} else {
					if ($args[2] eq "\${IMAKE_MANNEWSUFFIX}") {
						warn_about_PLIST_imake_mannewsuffix($line);
					}
				}

			} elsif ($cmd eq "pkgdir") {
				# TODO: What can we check here?

			} else {
				$line->log_warning("Unknown PLIST directive \"\@$cmd\".");
			}

		# Pathnames.
		} elsif ($text =~ m"^([A-Za-z0-9\$].*)/([^/]+)$") {
			my ($dirname, $basename) = ($1, $2);

			if ($opt_warn_plist_sort && $text =~ m"^\w" && $text !~ regex_unresolved) {
				if (defined($last_file_seen)) {
					if ($last_file_seen gt $text) {
						$line->log_warning("${text} should be sorted before ${last_file_seen}.");
						$line->explain_warning(
"For aesthetic reasons, the files in the PLIST should be sorted",
"alphabetically.");
					} elsif ($last_file_seen eq $text) {
						$line->log_warning("Duplicate filename.");
					}
				}
				$last_file_seen = $text;
			}

			if (index($basename, '${IMAKE_MANNEWSUFFIX}') != -1) {
				warn_about_PLIST_imake_mannewsuffix($line);
			}

			if (substr($dirname, 0, 4) eq "bin/") {
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
					$opt_warn_extra and $line->explain_warning(
"All programs that can be run directly by the user should have a manual",
"page for quick reference. The programs in the bin/ directory should have",
"corresponding manual pages in section 1 (filename program.1), not in",
"section 8.");
				}

			} elsif (substr($text, 0, 4) eq "doc/") {
				$line->log_error("Documentation must be installed under share/doc, not doc.");

			} elsif (substr($text, 0, 9) eq "etc/rc.d/") {
				$line->log_error("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.");

			} elsif (substr($text, 0, 4) eq "etc/") {
				my $f = "mk/pkginstall/bsd.pkginstall.mk";

				assert(-f "${cwd_pkgsrcdir}/${f}", "${cwd_pkgsrcdir}/${f} is not a regular file.");
				$line->log_error("Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in ${f}.");

			} elsif (substr($text, 0, 8) eq "include/" && $text =~ m"^include/.*\.(?:h|hpp)$") {
				# Fine.

			} elsif ($text eq "info/dir") {
				$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

			} elsif (substr($text, 0, 5) eq "info/" && length($text) > 5) {
				if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"INFO_FILES"})) {
					$line->log_warning("Packages that install info files should set INFO_FILES.");
				}

			} elsif (defined($effective_pkgbase) && $text =~ m"^lib/\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif (substr($text, 0, 11) eq "lib/locale/") {
				$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif (substr($text, 0, 4) eq "lib/" && $text =~ m"^(lib/(?:.*/)*)([^/]+)\.(so|a|la)$") {
				my ($dir, $lib, $ext) = ($1, $2, $3);

				if ($dir eq "lib/" && $lib !~ m"^lib") {
					$opt_warn_extra and $line->log_warning("Library filename does not start with \"lib\".");
				}
				if ($ext eq "la") {
					if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"USE_LIBTOOL"})) {
						$line->log_warning("Packages that install libtool libraries should define USE_LIBTOOL.");
					}
				}

			} elsif (substr($text, 0, 4) eq "man/" && $text =~ m"^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$") {
				my ($cat_or_man, $section, $manpage, $ext, $gz) = ($1, $2, $3, $4, $5);

				if ($section !~ m"^[\dln]$") {
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

			} elsif (substr($text, 0, 7) eq "man/cat") {
				$line->log_warning("Invalid filename \"${text}\" for preformatted manual page.");

			} elsif (substr($text, 0, 7) eq "man/man") {
				$line->log_warning("Invalid filename \"${text}\" for unformatted manual page.");

			} elsif (substr($text, 0, 5) eq "sbin/") {
				my $binname = substr($text, 5);

				if (!exists($all_files->{"man/man8/${binname}.8"})) {
					$opt_warn_extra and $line->log_warning("Manual page missing for sbin/${binname}.");
					$opt_warn_extra and $line->explain_warning(
"All programs that can be run directly by the user should have a manual",
"page for quick reference. The programs in the sbin/ directory should have",
"corresponding manual pages in section 8 (filename program.8), not in",
"section 1.");
				}

			} elsif (substr($text, 0, 6) eq "share/" && $text =~ m"^share/applications/.*\.desktop$") {
				my $f = "../../sysutils/desktop-file-utils/desktopdb.mk";
				if (defined($pkgctx_included) && !exists($pkgctx_included->{$f})) {
					$line->log_warning("Packages that install a .desktop entry may .include \"$f\".");
					$line->explain_warning(
"If *.desktop files contain MimeType keys, global MIME Type registory DB",
"must be updated by desktop-file-utils.",
"Otherwise, this warning is harmless.");
				}

			} elsif ($text =~ m"^share/icons/[^/]+/.+$") {
				if (defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"ICON_THEMES"})) {
					$line->log_warning("Packages that install icon theme files should set ICON_THEMES.");
				}

			} elsif ($pkgpath ne "graphics/hicolor-icon-theme" && $text =~ m"^share/icons/hicolor(?:$|/)") {
				my $f = "../../graphics/hicolor-icon-theme/buildlink3.mk";
				if (defined($pkgctx_included) && !exists($pkgctx_included->{$f})) {
					$line->log_error("Please .include \"$f\" in the Makefile");
					$line->explain_error(
"If hicolor icon themes are installed, icon theme cache must be",
"maintained. The hicolor-icon-theme package takes care of that.");
				}

			} elsif (substr($text, 0, 6) eq "share/" && $pkgpath ne "graphics/gnome-icon-theme" && $text =~ m"^share/icons/gnome(?:$|/)") {
				my $f = "../../graphics/gnome-icon-theme/buildlink3.mk";
				if (defined($pkgctx_included) && !exists($pkgctx_included->{$f})) {
					$line->log_error("Please .include \"$f\"");
					$line->explain_error(
"If Gnome icon themes are installed, icon theme cache must be maintained.");
				}
			} elsif ($dirname eq "share/aclocal" && $basename =~ m"\.m4$") {
				# Fine.

			} elsif (substr($text, 0, 15) eq "share/doc/html/") {
				$opt_warn_plist_depr and $line->log_warning("Use of \"share/doc/html\" is deprecated. Use \"share/doc/\${PKGBASE}\" instead.");

			} elsif (defined($effective_pkgbase) && $text =~ m"^share/(?:doc/|examples/|)\Q${effective_pkgbase}\E/") {
				# Fine.

			} elsif ($pkgpath ne "graphics/hicolor-icon-theme" && $text =~ m"^share/icons/hicolor/icon-theme\.cache") {
				$line->log_error("Please .include \"../../graphics/hicolor-icon-theme/buildlink3.mk\" and remove this line.");

			} elsif (substr($text, 0, 11) eq "share/info/") {
				$line->log_warning("Info pages should be installed into info/, not share/info/.");
				$line->explain_warning(
"To fix this, you should add INFO_FILES=yes to the package Makefile.");

			} elsif (substr($text, -3) eq ".mo" && $text =~ m"^share/locale/[\w\@_]+/LC_MESSAGES/[^/]+\.mo$") {
				# Fine.

			} elsif (substr($text, 0, 10) eq "share/man/") {
				$line->log_warning("Man pages should be installed into man/, not share/man/.");

			} else {
				$opt_debug_unchecked and $line->log_debug("Unchecked pathname \"${text}\".");
			}

			if ($text =~ /\$\{PKGLOCALEDIR}/ && defined($pkgctx_vardef) && !exists($pkgctx_vardef->{"USE_PKGLOCALEDIR"})) {
				$line->log_warning("PLIST contains \${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.");
			}

			if (index($text, "/CVS/") != -1) {
				$line->log_warning("CVS files should not be in the PLIST.");
			}
			if (substr($text, -5) eq ".orig") {
				$line->log_warning(".orig files should not be in the PLIST.");
			}
			if (substr($text, -14) eq "/perllocal.pod") {
				$line->log_warning("perllocal.pod files should not be in the PLIST.");
				$line->explain_warning(
"This file is handled automatically by the INSTALL/DEINSTALL scripts,",
"since its contents changes frequently.");
			}

			if ($text =~ m"^(.*)(\.a|\.so[0-9.]*)$") {
				my ($basename, $ext) = ($1, $2);

				if (exists($all_files->{"${basename}.la"})) {
					$line->log_warning("Redundant library found. The libtool library is in line " . $all_files->{"${basename}.la"}->lines . ".");
				}
			}

		} elsif ($text =~ m"^\$\{[\w_]+\}$") {
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
	if ($basename =~ m"^(?:work.*|.*~|.*\.orig|.*\.rej)$") {
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
		} elsif ($fname =~ m"(?:^|/)files/[^/]*$") {
			# Ok

		} elsif (!is_emptydir($fname)) {
			log_warning($fname, NO_LINE_NUMBER, "Unknown directory name.");
		}

	} elsif (S_ISLNK($st->mode)) {
		if ($basename !~ m"^work") {
			log_warning($fname, NO_LINE_NUMBER, "Unknown symlink name.");
		}

	} elsif (!S_ISREG($st->mode)) {
		log_error($fname, NO_LINE_NUMBER, "Only files and directories are allowed in pkgsrc.");

	} elsif ($basename eq "ALTERNATIVES") {
		$opt_check_ALTERNATIVES and checkfile_ALTERNATIVES($fname);

	} elsif ($basename eq "buildlink3.mk") {
		$opt_check_bl3 and checkfile_buildlink3_mk($fname);

	} elsif ($basename =~ m"^DESCR") {
		$opt_check_DESCR and checkfile_DESCR($fname);

	} elsif ($basename =~ m"^distinfo") {
		$opt_check_distinfo and checkfile_distinfo($fname);

	} elsif ($basename eq "DEINSTALL" || $basename eq "INSTALL") {
		$opt_check_INSTALL and checkfile_INSTALL($fname);

	} elsif ($basename =~ m"^MESSAGE") {
		$opt_check_MESSAGE and checkfile_MESSAGE($fname);

	} elsif ($basename =~ m"^patch-[-A-Za-z0-9_.~+]*[A-Za-z0-9_]$") {
		$opt_check_patches and checkfile_patch($fname);

	} elsif ($fname =~ m"(?:^|/)patches/manual[^/]*$") {
		$opt_debug_unchecked and log_debug($fname, NO_LINE_NUMBER, "Unchecked file \"${fname}\".");

	} elsif ($fname =~ m"(?:^|/)patches/[^/]*$") {
		log_warning($fname, NO_LINE_NUMBER, "Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.");

	} elsif ($basename =~ m"^(?:.*\.mk|Makefile.*)$" and not $fname =~ m,files/, and not $fname =~ m,patches/,) {
		$opt_check_mk and checkfile_mk($fname);

	} elsif ($basename =~ m"^PLIST") {
		$opt_check_PLIST and checkfile_PLIST($fname);

	} elsif ($basename eq "TODO" || $basename eq "README") {
		# Ok

	} elsif ($basename =~ m"^CHANGES-.*") {
		load_doc_CHANGES($fname);

	} elsif (!-T $fname) {
		log_warning($fname, NO_LINE_NUMBER, "Unexpectedly found a binary file.");

	} elsif ($fname =~ m"(?:^|/)files/[^/]*$") {
		# Ok
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
		assert(false, "Unknown line format: " . $line->text)
			unless $type eq "" || $type eq "D";
		assert(false, "Unknown line format: " . $line->text)
			unless defined($tag);
		assert(false, "Unknown line format: " . $line->text)
			unless defined($keyword_mode);
		assert(false, "Unknown line format: " . $line->text)
			if defined($undef);
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
		if ($line->text =~ m"^(#?)SUBDIR\s*\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $indentation, $subdir, $comment) = ($1, $2, $3, $4);

			if ($comment_flag eq "#" && (!defined($comment) || $comment eq "")) {
				$line->log_warning("${subdir} commented out without giving a reason.");
			}

			if ($indentation ne "\t") {
				$line->log_warning("Indentation should be a single tab character.");
			}

			if ($subdir =~ m"\$" || !-f "${current_dir}/${subdir}/Makefile") {
				next;
			}

			if (!defined($prev_subdir) || $subdir gt $prev_subdir) {
				# correctly ordered
			} elsif ($subdir eq $prev_subdir) {
				$line->log_error("${subdir} must only appear once.");
			} elsif ($prev_subdir eq "x11" && $subdir eq "archivers") {
				# ignore that one, since it is documented in the top-level Makefile
			} else {
				$line->log_warning("${subdir} should come before ${prev_subdir}.");
			}

			$prev_subdir = $subdir;

			if ($comment_flag eq "") {
				push(@subdirs, "${current_dir}/${subdir}");
			}
		}
	}

	checklines_mk($lines);

	if ($opt_recursive) {
		$ipc_checking_root_recursively = true;
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
	while ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ m"^#") {
		$lineno++;
	}

	# Then we need an empty line
	expect_empty_line($lines, \$lineno);

	# Then comes the COMMENT line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ m"^COMMENT=\t*(.*)") {
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

		if ($line->text =~ m"^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
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
	my ($lines, $have_distinfo, $have_patches);

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
	$pkgctx_included = {};
	$seen_Makefile_common = false;

	# we need to handle the Makefile first to get some variables
	if (!load_package_Makefile("${current_dir}/Makefile", \$lines)) {
		log_error("${current_dir}/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		goto cleanup;
	}

	my @files = glob("${current_dir}/*");
	if ($pkgdir ne ".") {
		push(@files, glob("${current_dir}/${pkgdir}/*"));
	}
	if ($opt_check_extra) {
		push(@files, glob("${current_dir}/${filesdir}/*"));
	}
	push(@files, glob("${current_dir}/${patchdir}/*"));
	if ($distinfo_file !~ m"^(?:\./)?distinfo$") {
		push(@files, "${current_dir}/${distinfo_file}");
	}
	$have_distinfo = false;
	$have_patches = false;

	# Determine the used variables before checking any of the
	# Makefile fragments.
	foreach my $fname (@files) {
		if (($fname =~ m"^((?:.*/)?Makefile\..*|.*\.mk)$")
		&& (not $fname =~ m"patch-")
		&& (not $fname =~ m"${pkgdir}/")
		&& (not $fname =~ m"${filesdir}/")
		&& (defined(my $lines = load_lines($fname, true)))) {
			parselines_mk($lines);
			determine_used_variables($lines);
		}
	}

	foreach my $fname (@files) {
		if ($fname eq "${current_dir}/Makefile") {
			$opt_check_Makefile and checkfile_package_Makefile($fname, $lines);
		} else {
			checkfile($fname);
		}
		if ($fname =~ m"/patches/patch-*$") {
			$have_patches = true;
		} elsif ($fname =~ m"/distinfo$") {
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
	$pkgctx_included = undef;
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
	$is_wip = !$opt_import && ($abs_current_dir =~ m"/wip(?:/|$)");
	$is_internal = ($abs_current_dir =~ m"/mk(?:/|$)");

	# Determine the root directory of pkgsrc. By only overwriting
	# the global variable $cwd_pkgsrcdir when we are checking inside
	# a pkgsrc tree, the user can specify a tree with the
	# --pkgsrcdir option and then check files (but not directories)
	# outside of any pkgsrc tree.
	$cur_pkgsrcdir = undef;
	$pkgpath = undef;
	foreach my $d (".", "..", "../..", "../../..") {
		if (-f "${current_dir}/${d}/mk/bsd.pkg.mk") {
			$cur_pkgsrcdir = $d;
			$pkgpath = relative_path("${current_dir}/${d}", $current_dir);
		}
	}
	if (!defined($cwd_pkgsrcdir) && defined($cur_pkgsrcdir)) {
		$cwd_pkgsrcdir = "${current_dir}/${cur_pkgsrcdir}";
	}

	if (!defined($cwd_pkgsrcdir)) {
		log_error($item, NO_LINE_NUMBER, "Cannot determine the pkgsrc root directory.");
		return;
	}

	return if $is_dir && is_emptydir($item);

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

	local $| = true;
	parse_command_line();

	@todo_items = (@ARGV != 0) ? @ARGV : (".");
	while (@todo_items != 0) {
		checkitem(shift(@todo_items));
	}

	if ($ipc_checking_root_recursively) {
		check_unused_licenses();
	}

	PkgLint::Logging::print_summary_and_exit($opt_quiet);
}

main() unless caller();
