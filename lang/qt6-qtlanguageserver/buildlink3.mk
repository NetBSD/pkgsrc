# $NetBSD: buildlink3.mk,v 1.15 2025/04/24 14:14:55 wiz Exp $

BUILDLINK_TREE+=	qt6-qtlanguageserver

.if !defined(QT6_QTLANGUAGESERVER_BUILDLINK3_MK)
QT6_QTLANGUAGESERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.8.3nb2
BUILDLINK_PKGSRCDIR.qt6-qtlanguageserver?=	../../lang/qt6-qtlanguageserver

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLANGUAGESERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlanguageserver
