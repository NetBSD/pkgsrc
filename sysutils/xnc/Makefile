# $NetBSD: Makefile,v 1.1.1.1 2001/09/17 05:40:06 zuntum Exp $

DISTNAME=	xnc-4.4.5.src
PKGNAME=	xnc-4.4.5
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xnc
		${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
