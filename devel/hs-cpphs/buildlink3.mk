# $NetBSD: buildlink3.mk,v 1.18 2023/02/07 01:40:31 pho Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9.1nb5
BUILDLINK_PKGSRCDIR.hs-cpphs?=		../../devel/hs-cpphs

.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
