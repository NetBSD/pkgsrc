# $NetBSD: options.mk,v 1.3 2024/08/25 06:18:39 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nvi2
PKG_SUPPORTED_OPTIONS=	iconv wide-curses
PKG_SUGGESTED_OPTIONS=	iconv wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miconv)
.  include "../../converters/libiconv/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DUSE_ICONV=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_ICONV=OFF
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../mk/curses.buildlink3.mk"
.  if ${CURSES_TYPE} != "ncurses" # XXX: Why is this necessary!?
CMAKE_CONFIGURE_ARGS+=	-DUSE_WIDECHAR=ON
.  else
CMAKE_CONFIGURE_ARGS+=	-DUSE_WIDECHAR=OFF
.  endif
.else
.  include "../../mk/curses.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DUSE_WIDECHAR=OFF
.endif
