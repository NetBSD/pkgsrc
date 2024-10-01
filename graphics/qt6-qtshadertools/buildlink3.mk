# $NetBSD: buildlink3.mk,v 1.10 2024/10/01 05:54:22 adam Exp $

BUILDLINK_TREE+=	qt6-qtshadertools

.if !defined(QT6_QTSHADERTOOLS_BUILDLINK3_MK)
QT6_QTSHADERTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtshadertools+=	qt6-qtshadertools>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtshadertools+=	qt6-qtshadertools>=6.6.3nb1
BUILDLINK_PKGSRCDIR.qt6-qtshadertools?=		../../graphics/qt6-qtshadertools

BUILDLINK_FILES.qt6-qtshadertools+=	bin/qsb

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSHADERTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtshadertools
