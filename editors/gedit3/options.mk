# $NetBSD: options.mk,v 1.1 2014/12/06 20:41:36 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gedit3
PKG_SUPPORTED_OPTIONS=	enchant
PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

PLIST_VARS=		enchant

###
### Spell-check plugin which uses enchant
###
.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
PLIST.enchant=		yes
.else
CONFIGURE_ARGS+=	--disable-spell
.endif
