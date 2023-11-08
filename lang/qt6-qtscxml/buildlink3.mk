# $NetBSD: buildlink3.mk,v 1.6 2023/11/08 13:19:52 wiz Exp $

BUILDLINK_TREE+=	qt6-qtscxml

.if !defined(QT6_QTSCXML_BUILDLINK3_MK)
QT6_QTSCXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtscxml+=	qt6-qtscxml>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtscxml?=	qt6-qtscxml>=6.6.0nb1
BUILDLINK_PKGSRCDIR.qt6-qtscxml?=	../../lang/qt6-qtscxml

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSCXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtscxml
