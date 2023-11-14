# $NetBSD: buildlink3.mk,v 1.11 2023/11/14 14:02:46 wiz Exp $

BUILDLINK_TREE+=	poppler-qt6

.if !defined(POPPLER_QT6_BUILDLINK3_MK)
POPPLER_QT6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-qt6+=	poppler-qt6>=22.01.0
BUILDLINK_ABI_DEPENDS.poppler-qt6?=	poppler-qt6>=23.06.0nb5
BUILDLINK_PKGSRCDIR.poppler-qt6?=	../../print/poppler-qt6

.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# POPPLER_QT6_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-qt6
