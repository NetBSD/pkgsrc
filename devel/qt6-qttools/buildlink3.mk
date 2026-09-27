# $NetBSD: buildlink3.mk,v 1.24 2026/09/27 11:35:48 tnn Exp $

BUILDLINK_TREE+=	qt6-qttools

.if !defined(QT6_QTTOOLS_BUILDLINK3_MK)
QT6_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qttools+=	qt6-qttools>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qttools+=	qt6-qttools>=6.11.2nb2
BUILDLINK_PKGSRCDIR.qt6-qttools?=	../../devel/qt6-qttools

BUILDLINK_FILES.qt6-qttools+=		qt6/bin/lconvert
BUILDLINK_FILES.qt6-qttools+=		qt6/bin/lrelease
BUILDLINK_FILES.qt6-qttools+=		qt6/bin/lupdate
BUILDLINK_FILES.qt6-qttools+=		qt6/libexec/lprodump
BUILDLINK_FILES.qt6-qttools+=		qt6/libexec/lrelease-pro
BUILDLINK_FILES.qt6-qttools+=		qt6/libexec/lupdate-pro

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qttools
