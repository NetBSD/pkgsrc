# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:20 jlam Exp $

DISTNAME=		metis-4.0
CATEGORIES=		math
MASTER_SITES=		http://www-users.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-users.cs.umn.edu/~karypis/metis/
COMMENT=		Unstructured graph partitioning and sparse matrix ordering system

BUILD_TARGET=		default
INSTALLATION_DIRS=	bin lib

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} graphchk kmetis mesh2dual 	\
		mesh2nodal oemetis onmetis partdmesh partnmesh pmetis	\
		${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h ${PREFIX}/include/metis/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/metis
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${PREFIX}/share/doc/metis
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/metis
	cd ${WRKSRC}/Graphs && ${INSTALL_DATA} 0README 4elt.graph 	\
		metis.mesh test.mgraph ${PREFIX}/share/examples/metis/
	${INSTALL_DATA} ${WRKSRC}/Test/mtest.c ${PREFIX}/share/examples/metis

.include "../../mk/bsd.pkg.mk"
