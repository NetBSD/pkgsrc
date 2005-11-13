package pkgsrc::Dewey;

use strict;
use warnings;

require Exporter;
use AutoLoader;

our @ISA = qw(Exporter);

our @EXPORT = qw(dewey_cmp dewey_match);

our $VERSION = '1.0';

require XSLoader;
XSLoader::load('pkgsrc::Dewey', $VERSION);

# Preloaded methods go here.

# Autoload methods go after =cut, and are processed by the autosplit program.

1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

pkgsrc::Dewey - Perl extension for comparing pkgsrc Dewey version numbers

=head1 SYNOPSIS

	use pkgsrc::Dewey;
	dewey_cmp(lhs, op, rhs);
	dewey_match(pattern, package);

=head1 DESCRIPTION

C<pkgsrc::Dewey> is a Perl extension for comparing pkgsrc Dewey version
numbers.
It provides two functions:
C<dewey_cmp()> and C<dewey_match()>.

C<dewey_cmp(pattern, package)>
compares the C<pattern> against the C<package>, and returns 1 if the
C<package> matches the C<pattern> and 0 if not. Both the C<pattern>
and the C<package> should contain a package name.

C<dewey_match(lhs, op, rhs)>
compares two pkgsrc Dewey version numbers. Both C<lhs> and
C<rhs> should be version numbers (not containing any package names).
If the operator C<op> is invalid, C<dewey_match> returns -1.
Otherwise it returns 1 if the comparison is true and 0 if not.

=head2 EXPORT

C<dewey_cmp()>,
C<dewey_match()>

=head1 SEE ALSO

Homepage for the Perl module:
L<http://www.netbsd.org/packages/pkgtools/p5-pkgsrc-Dewey/README.html>

General information about pkgsrc:
L<http://www.pkgsrc.org/>

The pkgsrc guide:
L<http://www.netbsd.org/Documentation/pkgsrc/>

=head1 AUTHORS

Dieter Baron E<lt>dillo@NetBSD.orgE<gt>
and
Thomas Klausner E<lt>wiz@NetBSD.orgE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2005 by Dieter Baron and Thomas Klausner

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.8.7 or,
at your option, any later version of Perl 5 you may have available.


=cut
