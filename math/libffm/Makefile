# $NetBSD: Makefile,v 1.2 2000/11/15 14:20:22 wiz Exp $

DISTNAME=		libffm.0.28
PKGNAME=		libffm-0.28
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.unix-ag.org/user/nils/

MAINTAINER=		root@garbled.net

USE_GMAKE=		yes

ONLY_FOR_PLATFORM=      NetBSD-*-alpha

do-install:
	${INSTALL_DATA} ${WRKSRC}/libffm.a ${PREFIX}/lib/libffm.a
	${INSTALL_DATA} ${WRKSRC}/libffm.h ${PREFIX}/include/libffm.h
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libffm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libffm

.include "../../mk/bsd.pkg.mk"
