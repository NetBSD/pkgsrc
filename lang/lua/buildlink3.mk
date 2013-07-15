# $NetBSD: buildlink3.mk,v 1.16 2013/07/15 02:02:23 ryoon Exp $

BUILDLINK_TREE+=	lua

.if !defined(LUA_BUILDLINK3_MK)
LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua+=	lua>=5.2.0
BUILDLINK_ABI_DEPENDS.lua+=	lua>=5.2.0
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua

.include "../../mk/readline.buildlink3.mk"
.endif # LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua
