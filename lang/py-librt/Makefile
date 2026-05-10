# $NetBSD: Makefile,v 1.5 2026/05/10 08:38:04 adam Exp $

DISTNAME=	librt-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_PYPI:=l/librt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypyc/librt
COMMENT=	Mypyc runtime library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} smoke_tests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
