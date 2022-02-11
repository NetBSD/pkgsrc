# $NetBSD: buildlink3.mk,v 1.7 2022/02/11 13:03:04 pho Exp $

BUILDLINK_TREE+=	hs-digest

.if !defined(HS_DIGEST_BUILDLINK3_MK)
HS_DIGEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-digest+=	hs-digest>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-digest+=	hs-digest>=0.0.1.3
BUILDLINK_PKGSRCDIR.hs-digest?=		../../security/hs-digest

.include "../../devel/zlib/buildlink3.mk"
.endif	# HS_DIGEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-digest
