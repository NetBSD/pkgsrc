# $NetBSD: Makefile,v 1.1.1.1 2001/12/10 18:11:46 martti Exp $

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
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/bsd.pkg.mk"
