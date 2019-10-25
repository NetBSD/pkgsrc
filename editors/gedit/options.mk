# $NetBSD: options.mk,v 1.6 2019/10/25 14:01:39 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gedit
PKG_SUPPORTED_OPTIONS=	enchant
PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

PLIST_VARS=		enchant

###
### Spell-check plugin which uses enchant
### (gspell is a wrapper for enchant)
###
.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell
.include "../../textproc/gspell/buildlink3.mk"
PLIST.enchant=		yes
.else
CONFIGURE_ARGS+=	--disable-spell
.endif
