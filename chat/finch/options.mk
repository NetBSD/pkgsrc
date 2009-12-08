# $NetBSD: options.mk,v 1.4 2009/12/08 12:45:42 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.finch
PKG_SUPPORTED_OPTIONS+=		gstreamer debug
PKG_SUGGESTED_OPTIONS+=		gstreamer

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.  include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
