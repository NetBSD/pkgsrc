# $NetBSD: buildlink3.mk,v 1.3 2024/02/15 18:20:15 nia Exp $

BUILDLINK_TREE+=	fcitx

.if !defined(FCITX_BUILDLINK3_MK)
FCITX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx+=	fcitx>=4.2.9.6
BUILDLINK_PKGSRCDIR.fcitx?=	../../inputmethod/fcitx

.endif	# FCITX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx
