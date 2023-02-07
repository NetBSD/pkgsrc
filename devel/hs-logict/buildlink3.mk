# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:42 pho Exp $

BUILDLINK_TREE+=	hs-logict

.if !defined(HS_LOGICT_BUILDLINK3_MK)
HS_LOGICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-logict+=	hs-logict>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-logict+=	hs-logict>=0.8.0.0nb1
BUILDLINK_PKGSRCDIR.hs-logict?=		../../devel/hs-logict
.endif	# HS_LOGICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-logict
