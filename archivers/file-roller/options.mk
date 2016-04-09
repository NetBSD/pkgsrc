# $NetBSD: options.mk,v 1.1 2016/04/09 05:40:46 richard Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.file-roller
PKG_SUPPORTED_OPTIONS=	nautilus
PKG_SUGGESTED_OPTIONS=	nautilus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nautilus

.if !empty(PKG_OPTIONS:Mnautilus)
PLIST.nautilus=		yes
CONFIGURE_ARGS+=	--enable-nautilus-actions
.include "../../sysutils/nautilus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nautilus-actions
.endif
