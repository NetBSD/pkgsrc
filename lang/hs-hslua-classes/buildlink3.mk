# $NetBSD: buildlink3.mk,v 1.4 2023/01/25 17:40:05 pho Exp $

BUILDLINK_TREE+=	hs-hslua-classes

.if !defined(HS_HSLUA_CLASSES_BUILDLINK3_MK)
HS_HSLUA_CLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.2.0
BUILDLINK_ABI_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.2.0
BUILDLINK_PKGSRCDIR.hs-hslua-classes?=		../../lang/hs-hslua-classes

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.endif	# HS_HSLUA_CLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-classes
