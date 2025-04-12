# $NetBSD: options.mk,v 1.1 2025/04/12 18:37:15 jmcneill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.direwolf
PKG_SUPPORTED_OPTIONS=		gpsd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpsd)
.include "../../geography/gpsd/buildlink3.mk"
.endif
