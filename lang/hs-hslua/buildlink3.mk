# $NetBSD: buildlink3.mk,v 1.8 2023/01/26 18:08:11 pho Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=2.2.1
BUILDLINK_ABI_DEPENDS.hs-hslua+=	hs-hslua>=2.2.1
BUILDLINK_PKGSRCDIR.hs-hslua?=		../../lang/hs-hslua

.include "../../converters/hs-hslua-aeson/buildlink3.mk"
.include "../../lang/hs-hslua-classes/buildlink3.mk"
.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-objectorientation/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
