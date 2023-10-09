# $NetBSD: buildlink3.mk,v 1.3 2023/10/09 04:54:13 pho Exp $

BUILDLINK_TREE+=	hs-enummapset

.if !defined(HS_ENUMMAPSET_BUILDLINK3_MK)
HS_ENUMMAPSET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.1
BUILDLINK_ABI_DEPENDS.hs-enummapset+=	hs-enummapset>=0.7.1.0nb2
BUILDLINK_PKGSRCDIR.hs-enummapset?=	../../devel/hs-enummapset

.include "../../converters/hs-aeson/buildlink3.mk"
.endif	# HS_ENUMMAPSET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-enummapset
