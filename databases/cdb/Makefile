# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 18:43:10 jlam Exp $

DISTNAME=	cdb-0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://cr.yp.to/cdb.html
COMMENT=	creates and reads constant databases

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if (${MACHINE_ARCH} == "arm32" || ${MACHINE_ARCH} == "arm")
.if (${CFLAGS:M-O2} == "-O2")
CFLAGS:=	${CFLAGS:S/-O2/-O0/}
.endif
.endif

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/bsd.pkg.mk"
