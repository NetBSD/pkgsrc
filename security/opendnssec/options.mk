# $NetBSD: options.mk,v 1.2 2011/01/24 20:30:28 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm
PKG_SUGGESTED_OPTIONS=		softhsm

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
DEPENDS+=	softhsm-[0-9]*:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
