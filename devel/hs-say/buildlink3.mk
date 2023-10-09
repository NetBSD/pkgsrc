# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:28 pho Exp $

BUILDLINK_TREE+=	hs-say

.if !defined(HS_SAY_BUILDLINK3_MK)
HS_SAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-say+=	hs-say>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-say+=	hs-say>=0.1.0.1nb3
BUILDLINK_PKGSRCDIR.hs-say?=	../../devel/hs-say
.endif	# HS_SAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-say
