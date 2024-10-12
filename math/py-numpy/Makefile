# $NetBSD: Makefile,v 1.127 2024/10/12 10:56:32 wiz Exp $

DISTNAME=	numpy-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		pkg-config
# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		c99
# checks for gcc 8.4
GCC_REQD+=		8

.include "../../math/py-numpy/make_env.mk"

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py

.include "../../lang/python/pyversion.mk"
PLIST_VARS+=		distutils
# Python 3.12 has no distutils anymore.
.if ${PYTHON_VERSION} < 312
PLIST.distutils=	yes
.endif
PRINT_PLIST_AWK+=	/\/distutils\// { $$0 = "$${PLIST.distutils}" $$0 }

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

# Check if the numpy/scipy ecosystem is ready for full ILP64 before
# allowing/setting BLAS_INDEX64=yes. Scipy needs both variants right now,
# wich does not work without standardized symbol suffix.
# Will need -Csetup-args=Duse-ilp64, too.
# TODO: accelerate.framework has no pkg-config yet (see blas.buildlink3.mk).
BLAS_ACCEPTED=		${_BLAS_TYPES}
BLAS_C_INTERFACE=	yes
# Cblas and lapack API (not lapacke) is desired.
# Meson build uses pkg-config since 1.26.2 (or elaborate own logic not
# suitable here) and guesses for cblas if blas lib does not contain the
# C interface. That covers netlib for us, and openblas builds serve
# all APIs.
WHEEL_ARGS+=		-Csetup-args=-Dblas=${BLAS_PC}
WHEEL_ARGS+=		-Csetup-args=-Dlapack=${LAPACK_PC}
WHEEL_ARGS+=		-Ccompile-args=-j${MAKE_JOBS:U1}

# disable AVX 512; the support on NetBSD is incomplete, see PR 58539
# from reports on the Haskell forums, the support on other operating
# system is troubled too.
WHEEL_ARGS+=		-Csetup-args=-Dcpu-dispatch="max -avx512f -avx512cd -avx512_knl -avx512_knm -avx512_skx -avx512_clx -avx512_cnl -avx512_icl -avx512_spr"

# Remove invalid __STDC_VERSION__ setting
BUILDLINK_TRANSFORM.SunOS+=	rm:-D__STDC_VERSION__=0

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

# Files don't exist with Python 3.12, so add '-f' to ${RM}
# (Please check if this is still necessary after updates.)
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/distutils/command/config.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/distutils/fcompiler/__init__.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/distutils/fcompiler/g95.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/distutils/fcompiler/gnu.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/numpy/distutils/log.py.orig
.for bin in f2py numpy-config
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing path to numpy-configure (for tests).
SUBST_FILES.paths=	numpy/tests/test_configtool.py
SUBST_SED.paths=	-e 's,'numpy-config','numpy-config-${PYVERSSUFFIX}',g'

# as of 2.1.2
# 35 failed, 46413 passed, 1713 skipped, 2799 deselected, 34 xfailed, 5 xpassed, 1 warning
do-test:
	cd ${WRKDIR} && \
	${SETENV} ${TEST_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} -c "import numpy; numpy.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
