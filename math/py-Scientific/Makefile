# $NetBSD: Makefile,v 1.72 2022/01/10 23:46:49 wiz Exp $

DISTNAME=	ScientificPython-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
PKGREVISION=	22
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/4411/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirac.cnrs-orleans.fr/ScientificPython/
COMMENT=	Python modules for scientific computing
LICENSE=	cecill-2.1

CONFLICTS+=	py-Scientific-[0-9]*

MAKE_ENV+=	NETCDF_PREFIX=${BUILDLINK_PREFIX.netcdf}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.8.1

.include "../../lang/python/pyversion.mk"

PYPLAT_CMD=	${PYTHONBIN} -c "import sys; print sys.platform"
PLIST_SUBST+=	PYPLAT=${PYPLAT_CMD:sh}

INSTALLATION_DIRS=	bin

post-build:
	${RUN} cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS=${CFLAGS:Q} \
	  LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}" ${PYTHONBIN} compile.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${DESTDIR}${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
