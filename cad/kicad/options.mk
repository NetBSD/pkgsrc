# $NetBSD: options.mk,v 1.1 2023/06/06 10:20:58 bouyer Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kicad
PKG_SUPPORTED_OPTIONS=	ng-spice 
PKG_SUGGESTED_OPTIONS=	ng-spice 

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mng-spice)
.  include "../../cad/ng-spice-shared/buildlink3.mk"
CMAKE_ARGS+=		-DKICAD_SPICE=ON
.else
CMAKE_ARGS+=		-DKICAD_SPICE=OFF
.endif
