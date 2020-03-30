# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:49:55 riastradh Exp $

BUILDLINK_TREE+=	hs-cassava-megaparsec

.if !defined(HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK)
HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.0.1
BUILDLINK_ABI_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.0.1
BUILDLINK_PKGSRCDIR.hs-cassava-megaparsec?=	../../textproc/hs-cassava-megaparsec
.endif	# HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cassava-megaparsec
