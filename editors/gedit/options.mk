# $NetBSD: options.mk,v 1.2 2009/04/17 18:40:42 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gedit
PKG_SUPPORTED_OPTIONS=	enchant
#PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

PLIST_VARS=	enchant
.if !empty(PKG_OPTIONS:Menchant)
PLIST.enchant=	yes
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-spell
.endif
