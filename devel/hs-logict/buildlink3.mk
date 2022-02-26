# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:00 pho Exp $

BUILDLINK_TREE+=	hs-logict

.if !defined(HS_LOGICT_BUILDLINK3_MK)
HS_LOGICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-logict+=	hs-logict>=0.7.1
BUILDLINK_ABI_DEPENDS.hs-logict+=	hs-logict>=0.7.1.0nb1
BUILDLINK_PKGSRCDIR.hs-logict?=		../../devel/hs-logict
.endif	# HS_LOGICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-logict
