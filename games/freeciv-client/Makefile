# $NetBSD: Makefile,v 1.23 2005/08/24 10:45:32 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	Freeciv client with Xaw interface

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=3.0:../../games/freeciv-sounds

CONFLICTS=	freeciv-client-gtk<=1.11.4

CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

.include "../freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
