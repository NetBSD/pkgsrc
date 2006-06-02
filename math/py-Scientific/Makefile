# $NetBSD: Makefile,v 1.28 2006/06/02 23:33:30 joerg Exp $

DISTNAME=	ScientificPython-2.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ScientificPython/ \
		http://dirac.cnrs-orleans.fr/programs/ScientificPython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

PYTHON_VERSIONS_ACCEPTED=	24 23 22

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

MAKE_ENV+=	NETCDF_PREFIX=${LOCALBASE:Q}

EVAL_PREFIX+=	NETCDFPREFIX=netcdf MPICHPREFIX=mpich
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=	OSVER=${OS_VERSION:C/^(.).*/\1/}

post-build:
	@(cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS="${CFLAGS}" \
	  LDFLAGS="${LDFLAGS} ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}" ${PYTHONBIN} compile.py)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
