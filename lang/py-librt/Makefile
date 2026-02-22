# $NetBSD: Makefile,v 1.3 2026/02/22 13:32:56 wiz Exp $

DISTNAME=	librt-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_PYPI:=l/librt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypyc/librt
COMMENT=	Mypyc runtime library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions-[0-9]*:../../lang/py-mypy_extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} smoke_tests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
