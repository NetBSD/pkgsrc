# $NetBSD: options.mk,v 1.5 2026/05/27 17:20:12 kikadf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quassel
PKG_SUPPORTED_OPTIONS=	quassel-audio quassel-webengine wayland

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

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

.if !empty(PKG_OPTIONS:Mwayland)
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.endif
