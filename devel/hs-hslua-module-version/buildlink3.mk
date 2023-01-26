# $NetBSD: buildlink3.mk,v 1.4 2023/01/26 09:30:36 pho Exp $

BUILDLINK_TREE+=	hs-hslua-module-version

.if !defined(HS_HSLUA_MODULE_VERSION_BUILDLINK3_MK)
HS_HSLUA_MODULE_VERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-version+=	hs-hslua-module-version>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-hslua-module-version+=	hs-hslua-module-version>=1.0.3
BUILDLINK_PKGSRCDIR.hs-hslua-module-version?=	../../devel/hs-hslua-module-version

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_VERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-version
