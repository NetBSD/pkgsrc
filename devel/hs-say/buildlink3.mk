# $NetBSD: buildlink3.mk,v 1.1 2022/02/24 01:16:25 pho Exp $

BUILDLINK_TREE+=	hs-say

.if !defined(HS_SAY_BUILDLINK3_MK)
HS_SAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-say+=	hs-say>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-say+=	hs-say>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-say?=	../../devel/hs-say
.endif	# HS_SAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-say
