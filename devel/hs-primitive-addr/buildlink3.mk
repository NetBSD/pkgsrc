# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:00:43 pho Exp $

BUILDLINK_TREE+=	hs-primitive-addr

.if !defined(HS_PRIMITIVE_ADDR_BUILDLINK3_MK)
HS_PRIMITIVE_ADDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive-addr+=	hs-primitive-addr>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-primitive-addr+=	hs-primitive-addr>=0.1.0.3
BUILDLINK_PKGSRCDIR.hs-primitive-addr?=		../../devel/hs-primitive-addr

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_PRIMITIVE_ADDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive-addr
