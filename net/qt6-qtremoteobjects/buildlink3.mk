# $NetBSD: buildlink3.mk,v 1.24 2026/11/07 19:11:55 wiz Exp $

BUILDLINK_TREE+=	qt6-qtremoteobjects

.if !defined(QT6_QTREMOTEOBJECTS_BUILDLINK3_MK)
QT6_QTREMOTEOBJECTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtremoteobjects+=	qt6-qtremoteobjects>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtremoteobjects+=	qt6-qtremoteobjects>=6.11.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtremoteobjects?=	../../net/qt6-qtremoteobjects

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTREMOTEOBJECTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtremoteobjects
