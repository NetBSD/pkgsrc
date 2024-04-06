# $NetBSD: buildlink3.mk,v 1.9 2024/04/06 08:05:53 wiz Exp $

BUILDLINK_TREE+=	qt6-qtquicktimeline

.if !defined(QT6_QTQUICKTIMELINE_BUILDLINK3_MK)
QT6_QTQUICKTIMELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtquicktimeline+=	qt6-qtquicktimeline>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtquicktimeline+=	qt6-qtquicktimeline>=6.6.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtquicktimeline?=	../../graphics/qt6-qtquicktimeline

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTQUICKTIMELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtquicktimeline
