# $NetBSD: options.mk,v 1.8 2023/09/04 20:52:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-mplayer
PKG_SUPPORTED_OPTIONS=	libnotify libgpod
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
# Add support for libgpod
#
.if !empty(PKG_OPTIONS:Mlibgpod)
.include "../../audio/libgpod/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgpod
.else
CONFIGURE_ARGS+=	--with-libgpod=no
.endif
