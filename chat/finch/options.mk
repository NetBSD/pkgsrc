# $NetBSD: options.mk,v 1.3 2008/05/18 00:06:46 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.finch
PKG_SUPPORTED_OPTIONS+=		gstreamer debug
PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.  include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
