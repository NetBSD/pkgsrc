# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:09:39 wiz Exp $

BUILDLINK_TREE+=	qt6-qtlanguageserver

.if !defined(QT6_QTLANGUAGESERVER_BUILDLINK3_MK)
QT6_QTLANGUAGESERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.5.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtlanguageserver?=	../../lang/qt6-qtlanguageserver

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLANGUAGESERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlanguageserver
