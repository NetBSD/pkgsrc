# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:27 pho Exp $

BUILDLINK_TREE+=	hs-megaparsec

.if !defined(HS_MEGAPARSEC_BUILDLINK3_MK)
HS_MEGAPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-megaparsec+=	hs-megaparsec>=9.0.1
BUILDLINK_ABI_DEPENDS.hs-megaparsec+=	hs-megaparsec>=9.0.1nb2
BUILDLINK_PKGSRCDIR.hs-megaparsec?=	../../textproc/hs-megaparsec

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.endif	# HS_MEGAPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-megaparsec
