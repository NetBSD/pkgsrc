# $NetBSD: buildlink3.mk,v 1.1 2026/03/04 00:19:40 tnn Exp $

BUILDLINK_TREE+=	qt6-qt-color-widgets

.if !defined(QT6_QT_COLOR_WIDGETS_BUILDLINK3_MK)
QT6_QT_COLOR_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qt-color-widgets+=	qt6-qt-color-widgets>=3.0.0
BUILDLINK_PKGSRCDIR.qt6-qt-color-widgets?=	../../graphics/qt6-qt-color-widgets

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QT_COLOR_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qt-color-widgets
