# $NetBSD: Makefile,v 1.43 2023/10/28 19:56:58 wiz Exp $

DISTNAME=	coverage-7.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.57.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage3

# AssertionError: assert None
# 'fixed' by running as root, needs to find a writeable directory
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
