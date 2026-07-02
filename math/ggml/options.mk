# $NetBSD: options.mk,v 1.1 2026/07/02 10:58:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ggml
PKG_SUPPORTED_OPTIONS=	vulkan
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		vulkan
PRINT_PLIST_AWK+=	/libggml-vulkan/ { $$0 = "$${PLIST.vulkan}" $$0 }

.if !empty(PKG_OPTIONS:Mvulkan)
DEPENDS+=		shaderc-[0-9]*:../../graphics/shaderc
CMAKE_CONFIGURE_ARGS+=	-DGGML_VULKAN=ON
PLIST.vulkan=		yes
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../graphics/vulkan-loader/buildlink3.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DGGML_VULKAN=OFF
.endif
