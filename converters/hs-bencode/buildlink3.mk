# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:38:56 pho Exp $

BUILDLINK_TREE+=	hs-bencode

.if !defined(HS_BENCODE_BUILDLINK3_MK)
HS_BENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-bencode+=	hs-bencode>=0.6.1.1nb4
BUILDLINK_PKGSRCDIR.hs-bencode?=	../../converters/hs-bencode

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_BENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bencode
