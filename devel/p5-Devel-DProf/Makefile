# $NetBSD: Makefile,v 1.1.1.1 1998/11/26 18:02:49 bad Exp $
#

DISTNAME=		DProf-19970614
PKGNAME=		p5-Devel-DProf-19970614
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=		bad@netbsd.org

USE_PERL5=		yes

WRKSRC=			${WRKDIR}/DProf-19970614

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
