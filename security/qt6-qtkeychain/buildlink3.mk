# $NetBSD: buildlink3.mk,v 1.1 2025/03/31 06:17:52 plunky Exp $

BUILDLINK_TREE+=	qt6-qtkeychain

.if !defined(QT6_QTKEYCHAIN_BUILDLINK3_MK)
QT6_QTKEYCHAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtkeychain+=	qt6-qtkeychain>=0.15.0
BUILDLINK_PKGSRCDIR.qt6-qtkeychain?=	../../security/qt6-qtkeychain

.endif	# QT6_QTKEYCHAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtkeychain
