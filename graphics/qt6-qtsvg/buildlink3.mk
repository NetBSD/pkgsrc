# $NetBSD: buildlink3.mk,v 1.7 2023/11/08 13:19:39 wiz Exp $

BUILDLINK_TREE+=	qt6-qtsvg

.if !defined(QT6_QTSVG_BUILDLINK3_MK)
QT6_QTSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtsvg+=	qt6-qtsvg>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtsvg+=	qt6-qtsvg>=6.6.0nb1
BUILDLINK_PKGSRCDIR.qt6-qtsvg?=		../../graphics/qt6-qtsvg

BUILDLINK_INCDIRS.qt6-qtsvg+=	qt6/include
BUILDLINK_LIBDIRS.qt6-qtsvg+=	qt6/lib
BUILDLINK_LIBDIRS.qt6-qtsvg+=	qt6/plugins

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtsvg
