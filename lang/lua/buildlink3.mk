# $NetBSD: buildlink3.mk,v 1.14 2011/01/19 13:46:13 adam Exp $

BUILDLINK_TREE+=	lua

.if !defined(LUA_BUILDLINK3_MK)
LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua+=	lua>=5.1.1
BUILDLINK_ABI_DEPENDS.lua+=	lua>=5.1.4nb1
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua

.include "../../devel/readline/buildlink3.mk"
.endif # LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua
