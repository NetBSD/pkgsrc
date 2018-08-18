# $NetBSD: buildlink3.mk,v 1.1 2018/08/18 01:17:29 ryoon Exp $

BUILDLINK_TREE+=	fcitx-qt5

.if !defined(FCITX_QT5_BUILDLINK3_MK)
FCITX_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx-qt5+=	fcitx-qt5>=1.2.3
BUILDLINK_PKGSRCDIR.fcitx-qt5?=		../../inputmethod/fcitx-qt5

.endif	# FCITX_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx-qt5
