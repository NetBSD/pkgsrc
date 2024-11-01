# $NetBSD: buildlink3.mk,v 1.3 2024/11/01 12:54:19 wiz Exp $

BUILDLINK_TREE+=	qca2-qt6

.if !defined(QCA2_QT6_BUILDLINK3_MK)
QCA2_QT6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qca2-qt6+=	qca2-qt6>=2.3.8
BUILDLINK_ABI_DEPENDS.qca2-qt6?=		qca2-qt6>=2.3.8nb3
BUILDLINK_PKGSRCDIR.qca2-qt6?=		../../security/qca2-qt6

.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QCA2_QT6_BUILDLINK3_MK

BUILDLINK_TREE+=	-qca2-qt6
