# $NetBSD: Makefile,v 1.32 2010/05/29 03:18:54 obache Exp $

DISTNAME=	ScientificPython-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
CATEGORIES=	math python
MASTER_SITES=	http://sourcesup.cru.fr/frs/download.php/2309/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirac.cnrs-orleans.fr/ScientificPython/
COMMENT=	Python modules for scientific computing

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	py-Scientific-[0-9]*

PYDISTUTILSPKG=	yes

MAKE_ENV+=	NETCDF_PREFIX=${BUILDLINK_PREFIX.netcdf}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=	OSVER=${OS_VERSION:C/^(.).*/\1/}

INSTALLATION_DIRS=	bin

post-build:
	${RUN} cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS=${CFLAGS:Q} \
	  LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}" ${PYTHONBIN} compile.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${DESTDIR}${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
