# $NetBSD: Makefile,v 1.2 2002/03/30 13:15:02 yyamano Exp $

DISTNAME=	cdb-0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://cr.yp.to/cdb.html
COMMENT=	creates and reads constant databases

ALL_TARGET=	it
INSTALL_TARGET=	setup check

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/bsd.pkg.mk"
