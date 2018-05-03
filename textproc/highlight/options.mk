# $NetBSD: options.mk,v 1.2 2018/05/03 13:13:50 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.highlight
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/qt5-qttools/buildlink3.mk"
BUILD_TARGET+=		gui
INSTALL_TARGET+=	install-gui
PLIST.x11=		yes
.endif
