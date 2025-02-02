# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:04 pho Exp $

BUILDLINK_TREE+=	hs-enummapset

.if !defined(HS_ENUMMAPSET_BUILDLINK3_MK)
HS_ENUMMAPSET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.3
BUILDLINK_ABI_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.3.0nb1
BUILDLINK_PKGSRCDIR.hs-enummapset?=	../../devel/hs-enummapset

.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_ENUMMAPSET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-enummapset
