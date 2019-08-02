# $NetBSD: options.mk,v 1.2 2019/08/02 08:37:43 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quassel
PKG_SUPPORTED_OPTIONS=	quassel-audio quassel-webkit

.include "../../mk/bsd.options.mk"

# "Support showing previews for URLs in chat (legacy)"
# Really just shows a small, difficult to read thumbnail on hover.
# Using WebEngine for this seems to be preferred.
.if !empty(PKG_OPTIONS:Mquassel-webkit)
CMAKE_ARGS+=	-DWITH_WEBKIT=ON
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif

# Required for audio notifications
.if !empty(PKG_OPTIONS:Mquassel-audio)
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.endif
