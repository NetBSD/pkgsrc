# $NetBSD: buildlink3.mk,v 1.5 2023/01/03 17:36:26 wiz Exp $

BUILDLINK_TREE+=	nvidia-texture-tools

.if !defined(NVIDIA_TEXTURE_TOOLS_BUILDLINK3_MK)
NVIDIA_TEXTURE_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nvidia-texture-tools+=	nvidia-texture-tools>=2.0.8
BUILDLINK_ABI_DEPENDS.nvidia-texture-tools?=	nvidia-texture-tools>=2.1.0nb4
BUILDLINK_PKGSRCDIR.nvidia-texture-tools?=	../../graphics/nvidia-texture-tools

.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# NVIDIA_TEXTURE_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nvidia-texture-tools
