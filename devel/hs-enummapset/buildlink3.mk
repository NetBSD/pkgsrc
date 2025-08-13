# $NetBSD: buildlink3.mk,v 1.10 2025/08/13 11:06:38 pho Exp $

BUILDLINK_TREE+=	hs-enummapset

.if !defined(HS_ENUMMAPSET_BUILDLINK3_MK)
HS_ENUMMAPSET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.3
BUILDLINK_ABI_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.3.0nb3
BUILDLINK_PKGSRCDIR.hs-enummapset?=	../../devel/hs-enummapset

.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_ENUMMAPSET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-enummapset
