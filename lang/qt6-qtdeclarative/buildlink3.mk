# $NetBSD: buildlink3.mk,v 1.2 2023/01/29 21:14:47 ryoon Exp $

BUILDLINK_TREE+=	qt6-qtdeclarative

.if !defined(QT6_QTDECLARATIVE_BUILDLINK3_MK)
QT6_QTDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtdeclarative+=	qt6-qtdeclarative>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtdeclarative?=		qt6-qtdeclarative>=6.4.1nb1
BUILDLINK_PKGSRCDIR.qt6-qtdeclarative?=		../../lang/qt6-qtdeclarative

BUILDLINK_INCDIRS.qt6-qtdeclarative+=	qt6/include
BUILDLINK_LIBDIRS.qt6-qtdeclarative+=	qt6/lib
BUILDLINK_LIBDIRS.qt6-qtdeclarative+=	qt6/plugins

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtdeclarative
