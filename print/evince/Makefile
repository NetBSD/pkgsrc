# $NetBSD: Makefile,v 1.23 2006/09/15 15:22:16 jmmv Exp $
#

.include "../../print/evince/Makefile.common"

COMMENT=		Document viewer for the GNOME Desktop

GCONF2_SCHEMAS=		evince.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dvi djvu
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

.if !empty(PKG_OPTIONS:Mdjvu)
CONFIGURE_ARGS+=	--enable-djvu
PLIST_SUBST+=		DJVU=	#empty
GCONF2_SCHEMAS+=	evince-thumbnailer-djvu.schemas
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.else
PLIST_SUBST+=		DJVU="@comment "
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
