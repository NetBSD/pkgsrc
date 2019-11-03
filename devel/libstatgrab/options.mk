# $NetBSD: options.mk,v 1.5 2019/11/03 10:39:18 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libstatgrab
PKG_SUPPORTED_OPTIONS=		saidar statgrab
PKG_SUGGESTED_OPTIONS=		saidar statgrab
PKG_OPTIONS_LEGACY_VARS+=	WITHOUT_SAIDAR:-saidar
PKG_OPTIONS_LEGACY_VARS+=	WITHOUT_STATGRAB:-statgrab

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		saidar statgrab

.if !empty(PKG_OPTIONS:Mstatgrab)
PLIST.statgrab=		yes
.else
CONFIGURE_ARGS+=	--disable-statgrab
.endif

.if !empty(PKG_OPTIONS:Msaidar)
PLIST.saidar=		yes
.  include "../../mk/curses.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-saidar
.endif
