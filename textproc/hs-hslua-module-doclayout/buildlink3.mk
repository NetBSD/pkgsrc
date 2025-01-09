# $NetBSD: buildlink3.mk,v 1.10 2025/01/09 23:47:29 wiz Exp $

BUILDLINK_TREE+=	hs-hslua-module-doclayout

.if !defined(HS_HSLUA_MODULE_DOCLAYOUT_BUILDLINK3_MK)
HS_HSLUA_MODULE_DOCLAYOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-module-doclayout+=	hs-hslua-module-doclayout>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-hslua-module-doclayout+=	hs-hslua-module-doclayout>=1.2.0
BUILDLINK_PKGSRCDIR.hs-hslua-module-doclayout?=		../../textproc/hs-hslua-module-doclayout

.include "../../textproc/hs-doclayout/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.endif	# HS_HSLUA_MODULE_DOCLAYOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-module-doclayout
