# $NetBSD: Makefile,v 1.134 2018/04/16 14:33:54 wiz Exp $

.include "../../print/evince/Makefile.common"
PKGREVISION=	65

COMMENT=		Document viewer

.include "options.mk"

CONFIGURE_ARGS+=	--enable-comics
CONFIGURE_ARGS+=	--disable-nautilus

USE_TOOLS+=	gsed

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
