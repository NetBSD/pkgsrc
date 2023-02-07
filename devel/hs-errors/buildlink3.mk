# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:40:33 pho Exp $

BUILDLINK_TREE+=	hs-errors

.if !defined(HS_ERRORS_BUILDLINK3_MK)
HS_ERRORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-errors+=	hs-errors>=2.3.0
BUILDLINK_ABI_DEPENDS.hs-errors+=	hs-errors>=2.3.0nb5
BUILDLINK_PKGSRCDIR.hs-errors?=		../../devel/hs-errors

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_ERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-errors
