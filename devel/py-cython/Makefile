# $NetBSD: Makefile,v 1.93 2024/05/26 01:59:19 gutteridge Exp $

DISTNAME=	Cython-3.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-1.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=69.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

REPLACE_PYTHON+=	Cython/Build/Cythonize.py
REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

USE_CC_FEATURES=	c99

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cython cython-${PYVERSSUFFIX} && \
	${MV} cythonize cythonize-${PYVERSSUFFIX} && \
	${MV} cygdb cygdb-${PYVERSSUFFIX} || ${TRUE}

# remove tests that are so broken they break collecting the other tests
pre-test:
	${RM} -f ${WRKSRC}/Cython/Debugger/Tests/test_libcython_in_gdb.py
	${RM} -f ${WRKSRC}/Cython/Debugger/Tests/test_libpython_in_gdb.py
	${RM} -f ${WRKSRC}/docs/examples/tutorial/clibraries/test_queue.py
	${RM} -f ${WRKSRC}/pyximport/test/test_reload.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
