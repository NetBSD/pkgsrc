# $NetBSD: options.mk,v 1.2 2019/10/16 16:12:42 sjmulder Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nnn
PKG_SUPPORTED_OPTIONS+=	readline
PKG_SUGGESTED_OPTIONS+=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../mk/readline.buildlink3.mk"
.else
MAKE_ENV+=		O_NORL=1
.endif
