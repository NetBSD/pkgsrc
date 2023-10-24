# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:09:31 wiz Exp $

BUILDLINK_TREE+=	qt6-qtlottie

.if !defined(QT6_QTLOTTIE_BUILDLINK3_MK)
QT6_QTLOTTIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlottie+=	qt6-qtlottie>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtlottie+=	qt6-qtlottie>=6.5.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtlottie?=	../../graphics/qt6-qtlottie

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLOTTIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlottie
