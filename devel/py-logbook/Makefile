# $NetBSD: Makefile,v 1.13 2024/11/11 07:28:15 wiz Exp $

DISTNAME=	Logbook-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
