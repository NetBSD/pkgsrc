# $NetBSD: buildlink3.mk,v 1.39 2020/05/06 14:04:11 adam Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=4.11
BUILDLINK_ABI_DEPENDS.cgal+=	cgal>=4.14nb10
BUILDLINK_PKGSRCDIR.cgal?=	../../math/cgal

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"

.endif	# CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
