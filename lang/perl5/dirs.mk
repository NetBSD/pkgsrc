# $NetBSD: dirs.mk,v 1.2 2011/05/16 07:59:04 abs Exp $
#
# Provide typical required Perl directories

.if !defined(_PERL5_DIRS_MK)
_PERL5_DIRS_MK=	# defined

.include "../../mk/bsd.prefs.mk"

PERL5_PREFIX=		${PREFIX}
PERL5_VENDORPREFIX=	${PERL5_PREFIX}
PERL5_SITEPREFIX?=	${PERL5_PREFIX}
BUILD_DEFS+=		PERL5_SITEPREFIX

PERL5=			${PERL5_PREFIX}/bin/perl
PERL5_PERLBASE=		${PERL5_PREFIX}/lib/perl5
PERL5_VENDORBASE=	${PERL5_VENDORPREFIX}/lib/perl5/vendor_perl
#
# The unusual check for empty(PERL5_SITEPREFIX) is because ${PREFIX} isn't
# defined until bsd.pkg.mk is included, so when we inspect its value at
# this point, it's empty.
#
.if empty(PERL5_SITEPREFIX) || \
    !empty(PERL5_SITEPREFIX:M${LOCALBASE}) || \
    !empty(PERL5_SITEPREFIX:M${LOCALBASE}/*)
PERL5_SITEBASE=		${PERL5_SITEPREFIX}/lib/perl5/site_perl
.else
PERL5_SITEBASE=		${PERL5_SITEPREFIX}
.endif

PERL5_SITEBIN?=		${PERL5_SITEBASE}/bin

PERL5_PRIVLIB=		${PERL5_PERLBASE}/${PERL5_API_VERS}
PERL5_VENDORLIB=	${PERL5_VENDORBASE}/${PERL5_API_VERS}
.if !empty(PERL5_SITEBASE:M*lib/perl5/site_perl)
PERL5_SITELIB=		${PERL5_SITEBASE}/${PERL5_API_VERS}
.else
PERL5_SITELIB=		${PERL5_SITEBASE}/lib/perl5/site_perl/${PERL5_API_VERS}
.endif

.endif
