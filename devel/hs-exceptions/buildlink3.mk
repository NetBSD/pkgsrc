# $NetBSD: buildlink3.mk,v 1.4 2020/01/01 04:23:34 pho Exp $

BUILDLINK_TREE+=	hs-exceptions

.if !defined(HS_EXCEPTIONS_BUILDLINK3_MK)
HS_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-exceptions+=	hs-exceptions>=0.10.4
BUILDLINK_ABI_DEPENDS.hs-exceptions+=	hs-exceptions>=0.10.4
BUILDLINK_PKGSRCDIR.hs-exceptions?=	../../devel/hs-exceptions

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.endif	# HS_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-exceptions
