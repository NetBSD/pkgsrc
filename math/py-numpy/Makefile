# $NetBSD: Makefile,v 1.11 2010/04/24 17:13:55 gls Exp $
#

DISTNAME=	numpy-1.4.1
PKGNAME=	${PYPKGPREFIX}-numpy-1.4.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numpy.scipy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
USE_LANGUAGES+=	c fortran
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	ATLAS=None

REPLACE_PYTHON+=	numpy/core/scons_support.py
REPLACE_PYTHON+=	numpy/distutils/from_template.py
REPLACE_PYTHON+=	numpy/distutils/system_info.py
REPLACE_PYTHON+=	numpy/ma/bench.py
REPLACE_PYTHON+=	numpy/distutils/conv_template.py

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95)
PYSETUPBUILDARGS+= --fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mgfortran)
PYSETUPBUILDARGS+= --fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+= --fcompiler=gnu
.endif

# needs devel/py-nose
#do-test:
#	${PYTHONBIN} -c "import numpy; numpy.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
