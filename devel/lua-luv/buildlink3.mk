# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 16:15:01 nia Exp $

BUILDLINK_TREE+=	lua-luv

.if !defined(LUA_LUV_BUILDLINK3_MK)
LUA_LUV_BUILDLINK3_MK:=

.include "../../lang/lua/luaversion.mk"

BUILDLINK_API_DEPENDS.lua-luv+=	${LUA_PKGPREFIX}-luv>=1.43.0.0nb1
BUILDLINK_PKGSRCDIR.lua-luv?=	../../devel/lua-luv

.include "../../devel/libuv/buildlink3.mk"
.endif	# LUA_LUV_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua-luv
