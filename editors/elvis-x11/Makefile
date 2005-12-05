# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:09 rillig Exp $
#

.include "../../editors/elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
PKGREVISION=	2
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

#MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
