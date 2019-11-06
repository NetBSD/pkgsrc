# $NetBSD: options.mk,v 1.1 2019/11/06 13:44:38 he Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm2
PKG_SUGGESTED_OPTIONS=		softhsm2

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm2)
DEPENDS+=	softhsm2-[0-9]*:../../security/softhsm2
.include "../../security/softhsm2/buildlink3.mk"
.endif
