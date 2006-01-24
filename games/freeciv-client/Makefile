# $NetBSD: Makefile,v 1.25 2006/01/24 07:32:08 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	Freeciv client with Xaw interface

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=3.0:../../games/freeciv-sounds

CONFLICTS=	freeciv-client-gtk<=1.11.4

CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
