# $NetBSD: Makefile,v 1.19 2012/08/09 12:42:16 jperkin Exp $
#

DISTNAME=	numpy-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numpy.scipy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=	c fortran
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	ATLAS=None

REPLACE_PYTHON+=	numpy/core/scons_support.py
REPLACE_PYTHON+=	numpy/distutils/from_template.py
REPLACE_PYTHON+=	numpy/distutils/system_info.py
REPLACE_PYTHON+=	numpy/ma/bench.py
REPLACE_PYTHON+=	numpy/distutils/conv_template.py

SUBST_CLASSES+=	numpy
SUBST_STAGE.numpy=	post-patch
SUBST_FILES.numpy=	numpy/f2py/setup.py numpy/f2py/setupscons.py
SUBST_SED.numpy=	-e 's:/usr/bin/env %s:${PYTHONBIN}:'
SUBST_SED.numpy+=	-e 's:%(os.path.basename(sys.executable))::'

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95)
PYSETUPBUILDARGS+= --fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mgfortran)
PYSETUPBUILDARGS+= --fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+= --fcompiler=gnu
.endif

# According to http://projects.scipy.org/numpy/ticket/1101,
# LDFLAGS should either not be set or include -shared.
LDFLAGS+=		-shared

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

# needs devel/py-nose
#do-test:
#	${PYTHONBIN} -c "import numpy; numpy.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
