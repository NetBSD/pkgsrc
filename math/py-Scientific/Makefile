# $NetBSD: Makefile,v 1.1.1.1 2001/01/30 02:01:43 jtb Exp $

DISTNAME=	ScientificPython-2.0.1
PKGNAME=	py-Scientific-2.0.1
CATEGORIES=	math
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html

DEPENDS+=	python>=1.5:../../lang/python
DEPENDS+=	netcdf>=3.0:../../devel/netcdf
DEPENDS+=	mpich-[0-9]*:../../parallel/mpi-ch
DEPENDS+=	py-Numeric-[0-9]*:../../math/py-Numeric

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EVAL_PREFIX+=	PYPREFIX=python NETCDFPREFIX=netcdf MPICHPREFIX=mpich

do-configure:
	${SED} -e "s|@NETCDFPREFIX@|${NETCDFPREFIX}|g"	\
	       -e "s|@MPICHPREFIX@|${MPICHPREFIX}|g"		\
	< ${FILESDIR}/Setup.in > ${WRKSRC}/Src/Setup.in

do-build:
	(cd ${WRKSRC}/Src && ${PYPREFIX}/bin/python compile.py)

post-build:
	(eval `${PYPREFIX}/bin/python ${FILESDIR}/printpypath.py` && \
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" \
	< ${PKGDIR}/PLIST > ${PLIST_SRC})

do-install:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python install.py)
	${INSTALL_DATA_DIR} ${PREFIX}/include/python2.0/Scientific
	@for f in ${WRKSRC}/Scientific/Include/Scientific/*; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/include/python2.0/Scientific/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-Scientific
	@for f in README COPYRIGHT Doc/PDF/manual.pdf; do \
		i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/py-Scientific/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/py-Scientific
	@for f in ${WRKSRC}/Doc/HTML/*; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/html/py-Scientific/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-Scientific
	@for f in ${WRKSRC}/Examples/*; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/py-Scientific/"; \
		${ECHO} $$i; $$i; \
	done

.include "../../mk/bsd.pkg.mk"
