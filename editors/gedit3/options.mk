# $NetBSD: options.mk,v 1.2 2016/04/12 16:12:55 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gedit3
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
