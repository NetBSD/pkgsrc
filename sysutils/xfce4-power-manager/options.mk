# $NetBSD: options.mk,v 1.1 2025/05/10 17:22:31 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-power-manager

PKG_SUPPORTED_OPTIONS+=	polkit xfce4-panel
PKG_SUGGESTED_OPTIONS=	polkit xfce4-panel

PLIST_VARS+=		polkit xfce4-panel

.include "../../mk/bsd.options.mk"

###
### Plugin support for Xfce's panel
###
.if !empty(PKG_OPTIONS:Mxfce4-panel)
.include "../../x11/xfce4-panel/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xfce4panel
PLIST.xfce4-panel=	yes
.else
CONFIGURE_ARGS+=	--disable-xfce4panel
.endif

###
### Polkit support
###
.if !empty(PKG_OPTIONS:Mpolkit)
.  include "../../security/polkit/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-polkit
PLIST.polkit=		yes
.else
CONFIGURE_ARGS+=	--disable-polkit
.endif
