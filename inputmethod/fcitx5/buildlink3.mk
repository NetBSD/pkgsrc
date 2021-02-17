# $NetBSD: buildlink3.mk,v 1.1 2021/02/17 15:16:25 ryoon Exp $

BUILDLINK_TREE+=	fcitx5

.if !defined(FCITX5_BUILDLINK3_MK)
FCITX5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx5+=	fcitx5>=5.0.1
BUILDLINK_PKGSRCDIR.fcitx5?=	../../inputmethod/fcitx5

.endif	# FCITX5_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5
