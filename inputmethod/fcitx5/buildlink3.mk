# $NetBSD: buildlink3.mk,v 1.3 2024/02/15 18:21:34 nia Exp $

BUILDLINK_TREE+=	fcitx5

.if !defined(FCITX5_BUILDLINK3_MK)
FCITX5_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	charconv

BUILDLINK_API_DEPENDS.fcitx5+=	fcitx5>=5.0.1
BUILDLINK_PKGSRCDIR.fcitx5?=	../../inputmethod/fcitx5

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed
.endif	# FCITX5_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5
