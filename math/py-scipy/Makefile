# $NetBSD: Makefile,v 1.66 2023/07/01 08:37:41 wiz Exp $

DISTNAME=	scipy-1.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pybind11-[0-9]*:../../devel/py-pybind11
DEPENDS+=	${PYPKGPREFIX}-pythran>=0.9.11:../../math/py-pythran
TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pooch-[0-9]*:../../devel/py-pooch
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES+=	c99 c++11 fortran
MAKE_ENV+=	ATLAS=None
GCC_REQD+=	8
EGG_NAME=	${DISTNAME:S/scipy/SciPy/}

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

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

# Prefer boost-headers from PkgSrc which are properly patched.
post-configure:
	${RM} -f -r ${WRKSRC}/scipy/_lib/boost/boost
	${LN} -s ${BUILDLINK_DIR}/include/boost ${WRKSRC}/scipy/_lib/boost/boost

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

BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers>=1.77.0nb1
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/fftw/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.18.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
