# $NetBSD: Makefile,v 1.1.1.1 1998/11/26 18:19:50 bad Exp $
#

DISTNAME=		Time-HiRes-01.19
PKGNAME=		p5-Time-HiRes-01.19
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time

MAINTAINER=		bad@netbsd.org

USE_PERL5=		yes

WRKSRC=			${WRKDIR}/Time-HiRes-01.19

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
