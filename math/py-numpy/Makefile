# $NetBSD: Makefile,v 1.28 2015/04/17 00:41:38 wen Exp $

DISTNAME=	numpy-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

USE_LANGUAGES=		c fortran
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=		ATLAS=None

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	numpy/*.py
REPLACE_PYTHON+=	numpy/compat/*.py
REPLACE_PYTHON+=	numpy/core/*.py
REPLACE_PYTHON+=	numpy/core/tests/*.py
REPLACE_PYTHON+=	numpy/distutils/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/f2py_ext/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/f2py_f90_ext/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/gen_ext/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/pyrex_ext/*.py
REPLACE_PYTHON+=	numpy/distutils/tests/swig_ext/*.py
REPLACE_PYTHON+=	numpy/f2py/*.py
REPLACE_PYTHON+=	numpy/f2py/docs/usersguide/*.py
REPLACE_PYTHON+=	numpy/fft/tests/*.py
REPLACE_PYTHON+=	numpy/ma/*.py
REPLACE_PYTHON+=	numpy/matrixlib/*.py
REPLACE_PYTHON+=	numpy/random/mtrand/*.py
REPLACE_PYTHON+=	numpy/testing/*.py

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95)
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mgfortran)
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+=	--fcompiler=gnu
.endif

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

.include "../../mk/bsd.prefs.mk"

# needs devel/py-nose
#do-test:
#	${PYTHONBIN} -c "import numpy; numpy.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.if ${OPSYS} != "Darwin"
# blas and lapack are not needed; numpy will use Accelerate.framework
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
