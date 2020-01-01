# $NetBSD: buildlink3.mk,v 1.3 2020/01/01 05:24:54 pho Exp $

BUILDLINK_TREE+=	hs-temporary

.if !defined(HS_TEMPORARY_BUILDLINK3_MK)
HS_TEMPORARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-temporary+=	hs-temporary>=1.3
BUILDLINK_ABI_DEPENDS.hs-temporary+=	hs-temporary>=1.3
BUILDLINK_PKGSRCDIR.hs-temporary?=	../../sysutils/hs-temporary

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_TEMPORARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-temporary
