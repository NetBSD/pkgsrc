# $NetBSD: buildlink3.mk,v 1.16 2013/01/26 21:36:44 adam Exp $

BUILDLINK_TREE+=	poppler-qt

.if !defined(POPPLER_QT_BUILDLINK3_MK)
POPPLER_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt+=	poppler-qt>=0.4.5nb1
BUILDLINK_ABI_DEPENDS.poppler-qt+=	poppler-qt>=0.16.7nb2
BUILDLINK_PKGSRCDIR.poppler-qt?=	../../print/poppler-qt

.include "../../print/poppler016/buildlink3.mk"
.endif # POPPLER_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt
