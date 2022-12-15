# $NetBSD: buildlink3.mk,v 1.2 2022/12/15 10:37:46 jperkin Exp $

BUILDLINK_TREE+=	fcitx5

.if !defined(FCITX5_BUILDLINK3_MK)
FCITX5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx5+=	fcitx5>=5.0.1
BUILDLINK_PKGSRCDIR.fcitx5?=	../../inputmethod/fcitx5

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
.endif	# FCITX5_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5
