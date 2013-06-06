# $NetBSD: buildlink3.mk,v 1.16 2013/06/06 12:53:43 wiz Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=3.9
BUILDLINK_ABI_DEPENDS.cgal+=	cgal>=3.9nb17
BUILDLINK_PKGSRCDIR.cgal?=	../../math/cgal

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.endif	# CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
