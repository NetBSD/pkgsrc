# $NetBSD: buildlink3.mk,v 1.5 2022/02/11 12:11:55 pho Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=2.1.0
BUILDLINK_ABI_DEPENDS.hs-hslua+=	hs-hslua>=2.1.0
BUILDLINK_PKGSRCDIR.hs-hslua?=		../../lang/hs-hslua

.include "../../lang/hs-hslua-classes/buildlink3.mk"
.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-objectorientation/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
