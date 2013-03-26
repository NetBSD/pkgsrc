#! @PERL@
# $NetBSD: build.pl,v 1.1 2013/03/26 15:08:29 schmonz Exp $
#

use strict;
use warnings;

sub readfile {
	my $file = shift;

	local $/ = undef;
	open(my $in, "<", $file) || die "failed to read $file: $!";
	my $contents = <$in>;
	close($in) || die "failed to read $file: $!";

	return $contents;
}

while (my $line = <>) {
	if ($line =~ /^use PkgLint::(.+);$/) {
		print readfile("PkgLint/$1.pm");
	} else {
		print $line;
	}
}
