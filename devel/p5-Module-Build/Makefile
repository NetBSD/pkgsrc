# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 16:15:38 kim Exp $
#

DISTNAME=	Module-Build-0.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Module-Build/
COMMENT=	Build and install Perl modules

USE_PERL5=	YES

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Build.PL

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install

.include "../../mk/bsd.pkg.mk"
