# $NetBSD: buildlink3.mk,v 1.7 2015/01/17 14:05:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.18.7
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.18.7
BUILDLINK_PKGSRCDIR.hs-cpphs?=	../../devel/hs-cpphs

.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
