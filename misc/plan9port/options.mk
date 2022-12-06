# $NetBSD: options.mk,v 1.1 2022/12/06 14:29:25 vins Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.plan9port
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11
PLIST_VARS+=		x11

.include "../../mk/bsd.options.mk"

# Build rio and related X11 tools.
.if !empty(PKG_OPTIONS:Mx11)

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

PLIST.x11=		yes
.endif
