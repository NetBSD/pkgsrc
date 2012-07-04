# $NetBSD: buildlink3.mk,v 1.11 2012/07/04 20:26:58 drochner Exp $

BUILDLINK_TREE+=	poppler-qt4

.if !defined(POPPLER_QT4_BUILDLINK3_MK)
POPPLER_QT4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt4+=	poppler-qt4>=0.6.1
BUILDLINK_ABI_DEPENDS.poppler-qt4+=	poppler-qt4>=0.20.1
BUILDLINK_PKGSRCDIR.poppler-qt4?=	../../print/poppler-qt4

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt4
