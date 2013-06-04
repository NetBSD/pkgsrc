# $NetBSD: buildlink3.mk,v 1.20 2013/06/04 22:17:00 tron Exp $

BUILDLINK_TREE+=	poppler-qt

.if !defined(POPPLER_QT_BUILDLINK3_MK)
POPPLER_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt+=	poppler-qt>=0.4.5nb1
BUILDLINK_ABI_DEPENDS.poppler-qt+=	poppler-qt>=0.16.7nb6
BUILDLINK_PKGSRCDIR.poppler-qt?=	../../print/poppler-qt

.include "../../print/poppler016/buildlink3.mk"
.endif # POPPLER_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt
