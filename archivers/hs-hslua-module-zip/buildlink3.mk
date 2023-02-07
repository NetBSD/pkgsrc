# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:40:22 pho Exp $

BUILDLINK_TREE+=	hs-hslua-module-zip

.if !defined(HS_HSLUA_MODULE_ZIP_BUILDLINK3_MK)
HS_HSLUA_MODULE_ZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-zip+=	hs-hslua-module-zip>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-hslua-module-zip+=	hs-hslua-module-zip>=1.0.0nb1
BUILDLINK_PKGSRCDIR.hs-hslua-module-zip?=	../../archivers/hs-hslua-module-zip

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_ZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-zip
