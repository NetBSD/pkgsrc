# $NetBSD: Makefile,v 1.9 2001/05/14 16:22:35 drochner Exp $

DISTNAME=	ScientificPython-2.2
PKGNAME=	py-Scientific-2.2
CATEGORIES=	math
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

DEPENDS+=	netcdf>=3.0:../../devel/netcdf
DEPENDS+=	mpich>=1.2.1:../../parallel/mpi-ch
DEPENDS+=	py-Numeric-[0-9]*:../../math/py-Numeric

USE_PYTHON=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

NETCDFPREFIX_DEFAULT=${LOCALBASE}
MPICHPREFIX_DEFAULT=${LOCALBASE}
EVAL_PREFIX+=	NETCDFPREFIX=netcdf MPICHPREFIX=mpich

do-configure:
	${SED} -e "s|@NETCDFPREFIX@|${NETCDFPREFIX}|g"			\
	       -e "s|@MPICHPREFIX@|${MPICHPREFIX}|g"			\
	${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp
	${MV} -f ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py
	${SED} -e "s|@MPICHPREFIX@|${MPICHPREFIX}|g"			\
	${FILESDIR}/Setup.in > ${WRKSRC}/Src/MPI/Setup.in

post-build:
	cd ${WRKSRC}/Src/MPI && ${PYTHON} compile.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-Scientific
	cd ${WRKSRC} && ${INSTALL_DATA} README COPYRIGHT 		\
		Doc/PDF/manual.pdf ${PREFIX}/share/doc/py-Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Doc/HTML/* 				\
	${PREFIX}/share/doc/html/py-Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Examples/* 				\
	${PREFIX}/share/examples/py-Scientific/

.include "../../mk/bsd.pkg.mk"
