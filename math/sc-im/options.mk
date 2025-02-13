# $NetBSD: options.mk,v 1.5 2025/02/13 16:43:50 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sc-im
PKG_SUPPORTED_OPTIONS+=	color xls xlsx lua threads x11
PKG_SUGGESTED_OPTIONS+=	color xls xlsx lua

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.if ${USE_BUILTIN.pthread:tl} == yes
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcolor)
CFLAGS+=	-DUSECOLORS
.endif

.if !empty(PKG_OPTIONS:Mxls)
CFLAGS+=	-DXLS
LDLIBS+=	-lxlsreader
.include "../../textproc/libxls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxlsx)
CFLAGS+=	-DXLSX -DXLSX_EXPORT
LDLIBS+=	-lxlsxwriter -lcrypto -lminizip
.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxlsxwriter/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlua)
MAKE_ENV+=   LUA_PKGNAME=${LUA_PACKAGE:S/lua/lua-/:S/5/5./}
.include "../../lang/lua/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=      yes
PTHREAD_OPTS+=          require
CFLAGS+=		-DHAVE_PTHREAD
.endif

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	xclip-[0-9]*:../../x11/xclip
CFLAGS+=	-DDEFAULT_COPY_TO_CLIPBOARD_CMD=\""xclip -i -selection clipboard <"\"
CFLAGS+=	-DDEFAULT_PASTE_FROM_CLIPBOARD_CMD=\""xclip -o -selection clipboard"\"
.else
CFLAGS+=	-DDEFAULT_COPY_TO_CLIPBOARD_CMD=\""tmux load-buffer"\"
CFLAGS+=	-DDEFAULT_PASTE_FROM_CLIPBOARD_CMD=\""tmux show-buffer"\"
.endif
