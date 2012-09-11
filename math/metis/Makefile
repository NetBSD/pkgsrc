# $NetBSD: Makefile,v 1.12 2012/09/11 23:04:24 asau Exp $

DISTNAME=		metis-4.0
CATEGORIES=		math
MASTER_SITES=		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://glaros.dtc.umn.edu/gkhome/views/metis/
COMMENT=		Unstructured graph partitioning and sparse matrix ordering system

BUILD_TARGET=		default
INSTALLATION_DIRS=	bin lib

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} graphchk kmetis mesh2dual 	\
		mesh2nodal oemetis onmetis partdmesh partnmesh pmetis	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h				\
		${DESTDIR}${PREFIX}/include/metis/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/metis
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps				\
		${DESTDIR}${PREFIX}/share/doc/metis
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/metis
	cd ${WRKSRC}/Graphs && ${INSTALL_DATA} 0README 4elt.graph 	\
		metis.mesh test.mgraph					\
		${DESTDIR}${PREFIX}/share/examples/metis/
	${INSTALL_DATA} ${WRKSRC}/Test/mtest.c				\
		${DESTDIR}${PREFIX}/share/examples/metis

.include "../../mk/bsd.pkg.mk"
