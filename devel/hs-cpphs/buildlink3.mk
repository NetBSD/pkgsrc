# $NetBSD: buildlink3.mk,v 1.12 2020/01/02 03:27:12 pho Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.8
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.20.8
BUILDLINK_PKGSRCDIR.hs-cpphs?=		../../devel/hs-cpphs

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
