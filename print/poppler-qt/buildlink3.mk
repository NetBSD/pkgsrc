# $NetBSD: buildlink3.mk,v 1.12 2011/03/09 13:06:49 drochner Exp $

BUILDLINK_TREE+=	poppler-qt

.if !defined(POPPLER_QT_BUILDLINK3_MK)
POPPLER_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt+=	poppler-qt>=0.4.5nb1
BUILDLINK_ABI_DEPENDS.poppler-qt?=	poppler-qt>=0.16.3
BUILDLINK_PKGSRCDIR.poppler-qt?=	../../print/poppler-qt

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt
