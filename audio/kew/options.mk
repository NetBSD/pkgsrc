# $NetBSD: options.mk,v 1.1 2024/10/09 14:25:45 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kew
PKG_SUPPORTED_OPTIONS=	libnotify
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include the libnotify library
###
.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.endif
