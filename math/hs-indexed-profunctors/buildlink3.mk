# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:37 pho Exp $

BUILDLINK_TREE+=	hs-indexed-profunctors

.if !defined(HS_INDEXED_PROFUNCTORS_BUILDLINK3_MK)
HS_INDEXED_PROFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-indexed-profunctors+=	hs-indexed-profunctors>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-indexed-profunctors+=	hs-indexed-profunctors>=0.1.1.1nb3
BUILDLINK_PKGSRCDIR.hs-indexed-profunctors?=	../../math/hs-indexed-profunctors
.endif	# HS_INDEXED_PROFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-indexed-profunctors
