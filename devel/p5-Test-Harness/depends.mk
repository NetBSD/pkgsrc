# $NetBSD: depends.mk,v 1.3 2004/07/13 22:01:03 kristerw Exp $

.include "../../mk/bsd.prefs.mk"

# perl58>=5.8.3 includes Test::Harness, so we allow it to satisfy this
# dependency.
#
# This does however cause problems for the bulk-builds; it adds all
# packages in the "path"-part of the DEPENDS to the list of required
# packages, and thus refuses to build the packages depending on
# this package when it fails...
#
# Fix this for now by noting that if there is no PERL5 installed,
# and PERL5_PKGSRCDIR has not been set, then a sufficiently new
# perl will be installed, so the DEPENDS line is not needed...
# This hack should be removed when the bulk-build dependency-
# tracking has been fixed.
.if exists(${PERL5}) || defined(${PERL5_PKGSRCDIR})
DEPENDS+=	{perl{,-thread}>=5.8.3,p5-Test-Harness-[0-9]*}:../../devel/p5-Test-Harness
.endif
