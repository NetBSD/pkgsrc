# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:31:40 pho Exp $

BUILDLINK_TREE+=	hs-bencode

.if !defined(HS_BENCODE_BUILDLINK3_MK)
HS_BENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1.1nb2
BUILDLINK_PKGSRCDIR.hs-bencode?=	../../converters/hs-bencode

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_BENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bencode
