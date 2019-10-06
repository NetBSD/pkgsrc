# $NetBSD: FileUtil.pm,v 1.2 2019/10/06 11:45:05 rillig Exp $
#
# Subroutines for loading and saving line-oriented files.
# The load_file() subroutine loads a file completely into memory,
# optionally handling continuation line folding. The load_lines() subrou-
# tine is an abbreviation for the common case of loading files without
# continuation lines.
#
package PkgLint::FileUtil;

use strict;
use warnings;

BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		load_file load_lines
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
	open(my $f, "<", $fname) or return;
	$lineno = 0;
	while (defined($line = <$f>)) {
		$lineno++;
		push(@{$physlines}, [$lineno, $line]);
	}
	close($f) or return;
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
		if ($lines->[$lineno]->[1] =~ m"^([ \t]*)(.*?)([ \t]*)(\\?)\n?$") {
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

	if (0 <= $#{$physlines} && $physlines->[-1]->[1] !~ m"\n$") {
		log_error($fname, $physlines->[-1]->[0], "File must end with a newline.");
	}

	return $loglines;
}

sub load_file($) {
	my ($fname) = @_;

	return load_lines($fname, false);
}
