# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:37:08 pho Exp $

BUILDLINK_TREE+=	hs-hslua-objectorientation

.if !defined(HS_HSLUA_OBJECTORIENTATION_BUILDLINK3_MK)
HS_HSLUA_OBJECTORIENTATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-objectorientation+=	hs-hslua-objectorientation>=2.3.0
BUILDLINK_ABI_DEPENDS.hs-hslua-objectorientation+=	hs-hslua-objectorientation>=2.3.0nb1
BUILDLINK_PKGSRCDIR.hs-hslua-objectorientation?=	../../lang/hs-hslua-objectorientation

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-typing/buildlink3.mk"
.endif	# HS_HSLUA_OBJECTORIENTATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-objectorientation
