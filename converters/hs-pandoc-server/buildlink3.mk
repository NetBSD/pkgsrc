# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:13 pho Exp $

BUILDLINK_TREE+=	hs-pandoc-server

.if !defined(HS_PANDOC_SERVER_BUILDLINK3_MK)
HS_PANDOC_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-server+=	hs-pandoc-server>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-pandoc-server+=	hs-pandoc-server>=0.1.0.3nb1
BUILDLINK_PKGSRCDIR.hs-pandoc-server?=		../../converters/hs-pandoc-server

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-base64/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-doctemplates/buildlink3.mk"
.include "../../converters/hs-pandoc-base/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../www/hs-servant-server/buildlink3.mk"
.include "../../textproc/hs-skylighting/buildlink3.mk"
.include "../../textproc/hs-unicode-collation/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-cors/buildlink3.mk"
.endif	# HS_PANDOC_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-server
