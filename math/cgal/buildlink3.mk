# $NetBSD: buildlink3.mk,v 1.49 2025/01/11 03:23:02 mef Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=5.1
BUILDLINK_ABI_DEPENDS.cgal+=	cgal>=5.1
BUILDLINK_PKGSRCDIR.cgal?=	../../math/cgal

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"

.endif	# CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
