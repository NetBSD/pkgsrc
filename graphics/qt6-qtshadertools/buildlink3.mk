# $NetBSD: buildlink3.mk,v 1.2 2023/01/29 21:14:45 ryoon Exp $

BUILDLINK_TREE+=	qt6-qtshadertools

.if !defined(QT6_QTSHADERTOOLS_BUILDLINK3_MK)
QT6_QTSHADERTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtshadertools+=	qt6-qtshadertools>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtshadertools?=		qt6-qtshadertools>=6.4.1nb1
BUILDLINK_PKGSRCDIR.qt6-qtshadertools?=		../../graphics/qt6-qtshadertools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSHADERTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtshadertools
