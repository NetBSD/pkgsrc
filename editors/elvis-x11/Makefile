# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:05 wiz Exp $
#

.include "../../editors/elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
PKGREVISION=	3
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

#MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
