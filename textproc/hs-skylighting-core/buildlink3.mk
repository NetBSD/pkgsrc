# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:28 pho Exp $

BUILDLINK_TREE+=	hs-skylighting-core

.if !defined(HS_SKYLIGHTING_CORE_BUILDLINK3_MK)
HS_SKYLIGHTING_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skylighting-core+=	hs-skylighting-core>=0.10.5
BUILDLINK_ABI_DEPENDS.hs-skylighting-core+=	hs-skylighting-core>=0.10.5.1nb2
BUILDLINK_PKGSRCDIR.hs-skylighting-core?=	../../textproc/hs-skylighting-core

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.endif	# HS_SKYLIGHTING_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skylighting-core
