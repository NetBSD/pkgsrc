# $NetBSD: buildlink3.mk,v 1.10 2015/08/02 11:27:05 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parsec

.if !defined(HS_PARSEC_BUILDLINK3_MK)
HS_PARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parsec+=	hs-parsec>=3.1.9
BUILDLINK_ABI_DEPENDS.hs-parsec+=	hs-parsec>=3.1.9nb1
BUILDLINK_PKGSRCDIR.hs-parsec?=	../../textproc/hs-parsec

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_PARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parsec
