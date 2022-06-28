# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:36 wiz Exp $

BUILDLINK_TREE+=	libprelude-lua

.if !defined(LIBPRELUDE_LUA_BUILDLINK3_MK)
LIBPRELUDE_LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-lua+=	libprelude-lua>=0.9.24
BUILDLINK_ABI_DEPENDS.libprelude-lua?=	libprelude-lua>=0.9.24.1nb20
BUILDLINK_PKGSRCDIR.libprelude-lua?=	../../security/libprelude-lua
.endif	# LIBPRELUDE_LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-lua
