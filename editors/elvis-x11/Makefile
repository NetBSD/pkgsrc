# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:38 tv Exp $
#

.include "../elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
PKGREVISION=	2
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

#MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
