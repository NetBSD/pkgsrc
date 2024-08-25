# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lldb

PKG_SUPPORTED_OPTIONS+=	tests curses
PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_TESTS=ON
.else
# py-lit, py-psutil, lld
CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
.endif

.if ${PKG_OPTIONS:Mcurses}
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DLLDB_ENABLE_CURSES=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_TERMINFO=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DLLDB_ENABLE_CURSES=OFF
CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.endif
