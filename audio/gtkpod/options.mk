# $NetBSD: options.mk,v 1.4 2017/04/17 08:45:52 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtkpod
PKG_SUPPORTED_OPTIONS=		libmp4v2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibmp4v2)
.  include "../../multimedia/libmp4v2/buildlink3.mk"
.endif
