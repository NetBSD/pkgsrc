# $NetBSD: options.mk,v 1.2 2010/12/16 11:52:15 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
PLIST_SRC+=	PLIST.x11
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXtst/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
