# $NetBSD: options.mk,v 1.2 2010/01/22 20:44:58 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dasher
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS=		gnome

###
### Gnome support
###
.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--with-gnome
PLIST.gnome=		yes
.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.else
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--disable-a11y
CONFIGURE_ARGS+=	--disable-nls
.endif # gnome
