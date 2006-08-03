# $NetBSD: Makefile,v 1.20 2006/08/03 19:25:52 drochner Exp $
#

.include "../../print/evince/Makefile.common"

COMMENT=		Document viewer for the GNOME Desktop

GCONF2_SCHEMAS=		evince.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdvi)
CONFIGURE_ARGS+=	--enable-dvi
PLIST_SUBST+=		DVI=	# empty
GCONF2_SCHEMAS+=	evince-thumbnailer-dvi.schemas
.include "../../mk/tex.buildlink3.mk"
.else
PLIST_SUBST+=		DVI="@comment "
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
