# $NetBSD: buildlink3.mk,v 1.64 2025/10/05 19:26:16 js Exp $

BUILDLINK_TREE+=	poppler-qt5

.if !defined(POPPLER_QT5_BUILDLINK3_MK)
POPPLER_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.26.0
BUILDLINK_ABI_DEPENDS.poppler-qt5+=	poppler-qt5>=25.08.0nb3
BUILDLINK_PKGSRCDIR.poppler-qt5?=	../../print/poppler-qt5

.include "../../print/poppler/buildlink3.mk"
.endif # POPPLER_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt5
