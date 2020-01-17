# $NetBSD: options.mk,v 1.7 2020/01/17 14:16:26 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-mplayer
PKG_SUPPORTED_OPTIONS=	libnotify musicbrainz libgpod
PKG_SUGGESTED_OPTIONS=	libnotify

PKG_OPTIONS_LEGACY_OPTS+=	gnome:libnotify

.include "../../mk/bsd.options.mk"

#
# Add support for libnotify
#
.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libnotify
.else
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
