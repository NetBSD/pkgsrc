# $NetBSD: options.mk,v 1.2 2023/03/02 22:47:33 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet-gtk
PKG_SUPPORTED_OPTIONS+=		audio
PKG_SUGGESTED_OPTIONS+=		audio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maudio)
.  if ${PKG_BUILD_OPTIONS.gnunet:Maudio}
PLIST_VARS+=			audio
PLIST.audio=			yes
.  endif
.endif
