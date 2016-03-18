# $NetBSD: Makefile,v 1.19 2016/03/18 12:54:57 wiedi Exp $

DISTNAME=	scipy-0.15.1
PKGNAME=	${PYPKGPREFIX}-scipy-0.15.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python
LICENSE=	modified-bsd

PLIST_SUBST+=   PYPKGPREFIX=${PYPKGPREFIX}
USE_LANGUAGES+=	c c++ fortran
MAKE_ENV+=	ATLAS=None

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95)
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mgfortran)
PYSETUPBUILDARGS+=	--fcompiler=gnu95
LDFLAGS.Darwin+=	-undefined dynamic_lookup
.else
BROKEN=		Requires fortran 95
.endif

CPPFLAGS+=	-D__STDC_FORMAT_MACROS
FFLAGS+=	-fPIC

REPLACE_PYTHON+=	scipy/cluster/setup.py
REPLACE_PYTHON+=	scipy/cluster/tests/test_hierarchy.py
REPLACE_PYTHON+=	scipy/cluster/tests/test_vq.py
REPLACE_PYTHON+=	scipy/fftpack/setup.py
REPLACE_PYTHON+=	scipy/fftpack/tests/test_basic.py
REPLACE_PYTHON+=	scipy/fftpack/tests/test_helper.py
REPLACE_PYTHON+=	scipy/fftpack/tests/test_pseudo_diffs.py
REPLACE_PYTHON+=	scipy/fftpack/tests/test_real_transforms.py
REPLACE_PYTHON+=	scipy/integrate/setup.py
REPLACE_PYTHON+=	scipy/interpolate/fitpack.py
REPLACE_PYTHON+=	scipy/interpolate/setup.py
REPLACE_PYTHON+=	scipy/interpolate/tests/test_fitpack.py
REPLACE_PYTHON+=	scipy/interpolate/tests/test_fitpack2.py
REPLACE_PYTHON+=	scipy/interpolate/tests/test_rbf.py
REPLACE_PYTHON+=	scipy/io/arff/arffread.py
REPLACE_PYTHON+=	scipy/io/arff/setup.py
REPLACE_PYTHON+=	scipy/io/arff/tests/test_arffread.py
REPLACE_PYTHON+=	scipy/io/harwell_boeing/setup.py
REPLACE_PYTHON+=	scipy/io/matlab/setup.py
REPLACE_PYTHON+=	scipy/io/matlab/tests/test_mio.py
REPLACE_PYTHON+=	scipy/io/matlab/tests/test_mio_funcs.py
REPLACE_PYTHON+=	scipy/io/setup.py
REPLACE_PYTHON+=	scipy/io/tests/test_mmio.py
REPLACE_PYTHON+=	scipy/lib/blas/setup.py
REPLACE_PYTHON+=	scipy/lib/blas/tests/test_blas.py
REPLACE_PYTHON+=	scipy/lib/lapack/setup.py
REPLACE_PYTHON+=	scipy/lib/lapack/tests/test_lapack.py
REPLACE_PYTHON+=	scipy/lib/setup.py
REPLACE_PYTHON+=	scipy/linalg/setup.py
REPLACE_PYTHON+=	scipy/linalg/tests/test_basic.py
REPLACE_PYTHON+=	scipy/linalg/tests/test_blas.py
REPLACE_PYTHON+=	scipy/linalg/tests/test_decomp.py
REPLACE_PYTHON+=	scipy/linalg/tests/test_lapack.py
REPLACE_PYTHON+=	scipy/linalg/tests/test_matfuncs.py
REPLACE_PYTHON+=	scipy/odr/setup.py
REPLACE_PYTHON+=	scipy/optimize/setup.py
REPLACE_PYTHON+=	scipy/optimize/tests/test_zeros.py
REPLACE_PYTHON+=	scipy/signal/setup.py
REPLACE_PYTHON+=	scipy/sparse/generate_sparsetools.py
REPLACE_PYTHON+=	scipy/sparse/linalg/dsolve/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/eigen/arpack/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/eigen/arpack/tests/test_arpack.py
REPLACE_PYTHON+=	scipy/sparse/linalg/eigen/lobpcg/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/eigen/lobpcg/tests/test_lobpcg.py
REPLACE_PYTHON+=	scipy/sparse/linalg/eigen/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/isolve/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/isolve/tests/test_iterative.py
REPLACE_PYTHON+=	scipy/sparse/linalg/isolve/tests/test_lgmres.py
REPLACE_PYTHON+=	scipy/sparse/linalg/setup.py
REPLACE_PYTHON+=	scipy/sparse/linalg/tests/test_matfuncs.py
REPLACE_PYTHON+=	scipy/sparse/setup.py
REPLACE_PYTHON+=	scipy/spatial/setup.py
REPLACE_PYTHON+=	scipy/spatial/tests/test_distance.py
REPLACE_PYTHON+=	scipy/special/generate_ufuncs.py
REPLACE_PYTHON+=	scipy/special/setup.py
REPLACE_PYTHON+=	scipy/special/spfun_stats.py
REPLACE_PYTHON+=	scipy/stats/setup.py
REPLACE_PYTHON+=	scipy/weave/setup.py

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	${FIND} ${DESTDIR}${PREFIX} -name "*.so" | while read lib; do   \
		libname=`basename $${lib}`;                             \
		libdir=`dirname $${lib} | sed -e 's,${DESTDIR},,'`;     \
		install_name_tool -id $${libdir}/$${libname} $${lib};   \
	done
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
