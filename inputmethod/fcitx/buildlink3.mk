# $NetBSD: buildlink3.mk,v 1.2 2024/02/15 18:19:45 nia Exp $

BUILDLINK_TREE+=	fcitx

.if !defined(FCITX_BUILDLINK3_MK)
FCITX_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	charconv

BUILDLINK_API_DEPENDS.fcitx+=	fcitx>=4.2.9.6
BUILDLINK_PKGSRCDIR.fcitx?=	../../inputmethod/fcitx

.endif	# FCITX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx
