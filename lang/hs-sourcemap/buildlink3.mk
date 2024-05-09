# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:23 pho Exp $

BUILDLINK_TREE+=	hs-sourcemap

.if !defined(HS_SOURCEMAP_BUILDLINK3_MK)
HS_SOURCEMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-sourcemap+=	hs-sourcemap>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-sourcemap+=	hs-sourcemap>=0.1.7nb6
BUILDLINK_PKGSRCDIR.hs-sourcemap?=	../../lang/hs-sourcemap

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_SOURCEMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-sourcemap
