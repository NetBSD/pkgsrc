# $NetBSD: buildlink3.mk,v 1.2 2025/07/28 09:15:00 dkazankov Exp $

BUILDLINK_TREE+=	gpr2-tools

.if !defined(GPR2TOOLS_BUILDLINK3_MK)
GPR2TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpr2-tools+=	gpr2-tools>=25.0.0
BUILDLINK_PKGSRCDIR.gpr2-tools?=	../../devel/gpr2-tools
BUILDLINK_DEPMETHOD.gpr2-tools?=	build

.endif

BUILDLINK_TREE+=	-gpr2-tools
