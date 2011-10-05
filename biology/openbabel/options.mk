# $NetBSD: options.mk,v 1.1.1.1 2011/10/05 22:15:49 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openbabel
PKG_SUPPORTED_OPTIONS=	wx-gui
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=		wx-gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwx-gui)
.  include "../../x11/wxGTK28/buildlink3.mk"
CMAKE_ARGS+=	-DBUILD_GUI=ON
PLIST.wx-gui=	yes
.else
CMAKE_ARGS+=	-DBUILD_GUI=OFF
.endif
