# $NetBSD: Makefile,v 1.5 2001/03/30 22:23:07 jtb Exp $

DISTNAME=	ScientificPython-2.2
PKGNAME=	py-Scientific-2.2
CATEGORIES=	math
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

DEPENDS+=	python>=1.5:../../lang/python
DEPENDS+=	netcdf>=3.0:../../devel/netcdf
DEPENDS+=	mpich>=1.2.1:../../parallel/mpi-ch
DEPENDS+=	py-Numeric-[0-9]*:../../math/py-Numeric

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EVAL_PREFIX+=	PYPREFIX=python NETCDFPREFIX=netcdf MPICHPREFIX=mpich

do-configure:
	${SED} -e "s|@NETCDFPREFIX@|${NETCDFPREFIX}|g"			\
	       -e "s|@MPICHPREFIX@|${MPICHPREFIX}|g"			\
	${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp
	${MV} -f ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py
	${SED} -e "s|@MPICHPREFIX@|${MPICHPREFIX}|g"			\
	${FILESDIR}/Setup.in > ${WRKSRC}/Src/MPI/Setup.in

do-build:
	cd ${WRKSRC} && ${PYPREFIX}/bin/python setup.py build
	cd ${WRKSRC}/Src/MPI && ${PYPREFIX}/bin/python compile.py

post-build:
	(eval `${PYPREFIX}/bin/python ${FILESDIR}/printpypath.py` && 	\
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" 	\
	${PKGDIR}/PLIST > ${PLIST_SRC})

do-install:
	cd ${WRKSRC} && ${PYPREFIX}/bin/python setup.py install
	${INSTALL_PROGRAM} ${WRKSRC}/Src/MPI/mpipython ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/${PYINC}/Scientific
	${INSTALL_DATA}	${WRKSRC}/Include/Scientific/* 			\
	${PREFIX}/${PYINC}/Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-Scientific
	for f in README COPYRIGHT Doc/PDF/manual.pdf; do 		\
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/py-Scientific/; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Doc/HTML/* 				\
	${PREFIX}/share/doc/html/py-Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Examples/* 				\
	${PREFIX}/share/examples/py-Scientific/

.include "../../mk/bsd.pkg.mk"
