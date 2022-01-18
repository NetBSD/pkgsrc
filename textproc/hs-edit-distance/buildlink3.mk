# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:25 pho Exp $

BUILDLINK_TREE+=	hs-edit-distance

.if !defined(HS_EDIT_DISTANCE_BUILDLINK3_MK)
HS_EDIT_DISTANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-edit-distance+=	hs-edit-distance>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-edit-distance+=	hs-edit-distance>=0.2.2.1nb2
BUILDLINK_PKGSRCDIR.hs-edit-distance?=		../../textproc/hs-edit-distance

.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_EDIT_DISTANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-edit-distance
