# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/23 19:03:34 hasso Exp $

BUILDLINK_TREE+=	libprelude-lua

.if !defined(LIBPRELUDE_LUA_BUILDLINK3_MK)
LIBPRELUDE_LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-lua+=	libprelude-lua>=0.9.24
BUILDLINK_PKGSRCDIR.libprelude-lua?=	../../security/libprelude-lua
.endif	# LIBPRELUDE_LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-lua
