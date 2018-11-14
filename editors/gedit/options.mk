# $NetBSD: options.mk,v 1.3 2018/11/14 21:17:22 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gedit
PKG_SUPPORTED_OPTIONS=	enchant
#PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

PLIST_VARS=	enchant
.if !empty(PKG_OPTIONS:Menchant)
PLIST.enchant=	yes
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-spell
.endif
