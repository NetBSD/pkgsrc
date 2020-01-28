# $NetBSD: options.mk,v 1.3 2020/01/28 14:31:19 sjmulder Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nnn
PKG_SUPPORTED_OPTIONS+=	readline debug
PKG_SUGGESTED_OPTIONS+=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../mk/readline.buildlink3.mk"
.else
MAKE_FLAGS+=		O_NORL=1
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_FLAGS+=		O_DEBUG=1
.endif
