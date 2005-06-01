# $NetBSD: options.mk,v 1.3 2005/06/01 14:05:54 wiz Exp $

PKG_SUPPORTED_OPTIONS=  anthy canna eb qt
PKG_SUGGESTED_OPTIONS=	anthy canna
PKG_OPTIONS_LEGACY_VARS+=	UIM_USE_ANTHY:anthy
PKG_OPTIONS_LEGACY_VARS+=	UIM_USE_CANNA:canna
PKG_OPTIONS_LEGACY_VARS+=	UIM_USE_EB:eb
PKG_OPTIONS_LEGACY_VARS+=	UIM_USE_QT:qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Manthy)
.include "../../inputmethod/anthy/buildlink3.mk"
PLIST_SRC+=		PLIST.anthy
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
PLIST_SRC+=		PLIST.canna
.endif

.if !empty(PKG_OPTIONS:Meb)
.include "../../textproc/eb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-eb
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt
# Not worked this option.  need immodule patch for Qt3
CONFIGURE_ARGS+=	--with-qt-immodule
PLIST_SRC+=		PLIST.qt
.endif

PLIST_SRC+=		PLIST.common
