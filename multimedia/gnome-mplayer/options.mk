# $NetBSD: options.mk,v 1.6 2013/10/16 10:39:05 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-mplayer
PKG_SUPPORTED_OPTIONS=	gnome musicbrainz libgpod
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	nautilus

#
# Compile the nautilus plugin
#
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nautilus
CONFIGURE_ARGS+=	--with-libnotify
PLIST.nautilus=		yes
.else
CONFIGURE_ARGS+=	--disable-nautilus
CONFIGURE_ARGS+=	--with-libnotify=no
.endif

#
# Add support for libmusicbrainz3
#
.if !empty(PKG_OPTIONS:Mmusicbrainz)
.include "../../audio/libmusicbrainz/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libmusicbrainz3
.else
CONFIGURE_ARGS+=	--with-libmusicbrainz3=no
.endif

#
# Add support for libgpod
#
.if !empty(PKG_OPTIONS:Mlibgpod)
.include "../../audio/libgpod/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgpod
.else
CONFIGURE_ARGS+=	--with-libgpod=no
.endif
