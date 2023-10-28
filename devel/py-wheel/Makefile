# $NetBSD: Makefile,v 1.34 2023/10/28 19:57:09 wiz Exp $

DISTNAME=	wheel-0.41.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Built-package format for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.8:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.0:../../devel/py-test

USE_LANGUAGES=	c # for tests only

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs to be installed first
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
