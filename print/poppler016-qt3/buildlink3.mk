# $NetBSD: buildlink3.mk,v 1.1 2015/09/12 16:50:01 joerg Exp $

BUILDLINK_TREE+=	poppler016-qt3

.if !defined(POPPLER_QT_BUILDLINK3_MK)
POPPLER_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler016-qt3+=	poppler-qt>=0.4.5nb1
BUILDLINK_ABI_DEPENDS.poppler016-qt3+=	poppler-qt>=0.16.7nb9
BUILDLINK_PKGSRCDIR.poppler016-qt3?=	../../print/poppler016-qt3

.include "../../print/poppler016/buildlink3.mk"
.endif # POPPLER_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler016-qt3
