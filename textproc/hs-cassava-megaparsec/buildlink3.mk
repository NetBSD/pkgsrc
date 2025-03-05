# $NetBSD: buildlink3.mk,v 1.16 2025/03/05 03:39:56 pho Exp $

BUILDLINK_TREE+=	hs-cassava-megaparsec

.if !defined(HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK)
HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.1.1
BUILDLINK_ABI_DEPENDS.hs-cassava-megaparsec+=	hs-cassava-megaparsec>=2.1.1nb2
BUILDLINK_PKGSRCDIR.hs-cassava-megaparsec?=	../../textproc/hs-cassava-megaparsec

.include "../../textproc/hs-cassava/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CASSAVA_MEGAPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cassava-megaparsec
