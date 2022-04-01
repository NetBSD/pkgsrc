# $NetBSD: options.mk,v 1.2 2022/04/01 08:07:28 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		softhsm2
PKG_SUGGESTED_OPTIONS=		softhsm2

.include "../../mk/bsd.options.mk"

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm2)
.include "../../security/softhsm2/buildlink3.mk"
.endif
