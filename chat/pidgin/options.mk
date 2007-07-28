# $NetBSD: options.mk,v 1.1.1.1 2007/07/28 12:12:33 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		gtkspell gstreamer debug
PKG_SUGGESTED_OPTIONS+=		gtkspell

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkspell)
.  include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.  include "../../multimedia/gstreamer0.10/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-gstreamer
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= --enable-debug
.else
CONFIGURE_ARGS+= --disable-debug
.endif

