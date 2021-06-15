# $NetBSD: buildlink3.mk,v 1.4 2021/06/15 04:07:20 thor Exp $

BUILDLINK_TREE+=	qhull

.if !defined(QHULL_BUILDLINK3_MK)
QHULL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qhull+=	qhull>=2003.1
BUILDLINK_ABI_DEPENDS.qhull+=	qhull>=2020.2nb1
BUILDLINK_PKGSRCDIR.qhull?=	../../math/qhull
.endif # QHULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qhull
