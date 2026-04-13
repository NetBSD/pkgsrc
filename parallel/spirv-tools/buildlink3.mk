# $NetBSD: buildlink3.mk,v 1.4 2026/04/13 13:22:21 kikadf Exp $

BUILDLINK_TREE+=	spirv-tools

.if !defined(SPIRV_TOOLS_BUILDLINK3_MK)
SPIRV_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spirv-tools+=	spirv-tools>=1.4.341.0
BUILDLINK_PKGSRCDIR.spirv-tools?=	../../parallel/spirv-tools
BUILDLINK_FILES.spirv-tools+=					\
					bin/spirv-as		\
					bin/spirv-cfg		\
					bin/spirv-diff		\
					bin/spirv-dis		\
					bin/spirv-link		\
					bin/spirv-lint		\
					bin/spirv-objdump	\
					bin/spirv-opt		\
					bin/spirv-reduce	\
					bin/spirv-val

.endif	# SPIRV_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-tools
