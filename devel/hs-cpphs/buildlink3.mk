# $NetBSD: buildlink3.mk,v 1.10 2016/01/10 11:49:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.19.2
BUILDLINK_ABI_DEPENDS.hs-cpphs+=	hs-cpphs>=1.19.2nb1
BUILDLINK_PKGSRCDIR.hs-cpphs?=	../../devel/hs-cpphs

.include "../../textproc/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
