# $NetBSD: Makefile,v 1.1.1.1 2000/02/12 15:58:52 garbled Exp $

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

.include "../../mk/bsd.pkg.mk"
