# $NetBSD: Makefile,v 1.10 2003/09/17 19:40:08 grant Exp $

DISTNAME=	cdb-0.75
CATEGORIES=	databases
MASTER_SITES=	http://cr.yp.to/cdb/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/cdb.html
COMMENT=	Creates and reads constant databases

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/bsd.pkg.mk"
