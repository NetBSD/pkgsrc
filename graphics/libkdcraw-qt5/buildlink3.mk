# $NetBSD: buildlink3.mk,v 1.1 2025/12/21 12:40:11 markd Exp $

BUILDLINK_TREE+=	libkdcraw-qt5

.if !defined(LIBKDCRAW_QT5_BUILDLINK3_MK)
LIBKDCRAW_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw-qt5+=	libkdcraw-qt5>=25.08.2
BUILDLINK_PKGSRCDIR.libkdcraw-qt5?=	../../graphics/libkdcraw-qt5

#.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw-qt5
