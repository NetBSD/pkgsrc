# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:40:57 pho Exp $

BUILDLINK_TREE+=	hs-hslua-classes

.if !defined(HS_HSLUA_CLASSES_BUILDLINK3_MK)
HS_HSLUA_CLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.2.0
BUILDLINK_ABI_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.2.0nb1
BUILDLINK_PKGSRCDIR.hs-hslua-classes?=		../../lang/hs-hslua-classes

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.endif	# HS_HSLUA_CLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-classes
