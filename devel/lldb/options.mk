# $NetBSD: options.mk,v 1.1 2023/10/06 19:16:28 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lldb

PKG_SUPPORTED_OPTIONS+=	tests curses
PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=ON
.else
# py-lit, py-psutil, lld
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
.endif

.if ${PKG_OPTIONS:Mcurses}
.include "../../mk/curses.buildlink3.mk"

.  if ${OPSYS} == "NetBSD"
.    if exists(/usr/include/panel.h)
CMAKE_ARGS+=	-DLLDB_ENABLE_CURSES=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=ON
.    else
.include "../../devel/ncurses/buildlink3.mk"
.      if exists(${BUILDLINK_PREFIX.ncurses}/include/ncurses/panel.h)
CMAKE_ARGS+=    -DLLDB_ENABLE_CURSES=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=ON
.      else
CMAKE_ARGS+=    -DLLDB_ENABLE_CURSES=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.      endif
.    endif
.  else
.include "../../devel/ncurses/buildlink3.mk"
.    if exists(${BUILDLINK_PREFIX.ncurses}/include/ncurses/panel.h)
CMAKE_ARGS+=    -DLLDB_ENABLE_CURSES=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=ON
.    else
CMAKE_ARGS+=    -DLLDB_ENABLE_CURSES=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.    endif
.  endif

.else

CMAKE_ARGS+=	-DLLDB_ENABLE_CURSES=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.endif
