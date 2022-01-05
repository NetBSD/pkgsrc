# $NetBSD: Makefile,v 1.9 2022/01/05 20:47:36 wiz Exp $

DISTNAME=	numpy-1.16.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

# While this builds with 3, the package only exists to accomodate
# things that require python2.7.
PYTHON_VERSIONS_ACCEPTED=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=		c fortran

.include "../../math/py-numpy/Makefile.make_env"

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py

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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py || ${TRUE}

do-test:
	cd ${WRKDIR} && \
	${RUN} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} -c "import numpy; numpy.test()"

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.29.2
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
