# $NetBSD: options.mk,v 1.3 2009/05/16 04:18:13 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libstatgrab
PKG_SUPPORTED_OPTIONS=	saidar statgrab
PKG_SUGGESTED_OPTIONS=	saidar statgrab
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
.  include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-saidar
.endif
