# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:05:13 pho Exp $

BUILDLINK_TREE+=	hs-logict

.if !defined(HS_LOGICT_BUILDLINK3_MK)
HS_LOGICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-logict+=	hs-logict>=0.8.2
BUILDLINK_ABI_DEPENDS.hs-logict+=	hs-logict>=0.8.2.0nb1
BUILDLINK_PKGSRCDIR.hs-logict?=		../../devel/hs-logict
.endif	# HS_LOGICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-logict
