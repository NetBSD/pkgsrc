# $NetBSD: buildlink3.mk,v 1.1 2025/07/28 09:07:49 dkazankov Exp $

BUILDLINK_TREE+=	gpr2-tools

.if !defined(GPR2TOOLS_BUILDLINK3_MK)
GPR2TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpr2-tools+=	gpr2-tools>=24.0.0
BUILDLINK_PKGSRCDIR.gpr2-tools?=	../../wip/gpr2-tools
BUILDLINK_DEPMETHOD.gpr2-tools?=	build

.endif

BUILDLINK_TREE+=	-gpr2-tools
