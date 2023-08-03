# $NetBSD: buildlink3.mk,v 1.5 2023/08/03 20:01:30 adam Exp $

BUILDLINK_TREE+=	qt6-qtlanguageserver

.if !defined(QT6_QTLANGUAGESERVER_BUILDLINK3_MK)
QT6_QTLANGUAGESERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.5.2
BUILDLINK_PKGSRCDIR.qt6-qtlanguageserver?=	../../lang/qt6-qtlanguageserver

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLANGUAGESERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlanguageserver
