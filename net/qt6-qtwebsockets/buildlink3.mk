# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:10:32 wiz Exp $

BUILDLINK_TREE+=	qt6-qtwebsockets

.if !defined(QT6_QTWEBSOCKETS_BUILDLINK3_MK)
QT6_QTWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebsockets+=	qt6-qtwebsockets>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtwebsockets+=	qt6-qtwebsockets>=6.5.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtwebsockets?=		../../net/qt6-qtwebsockets

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebsockets
