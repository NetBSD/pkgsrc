# $NetBSD: Makefile,v 1.31 2006/12/15 20:32:55 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	Freeciv client

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=3.0:../../games/freeciv-sounds

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
