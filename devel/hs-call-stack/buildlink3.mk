# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:05 pho Exp $

BUILDLINK_TREE+=	hs-call-stack

.if !defined(HS_CALL_STACK_BUILDLINK3_MK)
HS_CALL_STACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-call-stack+=	hs-call-stack>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-call-stack+=	hs-call-stack>=0.3.0nb2
BUILDLINK_PKGSRCDIR.hs-call-stack?=	../../devel/hs-call-stack
.endif	# HS_CALL_STACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-call-stack
