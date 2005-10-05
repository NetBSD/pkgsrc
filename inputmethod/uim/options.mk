# $NetBSD: options.mk,v 1.8 2005/10/05 13:29:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uim
PKG_SUPPORTED_OPTIONS=	anthy canna eb gtk qt
PKG_SUGGESTED_OPTIONS=	anthy canna gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Manthy)
.include "../../inputmethod/anthy/buildlink3.mk"
PLIST_SRC+=		PLIST.anthy
.else
CONFIGURE_ARGS+=	--without-anthy
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

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/modules.mk"
PLIST_SRC+=		PLIST.gtk
.else
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--with-qt
# Not worked this option.  need immodule patch for Qt3
CONFIGURE_ARGS+=	--with-qt-immodule
PLIST_SRC+=		PLIST.qt
.endif

PLIST_SRC+=		PLIST.common
