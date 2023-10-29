# $NetBSD: buildlink3.mk,v 1.4 2023/10/29 18:44:44 pho Exp $

BUILDLINK_TREE+=	hs-attoparsec-iso8601

.if !defined(HS_ATTOPARSEC_ISO8601_BUILDLINK3_MK)
HS_ATTOPARSEC_ISO8601_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec-iso8601+=	hs-attoparsec-iso8601>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-attoparsec-iso8601+=	hs-attoparsec-iso8601>=1.1.0.1
BUILDLINK_PKGSRCDIR.hs-attoparsec-iso8601?=	../../textproc/hs-attoparsec-iso8601

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../math/hs-integer-conversion/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.endif	# HS_ATTOPARSEC_ISO8601_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec-iso8601
