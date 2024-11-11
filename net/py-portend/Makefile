# $NetBSD: Makefile,v 1.13 2024/11/11 07:28:50 wiz Exp $

DISTNAME=	portend-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/portend
COMMENT=	TCP port monitoring utilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-tempora>=1.8:../../time/py-tempora
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

zz-do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test_portend.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
