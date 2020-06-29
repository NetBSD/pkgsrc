# $NetBSD: options.mk,v 1.2 2020/06/29 12:10:34 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openbabel
PKG_SUPPORTED_OPTIONS=	wxwidgets
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=		wx-gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwxwidgets)
.  include "../../x11/wxGTK28/buildlink3.mk"
CMAKE_ARGS+=	-DBUILD_GUI=ON
PLIST.wx-gui=	yes
.else
CMAKE_ARGS+=	-DBUILD_GUI=OFF
.endif
