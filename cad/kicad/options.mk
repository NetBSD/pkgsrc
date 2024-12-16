# $NetBSD: options.mk,v 1.5 2024/12/16 07:44:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kicad
PKG_SUPPORTED_OPTIONS=	ng-spice wayland
PKG_SUGGESTED_OPTIONS=	ng-spice wayland

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mng-spice)
.  include "../../cad/ng-spice-shared/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DKICAD_SPICE=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DKICAD_SPICE=OFF
.endif

.if !empty(PKG_OPTIONS:Mwayland)
.  include "../../devel/wayland/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=   -DKICAD_WAYLAND=ON
# This conditional matches the conditional in Makefile
# so that it's effectively a test for whether
# KICAD_USE_EGL is enabled.
.  if empty(MESALIB_SUPPORTS_EGL:Myes)
PKG_FAIL_REASON+= "Kicad requires the KICAD_USE_EGL CMake option when using the "
PKG_FAIL_REASON+= "KICAD_WAYLAND CMake option. See the cmake_dependent_option() "
PKG_FAIL_REASON+= "for KICAD_WAYLAND in CMakeLists.txt."
.  endif
.else
CMAKE_CONFIGURE_ARGS+=   -DKICAD_WAYLAND=OFF
.endif
