# $NetBSD: buildlink3.mk,v 1.17 2022/02/26 03:57:51 pho Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9.1nb4
BUILDLINK_PKGSRCDIR.hs-cpphs?=		../../devel/hs-cpphs

.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
