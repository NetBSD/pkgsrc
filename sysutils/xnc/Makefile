# $NetBSD: Makefile,v 1.5 2002/03/17 16:07:15 fredb Exp $

DISTNAME=	xnc-4.4.5.src
PKGNAME=	xnc-4.4.5
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xnc
		${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
