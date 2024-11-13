# $NetBSD: options.mk,v 1.4 2024/11/13 11:36:08 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quassel
PKG_SUPPORTED_OPTIONS=	quassel-audio quassel-webengine

.include "../../mk/bsd.options.mk"

# "Use WebEngine for showing previews of webpages linked in the chat. Requires
# the QtWebEngine module to be available, and increases the client's RAM usage
# by *a lot* if enabled at runtime."
.if !empty(PKG_OPTIONS:Mquassel-webengine)
CMAKE_CONFIGURE_ARGS+=	-DWITH_WEBENGINE=ON
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.endif

# Required for audio notifications
.if !empty(PKG_OPTIONS:Mquassel-audio)
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.endif
