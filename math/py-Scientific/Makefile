# $NetBSD: Makefile,v 1.18 2004/02/12 16:53:50 recht Exp $

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

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

MAKE_ENV+=	NETCDF_PREFIX=${LOCALBASE}

EVAL_PREFIX+=	NETCDFPREFIX=netcdf MPICHPREFIX=mpich
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-build:
	@(cd ${WRKSRC}/Src/MPI && ${SETENV} CFLAGS="${CFLAGS}" \
	  LDFLAGS="${LDFLAGS}" ${PYTHONBIN} compile.py)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython \
		${PREFIX}/bin/mpipython${PYVERSSUFFIX}

.include "../../devel/netcdf/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../parallel/mpi-ch/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
