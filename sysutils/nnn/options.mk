# $NetBSD: options.mk,v 1.4 2020/04/29 09:29:38 sjmulder Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nnn
PKG_SUPPORTED_OPTIONS+=	mouse pcre readline debug
PKG_SUGGESTED_OPTIONS+=	mouse pcre readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmouse)
USE_CURSES+=		getmouse
.else
MAKE_FLAGS+=		O_NOMOUSE=1
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
MAKE_FLAGS+=		O_PCRE=1
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../mk/readline.buildlink3.mk"
.else
MAKE_FLAGS+=		O_NORL=1
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_FLAGS+=		O_DEBUG=1
.endif
