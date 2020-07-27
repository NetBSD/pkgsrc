# $NetBSD: Makefile,v 1.27 2020/07/27 08:15:15 adam Exp $

DISTNAME=	coverage-5.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.4.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.20.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest-mixins-[0-9]*:../../devel/py-unittest-mixins

PYTHON_VERSIONED_DEPENDENCIES=	test:test

PYSETUPTESTTARGET=	pytest

# https://github.com/nedbat/coveragepy/issues/983
CHECK_PORTABILITY_SKIP=	tests/gold/html/Makefile

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage[23]

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
