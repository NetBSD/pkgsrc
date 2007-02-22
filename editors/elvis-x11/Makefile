# $NetBSD: Makefile,v 1.12 2007/02/22 19:26:25 wiz Exp $
#

.include "../../editors/elvis/Makefile.common"

PKGNAME=	elvis-x11-2.2.0
PKGREVISION=	5
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

#MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
