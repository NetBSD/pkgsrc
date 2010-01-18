# $NetBSD: buildlink3.mk,v 1.4 2010/01/18 09:59:23 wiz Exp $

BUILDLINK_TREE+=	poppler-qt4

.if !defined(POPPLER_QT4_BUILDLINK3_MK)
POPPLER_QT4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt4+=	poppler-qt4>=0.6.1
BUILDLINK_ABI_DEPENDS.poppler-qt4?=	poppler-qt4>=0.12.3nb1
BUILDLINK_PKGSRCDIR.poppler-qt4?=	../../print/poppler-qt4

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt4
