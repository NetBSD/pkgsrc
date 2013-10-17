# $NetBSD: options.mk,v 1.3 2013/10/17 15:32:22 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aalib
PKG_SUPPORTED_OPTIONS=	curses slang x11
PKG_SUGGESTED_OPTIONS=	curses x11
PKG_OPTIONS_LEGACY_OPTS+=	ncurses:curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses-driver=yes
.else
CONFIGURE_ARGS+=	--with-curses-driver=no
.endif

.if !empty(PKG_OPTIONS:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang-driver=yes
.else
CONFIGURE_ARGS+=	--with-slang-driver=no
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x11-driver=yes
.else
CONFIGURE_ARGS+=	--with-x11-driver=no
.endif
