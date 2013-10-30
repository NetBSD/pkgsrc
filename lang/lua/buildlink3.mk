# $NetBSD: buildlink3.mk,v 1.17 2013/10/30 06:18:09 dholland Exp $
#
# This is a fake buildlink3.mk file. It figures out the Lua version
# and then includes the real buildlink3.mk file for that Lua version.
#
# It is intended to be included by packages that embed the Lua
# interpreter and therefore link against Lua.

.include "../../lang/lua/luaversion.mk"
.include "${LUA_PKGSRCDIR}/buildlink3.mk"

BUILDLINK_PREFIX.lua=	${BUILDLINK_PREFIX.${LUA_PACKAGE}}
