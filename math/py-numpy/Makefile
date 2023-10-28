# $NetBSD: Makefile,v 1.110 2023/10/28 19:57:11 wiz Exp $

DISTNAME=	numpy-1.25.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions

USE_LANGUAGES=		c c++ fortran

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		c99

USE_CXX_FEATURES+=	c++17

.include "../../math/py-numpy/make_env.mk"

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "g95"
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "gfortran"
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+=	--fcompiler=gnu
.endif

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

BLAS_ACCEPTED=		${_BLAS_TYPES} accelerate.framework
BLAS_C_INTERFACE=	yes
CPPFLAGS+=		${BLAS_INCLUDES}

# Remove invalid __STDC_VERSION__ setting
BUILDLINK_TRANSFORM.SunOS+=	rm:-D__STDC_VERSION__=0

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py3 || ${TRUE}
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/core/include/numpy/npy_common.h.orig

# as of 1.24.2
# 29 failed, 26625 passed, 1481 skipped, 1307 deselected, 35 xfailed, 2 xpassed, 40 warnings
do-test:
	cd ${WRKDIR} && \
	${SETENV} ${TEST_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} -c "import numpy; numpy.test()"

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.29.21
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
