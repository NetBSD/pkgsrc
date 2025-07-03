# $NetBSD: Makefile,v 1.105 2025/07/03 19:18:03 wiz Exp $

DISTNAME=	cython-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cython.org/
COMMENT=	C-Extensions for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

REPLACE_PYTHON+=	Cython/Debugger/Cygdb.py
REPLACE_PYTHON+=	Cython/Debugger/libpython.py
REPLACE_PYTHON+=	cython.py

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

USE_CC_FEATURES=	c99
# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD+=		c99

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
