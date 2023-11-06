# $NetBSD: options.mk,v 1.1 2023/11/06 17:15:57 pho Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.chezscheme
PKG_SUPPORTED_OPTIONS=	x11 curses iconv ffi
PKG_SUGGESTED_OPTIONS=	x11 curses iconv ffi

.include "../../mk/bsd.options.mk"

###
### X11 support
###
.if ${PKG_OPTIONS:Mx11}
.  include "../../x11/libX11/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

###
### Curses support
###
.if ${PKG_OPTIONS:Mcurses}
.  include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-curses
.endif

###
### iconv support
###
.if ${PKG_OPTIONS:Miconv}
.  include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

###
### libffi support
###
.if ${PKG_OPTIONS:Mffi}
.  include "../../devel/libffi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libffi
.endif
