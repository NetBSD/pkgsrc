# $NetBSD: buildlink3.mk,v 1.9 2023/10/09 04:54:09 pho Exp $

BUILDLINK_TREE+=	hs-call-stack

.if !defined(HS_CALL_STACK_BUILDLINK3_MK)
HS_CALL_STACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-call-stack+=	hs-call-stack>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-call-stack+=	hs-call-stack>=0.4.0nb4
BUILDLINK_PKGSRCDIR.hs-call-stack?=	../../devel/hs-call-stack
.endif	# HS_CALL_STACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-call-stack
