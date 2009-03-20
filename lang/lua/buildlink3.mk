# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:50 joerg Exp $

BUILDLINK_TREE+=	lua

.if !defined(LUA_BUILDLINK3_MK)
LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua+=	lua>=5.1.1
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua

.include "../../devel/readline/buildlink3.mk"
.endif # LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua
