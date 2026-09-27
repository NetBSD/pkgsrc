# $NetBSD: buildlink3.mk,v 1.35 2026/09/27 11:38:28 tnn Exp $

BUILDLINK_TREE+=	qca2-qt5

.if !defined(QCA2_QT5_BUILDLINK3_MK)
QCA2_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qca2-qt5+=	qca2-qt5>=2.1.3
BUILDLINK_ABI_DEPENDS.qca2-qt5+=	qca2-qt5>=2.3.12nb1
BUILDLINK_PKGSRCDIR.qca2-qt5?=		../../security/qca2-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QCA2_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-qca2-qt5
