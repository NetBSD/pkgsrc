# $NetBSD: options.mk,v 1.24 2022/11/26 09:55:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glib2
PKG_SUPPORTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	cocoa
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	cocoa nococoa

# if this options is enabled, use quartz for gtk{2,3}
.if !empty(PKG_OPTIONS:Mcocoa)
MESON_ARGS+=	-Duse_cocoa=true
# Broken as of 2.74.1: gio/tests/giotypefuncs.inc:168:9:
# error: implicit declaration of function 'g_osx_app_info_get_type'
MESON_ARGS+=	-Dtests=false
PLIST.cocoa=	yes
.else
PLIST.nococoa=	yes
.endif
