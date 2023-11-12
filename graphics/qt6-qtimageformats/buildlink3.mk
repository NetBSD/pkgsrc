# $NetBSD: buildlink3.mk,v 1.8 2023/11/12 13:22:14 wiz Exp $

BUILDLINK_TREE+=	qt6-qtimageformats

.if !defined(QT6_QTIMAGEFORMATS_BUILDLINK3_MK)
QT6_QTIMAGEFORMATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtimageformats+=	qt6-qtimageformats>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtimageformats+=	qt6-qtimageformats>=6.6.0nb2
BUILDLINK_PKGSRCDIR.qt6-qtimageformats?=	../../graphics/qt6-qtimageformats

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTIMAGEFORMATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtimageformats
