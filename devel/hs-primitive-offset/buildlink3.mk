# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:12 pho Exp $

BUILDLINK_TREE+=	hs-primitive-offset

.if !defined(HS_PRIMITIVE_OFFSET_BUILDLINK3_MK)
HS_PRIMITIVE_OFFSET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive-offset+=	hs-primitive-offset>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-primitive-offset+=	hs-primitive-offset>=0.2.0.1nb2
BUILDLINK_PKGSRCDIR.hs-primitive-offset?=	../../devel/hs-primitive-offset

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_PRIMITIVE_OFFSET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive-offset
