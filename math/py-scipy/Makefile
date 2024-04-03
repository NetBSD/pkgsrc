# $NetBSD: Makefile,v 1.76 2024/04/03 19:36:38 thor Exp $

DISTNAME=	scipy-1.11.4
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.35:../../devel/py-cython
# Package directly expresses a meson minimum; we need higher to pick up our
# multi-version build fixes.
TOOL_DEPENDS+=	meson>=1.2.2nb1:../../devel/meson
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pybind11>=2.10.4:../../devel/py-pybind11
DEPENDS+=	${PYPKGPREFIX}-pythran>=0.12.0:../../math/py-pythran
TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pooch-[0-9]*:../../devel/py-pooch
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES+=	c99 c++11 fortran
USE_TOOLS+=	pkg-config
MAKE_ENV+=	ATLAS=None
GCC_REQD+=	8
EGG_NAME=	${DISTNAME:S/scipy/SciPy/}

SUBST_CLASSES+=		pythran
SUBST_STAGE.pythran=	pre-configure
SUBST_MESSAGE.pythran=	Fixing pythran binary name.
SUBST_FILES.pythran=	meson.build
SUBST_SED.pythran=	-e "s,'pythran','pythran-${PYVERSSUFFIX}',"

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "gfortran"
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.else
BROKEN=			"Requires fortran 95"
.endif

CPPFLAGS+=	-D__STDC_FORMAT_MACROS
FFLAGS+=	-fPIC

LDFLAGS.Darwin+=	-headerpad_max_install_names

# Same as for py-numpy.
# Except that py-scipy needs explicit linkage to libblas.so for
# netlib (otherwise there will be missing symbols in _superlu.so (vendored).
# Meson will locate libcblas itself with -Dblas=blas by guesswork,
# satisfying the meson setup. Proper fix is a future meson build where
# one can specify blas and cblas separately. The distinction
# does not matter for openblas.
BLAS_ACCEPTED=		${_BLAS_TYPES}
BLAS_C_INTERFACE=	yes
WHEEL_ARGS+=		-Csetup-args=-Dblas=${BLAS_PC}
WHEEL_ARGS+=		-Csetup-args=-Dlapack=${LAPACK_PC}
WHEEL_ARGS+=		-Ccompile-args=-j${MAKE_JOBS}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${FIND} ${DESTDIR}${PREFIX} -name "*.so" |                      \
		while read lib; do                                      \
		libname=`basename $${lib}`;                             \
		libdir=`dirname $${lib} | sed -e 's,${DESTDIR},,'`;     \
		install_name_tool -id $${libdir}/$${libname} $${lib};   \
	done
.endif

# self test failures for 1.1.0 reported at
# https://github.com/scipy/scipy/issues/9196
# needs 'make install' first!
do-test:
	cd ${WRKDIR} && \
	${PYTHONBIN} -c "import scipy; scipy.test('full')"

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.21.6
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
