# $NetBSD: Makefile,v 1.99 2026/10/22 16:33:20 adam Exp $

DISTNAME=	coverage-7.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.57.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage3

# Testing: AssertionError: assert None
# 'fixed' by running as root, needs to find a writeable directory

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
