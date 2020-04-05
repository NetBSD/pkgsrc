# $NetBSD: options.mk,v 1.14 2020/04/05 16:05:45 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pluma
PKG_SUPPORTED_OPTIONS=	enchant
PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menchant)
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-spell
.else
CONFIGURE_ARGS+=	--disable-spell
.endif
