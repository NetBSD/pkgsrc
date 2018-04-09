# $NetBSD: options.mk,v 1.1 2018/04/09 20:17:46 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.highlight
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
BUILD_TARGET+=		gui
INSTALL_TARGET+=	install-gui
PLIST.x11=		yes
.endif
