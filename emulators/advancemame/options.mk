# $NetBSD: options.mk,v 1.1 2023/07/03 21:49:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.advancemame

PKG_SUPPORTED_OPTIONS+=		freetype curses slang alsa
PKG_SUGGESTED_OPTIONS+=		freetype curses
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-freetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if !empty(PKG_OPTIONS:Mcurses)
FAKE_NCURSES=		yes
CONFIGURE_ARGS+=	--enable-ncurses
.include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ncurses
.endif

.if !empty(PKG_OPTIONS:Mslang)
CONFIGURE_ARGS+=	--enable-slang
.include "../../devel/libslang/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-slang
.endif
