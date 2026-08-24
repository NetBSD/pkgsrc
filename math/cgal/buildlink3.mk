# $NetBSD: buildlink3.mk,v 1.53 2026/08/24 08:42:25 adam Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=5.1
BUILDLINK_ABI_DEPENDS.cgal+=	cgal>=5.6.2nb9
BUILDLINK_PKGSRCDIR.cgal?=	../../math/cgal

BUILDLINK_DEPMETHOD.cgal?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"

.endif	# CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
