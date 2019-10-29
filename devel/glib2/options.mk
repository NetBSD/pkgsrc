# $NetBSD: options.mk,v 1.22 2019/10/29 09:22:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glib2
PKG_SUPPORTED_OPTIONS=	fam

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	cocoa
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	cocoa nococoa

# if this options is enabled, use quartz for gtk{2,3}
.if !empty(PKG_OPTIONS:Mcocoa)
MESON_ARGS+=	-Duse_cocoa=true
PLIST.cocoa=	yes
.else
PLIST.nococoa=	yes
.endif

PLIST_VARS+=	fam
.if !empty(PKG_OPTIONS:Mfam)
MESON_ARGS+=	-Dfam=true
PLIST.fam=	yes
.include "../../mk/fam.buildlink3.mk"
.endif
