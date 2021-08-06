# $NetBSD: options.mk,v 1.5 2021/08/06 01:36:38 sjmulder Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nnn
PKG_SUPPORTED_OPTIONS+=	mouse pcre readline x11 debug
PKG_SUGGESTED_OPTIONS+=	mouse pcre readline x11

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

.if empty(PKG_OPTIONS:Mx11)
MAKE_FLAGS+=		O_NOX11=1
.endif

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_FLAGS+=		O_DEBUG=1
.endif
