# $NetBSD: Makefile,v 1.28 2022/01/10 18:20:57 wiz Exp $

DISTNAME=	optik-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/optik/Optik/}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=optik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://optik.sourceforge.net/
COMMENT=	Command line parsing library for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	#none

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_optik.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
