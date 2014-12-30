# $NetBSD: buildlink3.mk,v 1.1 2014/12/30 22:05:46 ryoon Exp $

BUILDLINK_TREE+=	qt4-qtkeychain

.if !defined(QT4_QTKEYCHAIN_BUILDLINK3_MK)
QT4_QTKEYCHAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-qtkeychain+=	qt4-qtkeychain>=0.1.0
BUILDLINK_PKGSRCDIR.qt4-qtkeychain?=	../../security/qt4-qtkeychain

.endif	# QT4_QTKEYCHAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-qtkeychain
