# $NetBSD: options.mk,v 1.2 2006/11/06 11:26:31 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aalib
PKG_SUPPORTED_OPTIONS=	ncurses slang x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
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
