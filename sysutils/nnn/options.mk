# $NetBSD: options.mk,v 1.1 2019/03/19 22:43:18 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nnn
PKG_SUPPORTED_OPTIONS+=	readline
PKG_SUGGESTED_OPTIONS+=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
BUILD_TARGET=		all
.include "../../mk/readline.buildlink3.mk"
.endif
