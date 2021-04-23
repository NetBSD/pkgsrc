# $NetBSD: buildlink3.mk,v 1.14 2021/04/23 05:03:57 pho Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.14.1
BUILDLINK_ABI_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.14.1
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../textproc/hs-attoparsec

.include "../../math/hs-scientific/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
