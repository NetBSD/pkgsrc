# $NetBSD: buildlink3.mk,v 1.14 2023/11/02 06:37:20 pho Exp $

BUILDLINK_TREE+=	hs-digest

.if !defined(HS_DIGEST_BUILDLINK3_MK)
HS_DIGEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-digest+=	hs-digest>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-digest+=	hs-digest>=0.0.1.7nb1
BUILDLINK_PKGSRCDIR.hs-digest?=		../../security/hs-digest

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_DIGEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-digest
