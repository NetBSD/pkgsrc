# -*-perl-*-

# This is a drop-in replacement for the MakeMaker Perl module. Instead
# of generating a Makefile, it extracts the dependency information for
# other Perl modules. It is used to simplify the generation of pkgsrc
# packages for Perl modules.

package ExtUtils::MakeMaker;

use strict;
use warnings;

BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT);
	@ISA = qw(Exporter);
	@EXPORT = qw(WriteMakefile);
}

use constant pkgsrcdir	=> "../..";

# Finds and returns the category a given package lies in.
# If the package does not exist, C<undef> is returned.
# If the package exists more than once, it is unspecified which
# of the categories is returned.
sub find_category($) {
	my ($pkg) = @_;
	my $retval;

	opendir(D, pkgsrcdir) or die;
	foreach my $cat (readdir(D)) {
		next if ($cat =~ qr"^\.");

		if (-d (sprintf("%s/%s/%s", pkgsrcdir, $cat, $pkg))) {
			$retval = $cat;
		}
	}
	closedir(D);
	return $retval;
}

sub WriteMakefile(%) {
	my (%options) = @_;

	if (exists($options{"PREREQ_PM"})) {
		my $deps = $options{"PREREQ_PM"};

		foreach my $dep (sort(keys(%{$deps}))) {
			my ($ver, $pkgbase, $category);

			$ver = $deps->{$dep};
			($pkgbase = "p5-${dep}") =~ s/::/-/g;
			$category = find_category($pkgbase);

			if (defined($category)) {
				printf("%s>=%s:../../%s/%s\n", $pkgbase, $ver, $category, $pkgbase);

			} else {
				# If the package does not exist but the
				# Perl module can be loaded, assume that
				# no extra dependency is needed. Otherwise fail.
				if (!eval(sprintf("use %s %s; 1;", $dep, $ver))) {
					die("$0: ERROR: No pkgsrc package found for dependency ${dep}>=${ver}.\n$@\n");
				}
			}
		}
	}
}

1;
