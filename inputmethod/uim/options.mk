# $NetBSD: options.mk,v 1.1 2005/03/29 18:47:52 wiz Exp $

# Global and legacy options
.if defined(UIM_USE_ANTHY) && !empty(UIM_USE_ANTHY:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=   anthy
.endif

.if defined(UIM_USE_CANNA) && !empty(UIM_USE_CANNA:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=   canna
.endif

.if defined(UIM_USE_EB) && !empty(UIM_USE_EB:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=   eb
.endif

.if defined(UIM_USE_QT) && !empty(UIM_USE_QT:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=   qt
.endif

PKG_OPTIONS_VAR=        PKG_OPTIONS.uim
PKG_SUPPORTED_OPTIONS=  anthy canna eb qt
PKG_DEFAULT_OPTIONS+=	anthy canna

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
