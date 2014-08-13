# $NetBSD: buildlink3.mk,v 1.20 2014/08/13 10:57:32 adam Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=3.9
BUILDLINK_ABI_DEPENDS.cgal+=	cgal>=3.9nb22
BUILDLINK_PKGSRCDIR.cgal?=	../../math/cgal

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.endif	# CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
