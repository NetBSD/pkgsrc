# $NetBSD: Makefile,v 1.15 2026/08/23 06:30:30 wiz Exp $

DISTNAME=		metis-4.0.3
CATEGORIES=		math
MASTER_SITES=		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/KarypisLab/METIS
COMMENT=		Unstructured graph partitioning and sparse matrix ordering system

BUILD_TARGET=		default
INSTALLATION_DIRS=	bin include/metis lib share/doc/metis share/examples/metis

CFLAGS+=		-Wno-implicit-function-declaration
CFLAGS+=		-Wno-implicit-int

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} graphchk kmetis mesh2dual 	\
		mesh2nodal oemetis onmetis partdmesh partnmesh pmetis	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h				\
		${DESTDIR}${PREFIX}/include/metis/
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps				\
		${DESTDIR}${PREFIX}/share/doc/metis
	cd ${WRKSRC}/Graphs && ${INSTALL_DATA} 0README 4elt.graph 	\
		metis.mesh test.mgraph					\
		${DESTDIR}${PREFIX}/share/examples/metis/
	${INSTALL_DATA} ${WRKSRC}/Test/mtest.c				\
		${DESTDIR}${PREFIX}/share/examples/metis

.include "../../mk/bsd.pkg.mk"
