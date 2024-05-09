# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:39 pho Exp $

BUILDLINK_TREE+=	hs-attoparsec-aeson

.if !defined(HS_ATTOPARSEC_AESON_BUILDLINK3_MK)
HS_ATTOPARSEC_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec-aeson+=	hs-attoparsec-aeson>=2.2.0
BUILDLINK_ABI_DEPENDS.hs-attoparsec-aeson+=	hs-attoparsec-aeson>=2.2.0.1nb2
BUILDLINK_PKGSRCDIR.hs-attoparsec-aeson?=	../../textproc/hs-attoparsec-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../math/hs-integer-conversion/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_ATTOPARSEC_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec-aeson
