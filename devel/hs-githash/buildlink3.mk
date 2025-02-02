# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:05:08 pho Exp $

BUILDLINK_TREE+=	hs-githash

.if !defined(HS_GITHASH_BUILDLINK3_MK)
HS_GITHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-githash+=	hs-githash>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-githash+=	hs-githash>=0.1.7.0nb3
BUILDLINK_PKGSRCDIR.hs-githash?=	../../devel/hs-githash

.include "../../devel/hs-th-compat/buildlink3.mk"
.endif	# HS_GITHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-githash
