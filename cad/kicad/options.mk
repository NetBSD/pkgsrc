# $NetBSD: options.mk,v 1.3 2024/11/20 01:29:49 mef Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kicad
PKG_SUPPORTED_OPTIONS=	ng-spice
PKG_SUGGESTED_OPTIONS=	ng-spice

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mng-spice)
.  include "../../cad/ng-spice-shared/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DKICAD_SPICE=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DKICAD_SPICE=OFF
.endif
