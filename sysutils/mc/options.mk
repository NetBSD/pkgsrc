# $NetBSD: options.mk,v 1.15 2019/11/04 21:28:48 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mc
PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	ncurses slang
PKG_SUPPORTED_OPTIONS=		mc-charset x11
PKG_SUGGESTED_OPTIONS=		mc-charset slang

.include "../../mk/bsd.options.mk"

### The charset option enables input/display support for various 8-bit
### codepages, chooseable at runtime.
.if !empty(PKG_OPTIONS:Mmc-charset)
CONFIGURE_ARGS+=	--enable-charset
PLIST_SRC+=		${PKGDIR}/PLIST.charset
.include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

### X11 support allows better key handling (detection of the Alt, Ctrl,
### Shift modifiers) and mouse support.
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=		--with-x
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif

### The Midnight Commander can use three different screen libraries to
### draw itself on the screen. SLang, ncurses, and a slim variant of
### SLang (the default), which is distributed with the Midnight Commander.
.if !empty(PKG_OPTIONS:Mslang)
CONFIGURE_ARGS+=	--with-screen=slang
.include "../../devel/libslang2/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		yes
CONFIGURE_ARGS+=	--with-screen=ncurses
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-screen=mcslang
.endif
