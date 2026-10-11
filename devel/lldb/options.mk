# $NetBSD: options.mk,v 1.5 2026/10/11 05:28:13 adam Exp $

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
.else
CMAKE_CONFIGURE_ARGS+=	-DLLDB_ENABLE_CURSES=OFF
.endif
