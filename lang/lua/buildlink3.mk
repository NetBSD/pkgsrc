# $NetBSD: buildlink3.mk,v 1.15 2013/07/04 18:04:42 adam Exp $

BUILDLINK_TREE+=	lua

.if !defined(LUA_BUILDLINK3_MK)
LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua+=	lua>=5.2.0
BUILDLINK_ABI_DEPENDS.lua+=	lua>=5.2.0
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua

.include "../../devel/readline/buildlink3.mk"
.endif # LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua
