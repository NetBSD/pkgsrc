# $NetBSD: options.mk,v 1.1 2015/06/08 11:16:38 wiz Exp $

PKG_OPTIONS_VAR=                PKG_OPTIONS.artha
PKG_SUPPORTED_OPTIONS=          libnotify
PKG_SUGGESTED_OPTIONS=          libnotify

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.endif
