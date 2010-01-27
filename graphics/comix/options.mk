# $NetBSD: options.mk,v 1.1 2010/01/27 10:24:08 wiz Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.comix
PKG_SUPPORTED_OPTIONS= gnome
PKG_SUGGESTED_OPTIONS= gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/GConf/buildlink3.mk"
.endif
