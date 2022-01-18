# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:09 pho Exp $

BUILDLINK_TREE+=	hs-hslua-module-system

.if !defined(HS_HSLUA_MODULE_SYSTEM_BUILDLINK3_MK)
HS_HSLUA_MODULE_SYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-system+=	hs-hslua-module-system>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-hslua-module-system+=	hs-hslua-module-system>=0.2.2.1nb2
BUILDLINK_PKGSRCDIR.hs-hslua-module-system?=	../../devel/hs-hslua-module-system

.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_SYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-system
