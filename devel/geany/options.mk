# $NetBSD: options.mk,v 1.1 2019/02/06 01:49:32 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geany
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk2

PLIST_VARS+=	gtk2 gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk3
PLIST.gtk3=		yes
.else
.include "../../x11/gtk2/buildlink3.mk"
# No CONFIGURE_ARGS needed, it's the default
PLIST.gtk2=		yes
.endif
