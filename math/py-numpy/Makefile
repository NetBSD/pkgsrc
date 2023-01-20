# $NetBSD: Makefile,v 1.102 2023/01/20 13:39:21 wiz Exp $

DISTNAME=	numpy-1.23.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=		c99 c++11 fortran

.include "../../math/py-numpy/Makefile.make_env"

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

USE_PKG_RESOURCES=	yes

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

.include "../../mk/bsd.prefs.mk"

# numpy fails using the gold linker with:
# fatal error: --sysroot=: must take a non-empty argument
# Work around it on DragonFly by specifying the classic gnu linker
MAKE_ENV.DragonFly+=	LDVER=ld.bfd

# Remove invalid __STDC_VERSION__ setting
BUILDLINK_TRANSFORM.SunOS+=	rm:-D__STDC_VERSION__=0

pre-install:
	${RM} -f ${WRKSRC}/numpy/core/include/numpy/npy_common.h.orig

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py3 || ${TRUE}

# as of 1.23.5
# 8 failed, 18561 passed, 782 skipped, 1306 deselected, 41 xfailed, 2 xpassed, 59 warnings
do-test:
	cd ${WRKDIR} && \
	${SETENV} ${TEST_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} -c "import numpy; numpy.test()"

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.29.21
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
