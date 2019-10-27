# $NetBSD: buildlink3.mk,v 1.1 2019/10/27 18:20:00 bouyer Exp $

BUILDLINK_TREE+=	qt5-qtkeychain

.if !defined(QT5_QTKEYCHAIN_BUILDLINK3_MK)
QT5_QTKEYCHAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtkeychain+=	qt5-qtkeychain>=0.1.0
BUILDLINK_PKGSRCDIR.qt5-qtkeychain?=	../../security/qt5-qtkeychain

.endif	# QT5_QTKEYCHAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtkeychain
