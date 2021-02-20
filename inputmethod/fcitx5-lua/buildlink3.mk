# $NetBSD: buildlink3.mk,v 1.1 2021/02/20 21:36:59 ryoon Exp $

BUILDLINK_TREE+=	fcitx5-lua

.if !defined(FCITX5_LUA_BUILDLINK3_MK)
FCITX5_LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx5-lua+=	fcitx5-lua>=5.0.2
BUILDLINK_PKGSRCDIR.fcitx5-lua?=	../../inputmethod/fcitx5-lua

.endif	# FCITX5_LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx5-lua
