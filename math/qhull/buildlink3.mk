# $NetBSD: buildlink3.mk,v 1.5 2022/01/09 01:30:46 gdt Exp $

BUILDLINK_TREE+=	qhull

.if !defined(QHULL_BUILDLINK3_MK)
QHULL_BUILDLINK3_MK:=

BUILDLINK_FILES.qhull+=		bin/qconvex
BUILDLINK_FILES.qhull+=		bin/qdelaunay
BUILDLINK_FILES.qhull+=		bin/qhalf
BUILDLINK_FILES.qhull+=		bin/qhull
BUILDLINK_FILES.qhull+=		bin/qvoronoi
BUILDLINK_FILES.qhull+=		bin/rbox

BUILDLINK_API_DEPENDS.qhull+=	qhull>=2003.1
BUILDLINK_ABI_DEPENDS.qhull+=	qhull>=2020.2nb1
BUILDLINK_PKGSRCDIR.qhull?=	../../math/qhull
.endif # QHULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qhull
