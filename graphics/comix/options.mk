# $NetBSD: options.mk,v 1.2 2019/11/02 22:37:54 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.comix
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/GConf/buildlink3.mk"
.endif
