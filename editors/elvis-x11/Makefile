# $NetBSD: Makefile,v 1.10 2006/05/15 16:29:19 joerg Exp $
#

.include "../../editors/elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
PKGREVISION=	5
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

#MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
