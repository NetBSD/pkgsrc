# $NetBSD: buildlink3.mk,v 1.7 2023/10/29 07:13:50 pho Exp $

BUILDLINK_TREE+=	hs-hslua-classes

.if !defined(HS_HSLUA_CLASSES_BUILDLINK3_MK)
HS_HSLUA_CLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.3.0
BUILDLINK_ABI_DEPENDS.hs-hslua-classes+=	hs-hslua-classes>=2.3.0
BUILDLINK_PKGSRCDIR.hs-hslua-classes?=		../../lang/hs-hslua-classes

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.endif	# HS_HSLUA_CLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-classes
