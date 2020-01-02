# $NetBSD: buildlink3.mk,v 1.13 2020/01/02 14:49:43 pho Exp $

BUILDLINK_TREE+=	hs-parsec

.if !defined(HS_PARSEC_BUILDLINK3_MK)
HS_PARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parsec+=	hs-parsec>=3.1.14
BUILDLINK_ABI_DEPENDS.hs-parsec+=	hs-parsec>=3.1.14.0
BUILDLINK_PKGSRCDIR.hs-parsec?=		../../textproc/hs-parsec

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_PARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parsec
