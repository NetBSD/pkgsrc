# $NetBSD: options.mk,v 1.4 2021/07/14 07:39:05 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	gui

.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mgui)
PLIST_SRC+=		PLIST.gui
CONFIGURE_ARGS+=	--enable-gui
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui
.endif
