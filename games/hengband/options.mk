# $NetBSD: options.mk,v 1.1 2020/01/24 13:33:32 pho Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hengband
PKG_SUPPORTED_OPTIONS=		lang-ja
PKG_OPTIONS_NONEMPTY_SETS=	ui
PKG_OPTIONS_SET.ui=		ncurses curses termcap x11
PKG_SUGGESTED_OPTIONS=		ncurses x11

.include "../../mk/bsd.options.mk"

###
### Language (English or Japanese)
###
.if empty(PKG_OPTIONS:Mlang-ja)
CONFIGURE_ARGS+=	--disable-japanese
.endif

###
### TTY support
###
.if !empty(PKG_OPTIONS:Mncurses)
.include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtermcap)
.include "../../mk/termcap.buildlink3.mk"
.endif

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif
