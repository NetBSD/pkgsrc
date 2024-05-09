# $NetBSD: buildlink3.mk,v 1.17 2024/05/09 01:32:46 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-core

.if !defined(HS_SKYLIGHTING_CORE_BUILDLINK3_MK)
HS_SKYLIGHTING_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-core+=	hs-skylighting-core>=0.14.1
BUILDLINK_ABI_DEPENDS.hs-skylighting-core+=	hs-skylighting-core>=0.14.1.1nb1
BUILDLINK_PKGSRCDIR.hs-skylighting-core?=	../../textproc/hs-skylighting-core

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.endif	# HS_SKYLIGHTING_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-core
