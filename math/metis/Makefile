# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 04:18:37 jtb Exp $

DISTNAME=		metis-4.0
CATEGORIES=		math
MASTER_SITES=		http://www-users.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www-users.cs.umn.edu/~karypis/metis/

ALL_TARGET=		default

do-install:
	@for f in graphchk kmetis mesh2dual mesh2nodal oemetis onmetis	\
	partdmesh partnmesh pmetis; do					\
	i="${INSTALL_PROGRAM} ${WRKSRC}/$$f ${PREFIX}/bin/";		\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/metis
	@for f in ${WRKSRC}/Lib/*.h; do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/include/metis/";	\
	${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/metis
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${PREFIX}/share/doc/metis
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/metis
	@for f in 0README 4elt.graph metis.mesh test.mgraph; do	\
	i="${INSTALL_DATA} ${WRKSRC}/Graphs/$$f			\
	${PREFIX}/share/examples/metis/";			\
	${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA} ${WRKSRC}/Test/mtest.c ${PREFIX}/share/examples/metis

.include "../../mk/bsd.pkg.mk"
