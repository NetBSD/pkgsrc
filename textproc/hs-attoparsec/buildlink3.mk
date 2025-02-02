# $NetBSD: buildlink3.mk,v 1.24 2025/02/02 13:05:49 pho Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.14.4
BUILDLINK_ABI_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.14.4nb7
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../textproc/hs-attoparsec

.include "../../math/hs-scientific/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
