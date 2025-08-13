# $NetBSD: buildlink3.mk,v 1.12 2025/08/13 11:06:42 pho Exp $

BUILDLINK_TREE+=	hs-githash

.if !defined(HS_GITHASH_BUILDLINK3_MK)
HS_GITHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-githash+=	hs-githash>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-githash+=	hs-githash>=0.1.7.0nb5
BUILDLINK_PKGSRCDIR.hs-githash?=	../../devel/hs-githash

.include "../../devel/hs-th-compat/buildlink3.mk"
.endif	# HS_GITHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-githash
