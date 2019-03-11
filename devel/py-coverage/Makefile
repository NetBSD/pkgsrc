# $NetBSD: Makefile,v 1.17 2019/03/11 13:55:28 adam Exp $

DISTNAME=	coverage-4.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.4.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.2.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.20.1:../../devel/py-test-xdist

PYSETUPTESTTARGET=	pytest

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage[23]

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
