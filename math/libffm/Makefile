# $NetBSD: Makefile,v 1.6 2004/01/24 13:58:23 grant Exp $

DISTNAME=		libffm.0.28
PKGNAME=		libffm-0.28
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.unix-ag.org/user/nils/

MAINTAINER=		root@garbled.net
COMMENT=		Fast alpha-optimized replacement for some libm routines

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=      NetBSD-*-alpha

do-install:
	${INSTALL_DATA} ${WRKSRC}/libffm.a ${PREFIX}/lib/libffm.a
	${INSTALL_DATA} ${WRKSRC}/libffm.h ${PREFIX}/include/libffm.h
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libffm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libffm

.include "../../mk/bsd.pkg.mk"
