# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 18:19:19 jtb Exp $

DISTNAME=	otter-3.0.6
CATEGORIES=	math
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/Otter/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.mcs.anl.gov/AR/otter/

WRKSRC=		${WRKDIR}/${PKGNAME}/source

ALL_TARGET=	otter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otter ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/otter
	@(cd ${WRKDIR}/${PKGNAME};					\
	for r in Announce Changelog Copying README*;			\
	do								\
	${INSTALL_DATA} $$r ${PREFIX}/share/doc/otter;			\
	done;								\
	for d in auto fringe ivy kalman misc program split wos;		\
	do								\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter/$$d;		\
	${INSTALL_DATA} examples/$$d/* ${PREFIX}/share/examples/otter/$$d;\
	done;								\
	for p in Run_all objects summary;				\
	do								\
	${INSTALL_SCRIPT} examples/$$p ${PREFIX}/share/examples/otter/$$p;\
	done;								\
	${INSTALL_DATA} examples/README ${PREFIX}/share/examples/otter;	\
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/document/* 		\
	${PREFIX}/share/doc/otter)

.include "../../mk/bsd.pkg.mk"
