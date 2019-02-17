# $NetBSD: options.mk,v 1.1 2019/02/17 10:17:46 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quassel
PKG_SUPPORTED_OPTIONS=	quassel-webkit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# "Support showing previews for URLs in chat (legacy)"
# Really just shows a small, difficult to read thumbnail on hover.
# Using WebEngine for this seems to be preferred.
.if !empty(PKG_OPTIONS:Mquassel-webkit)
CMAKE_ARGS+=	-DWITH_WEBKIT=ON
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.endif
