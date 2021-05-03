# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:01:11 pho Exp $

BUILDLINK_TREE+=	hs-hslua-module-path

.if !defined(HS_HSLUA_MODULE_PATH_BUILDLINK3_MK)
HS_HSLUA_MODULE_PATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-path+=	hs-hslua-module-path>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-hslua-module-path+=	hs-hslua-module-path>=0.1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-hslua-module-path?=	../../sysutils/hs-hslua-module-path

.include "../../lang/hs-hslua/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_PATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-path
