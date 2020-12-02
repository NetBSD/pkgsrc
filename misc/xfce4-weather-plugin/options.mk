# $NetBSD: options.mk,v 1.1 2020/12/02 00:46:31 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-weather-plugin
PKG_SUPPORTED_OPTIONS=	upower
PKG_SUGGESTED_OPTIONS=	upower

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mupower)
.include "../../sysutils/upower/buildlink3.mk"
.endif
