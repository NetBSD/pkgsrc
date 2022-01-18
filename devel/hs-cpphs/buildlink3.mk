# $NetBSD: buildlink3.mk,v 1.15 2022/01/18 02:48:06 pho Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.9.1nb2
BUILDLINK_PKGSRCDIR.hs-cpphs?=		../../devel/hs-cpphs

.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
