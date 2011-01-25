# $NetBSD: options.mk,v 1.4 2011/01/25 11:02:35 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gwaei
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
PLIST_SRC+=		PLIST.gnome

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.22.0
.include "../../devel/libgnome/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsexy+=		libsexy>=0.1.11
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.else
CONFIGURE_ARGS+=	--without-gnome
.endif
