# $NetBSD: buildlink3.mk,v 1.3 2016/02/03 16:05:56 nros Exp $

BUILDLINK_TREE+=	qhull

.if !defined(QHULL_BUILDLINK3_MK)
QHULL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qhull+=	qhull>=2003.1
BUILDLINK_ABI_DEPENDS.qhull+=	qhull>=2015.1
BUILDLINK_PKGSRCDIR.qhull?=	../../math/qhull
.endif # QHULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qhull
