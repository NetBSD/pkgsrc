# $NetBSD: Makefile,v 1.102 2026/11/08 21:08:42 wiz Exp $

DISTNAME=	coverage-7.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
#TEST_DEPENDS+=	${PYPKGPREFIX}-gevent>=0:../../net/py-gevent
#TEST_DEPENDS+=	${PYPKGPREFIX}-greenlet>=0:../../devel/py-greenlet

# coverage3 and coverage-${PYVERSSUFFIX} provide deprecation warnings;
# use the one that doesn't.
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/coverage \
		${DESTDIR}${PREFIX}/bin/coverage-${PYVERSSUFFIX}
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage3

# provide scripts for testing to match upstream expectations;
# create test data
pre-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} igor.py zip_mods
	${MKDIR} -p ${BUILDLINK_DIR}/bin
	${ECHO} '#!/bin/sh' > ${BUILDLINK_DIR}/bin/coverage
	${ECHO} 'exec "${PYTHONBIN}" -m coverage "$$@"' >> ${BUILDLINK_DIR}/bin/coverage
	${CHMOD} 755 ${BUILDLINK_DIR}/bin/coverage
.for alias in coverage3 coverage-${PYTHON_VERSION}
	${ECHO} '#!/bin/sh' > ${BUILDLINK_DIR}/bin/${alias}
	${ECHO} 'exec "${PYTHONBIN}" -c "import sys; from coverage.cmdline import main_deprecated; sys.exit(main_deprecated())" "$$@"' >> ${BUILDLINK_DIR}/bin/${alias}
	${CHMOD} 755 ${BUILDLINK_DIR}/bin/${alias}
.endfor

# as of 7.17.2, after 'make install'
# 12 failed, 1631 passed, 62 skipped, 1 error

# The VirtualenvTest tests create a virtualenv and pip install into it, skip them.
do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		pytest-${PYVERSSUFFIX} --ignore=tests/test_venv.py

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
