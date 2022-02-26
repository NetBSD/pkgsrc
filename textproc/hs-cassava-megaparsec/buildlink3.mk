# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:25 pho Exp $

BUILDLINK_TREE+=	hs-cassava-megaparsec

.if !defined(HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK)
HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.0.4
BUILDLINK_ABI_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.0.4nb2
BUILDLINK_PKGSRCDIR.hs-cassava-megaparsec?=	../../textproc/hs-cassava-megaparsec

.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cassava-megaparsec
