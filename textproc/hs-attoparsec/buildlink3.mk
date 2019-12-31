# $NetBSD: buildlink3.mk,v 1.11 2019/12/31 17:33:18 pho Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.13.2
BUILDLINK_ABI_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.13.2.3
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../textproc/hs-attoparsec

.include "../../devel/hs-fail/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
