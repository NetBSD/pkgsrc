# $NetBSD: Makefile,v 1.41 2010/02/10 19:17:38 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	2
COMMENT=	Freeciv client

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
