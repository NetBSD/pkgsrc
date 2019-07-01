# $NetBSD: Makefile,v 1.58 2019/07/01 04:08:31 ryoon Exp $

DISTNAME=	ScientificPython-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
PKGREVISION=	10
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/4411/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirac.cnrs-orleans.fr/ScientificPython/
COMMENT=	Python modules for scientific computing
LICENSE=	cecill-2.1

CONFLICTS+=	py-Scientific-[0-9]*

MAKE_ENV+=	NETCDF_PREFIX=${BUILDLINK_PREFIX.netcdf}

.include "../../lang/python/pyversion.mk"

PYPLAT_CMD=	${PYTHONBIN} -c "import sys; print sys.platform"
PLIST_SUBST+=	PYPLAT=${PYPLAT_CMD:sh}

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 2.8.1

INSTALLATION_DIRS=	bin

post-build:
	${RUN} cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS=${CFLAGS:Q} \
	  LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}" ${PYTHONBIN} compile.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${DESTDIR}${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
