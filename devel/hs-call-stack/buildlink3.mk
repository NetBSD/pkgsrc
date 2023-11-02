# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:36:22 pho Exp $

BUILDLINK_TREE+=	hs-call-stack

.if !defined(HS_CALL_STACK_BUILDLINK3_MK)
HS_CALL_STACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-call-stack+=	hs-call-stack>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-call-stack+=	hs-call-stack>=0.4.0nb5
BUILDLINK_PKGSRCDIR.hs-call-stack?=	../../devel/hs-call-stack
.endif	# HS_CALL_STACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-call-stack
