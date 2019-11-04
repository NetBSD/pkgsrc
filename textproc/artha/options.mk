# $NetBSD: options.mk,v 1.2 2019/11/04 21:43:33 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.artha
PKG_SUPPORTED_OPTIONS=		libnotify
PKG_SUGGESTED_OPTIONS=		libnotify

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.endif
