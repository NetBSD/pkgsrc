# $NetBSD: buildlink3.mk,v 1.35 2020/03/04 22:07:24 wiz Exp $

BUILDLINK_TREE+=	poppler-qt5

.if !defined(POPPLER_QT5_BUILDLINK3_MK)
POPPLER_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.26.0
BUILDLINK_ABI_DEPENDS.poppler-qt5+=	poppler-qt5>=0.86.1
BUILDLINK_PKGSRCDIR.poppler-qt5?=	../../print/poppler-qt5

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt5
