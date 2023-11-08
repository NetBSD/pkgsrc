# $NetBSD: buildlink3.mk,v 1.7 2023/11/08 13:20:50 wiz Exp $

BUILDLINK_TREE+=	qt6-qtnetworkauth

.if !defined(QT6_QTNETWORKAUTH_BUILDLINK3_MK)
QT6_QTNETWORKAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtnetworkauth+=	qt6-qtnetworkauth>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtnetworkauth+=	qt6-qtnetworkauth>=6.6.0nb1
BUILDLINK_PKGSRCDIR.qt6-qtnetworkauth?=		../../security/qt6-qtnetworkauth

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTNETWORKAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtnetworkauth
