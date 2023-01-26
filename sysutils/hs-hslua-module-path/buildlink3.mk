# $NetBSD: buildlink3.mk,v 1.7 2023/01/26 09:16:51 pho Exp $

BUILDLINK_TREE+=	hs-hslua-module-path

.if !defined(HS_HSLUA_MODULE_PATH_BUILDLINK3_MK)
HS_HSLUA_MODULE_PATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-path+=	hs-hslua-module-path>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-hslua-module-path+=	hs-hslua-module-path>=1.0.3
BUILDLINK_PKGSRCDIR.hs-hslua-module-path?=	../../sysutils/hs-hslua-module-path

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_PATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-path
