# $NetBSD: buildlink3.mk,v 1.14 2024/12/26 22:20:19 adam Exp $

BUILDLINK_TREE+=	qt6-qttools

.if !defined(QT6_QTTOOLS_BUILDLINK3_MK)
QT6_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qttools+=	qt6-qttools>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qttools+=	qt6-qttools>=6.8.1
BUILDLINK_PKGSRCDIR.qt6-qttools?=	../../devel/qt6-qttools

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qttools
