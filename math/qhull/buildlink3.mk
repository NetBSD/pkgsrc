# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:58 joerg Exp $

BUILDLINK_TREE+=	qhull

.if !defined(QHULL_BUILDLINK3_MK)
QHULL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qhull+=	qhull>=2003.1
BUILDLINK_PKGSRCDIR.qhull?=	../../math/qhull
.endif # QHULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qhull
