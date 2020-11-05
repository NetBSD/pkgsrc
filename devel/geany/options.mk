# $NetBSD: options.mk,v 1.4 2020/11/05 01:04:52 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geany
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk3

PLIST_VARS+=	gtk2 gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
# No CONFIGURE_ARGS needed, it's the default
PLIST.gtk3=		yes
.else
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk2
PLIST.gtk2=		yes
.endif
