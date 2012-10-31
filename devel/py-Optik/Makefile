# $NetBSD: Makefile,v 1.16 2012/10/31 11:19:27 asau Exp $

DISTNAME=	optik-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/optik/Optik/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://optik.sourceforge.net/
COMMENT=	Command line parsing library for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	#none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_optik.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
