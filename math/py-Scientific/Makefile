# $NetBSD: Makefile,v 1.19 2004/04/24 21:01:28 wiz Exp $

DISTNAME=	ScientificPython-2.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python//}
CATEGORIES=	math
MASTER_SITES=	http://starship.python.net/crew/hinsen/ScientificPython/ \
		http://dirac.cnrs-orleans.fr/programs/ScientificPython/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

BUILDLINK_DEPENDS.python20=	python20>=2.0.1nb1
BUILDLINK_DEPENDS.python21=	python21>=2.1.1nb1

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

MAKE_ENV+=	NETCDF_PREFIX=${LOCALBASE}

EVAL_PREFIX+=	NETCDFPREFIX=netcdf MPICHPREFIX=mpich
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	OSVER=${OS_VERSION:C/^(.).*/\1/}

post-build:
	@(cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS="${CFLAGS}" \
	  LDFLAGS="${LDFLAGS}" ${PYTHONBIN} compile.py)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
