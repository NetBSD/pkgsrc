# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:11 pho Exp $

BUILDLINK_TREE+=	hs-bencode

.if !defined(HS_BENCODE_BUILDLINK3_MK)
HS_BENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1.1nb1
BUILDLINK_PKGSRCDIR.hs-bencode?=	../../converters/hs-bencode

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_BENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bencode
