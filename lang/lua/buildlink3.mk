# $NetBSD: buildlink3.mk,v 1.18 2015/07/20 11:30:54 wiz Exp $
#
# This is a fake buildlink3.mk file. It figures out the Lua version
# and then includes the real buildlink3.mk file for that Lua version.
#
# It is intended to be included by packages that embed the Lua
# interpreter and therefore link against Lua.

.include "../../lang/lua/luaversion.mk"
.include "${LUA_PKGSRCDIR}/buildlink3.mk"

BUILDLINK_PREFIX.lua=	${BUILDLINK_PREFIX.${LUA_PACKAGE}}

.if !defined(LUA_BUILDLINK3_MK)
LUA_BUILDLINK3_MK:=

BUILDLINK_TARGETS+=     buildlink-bin-unversioned

buildlink-bin-unversioned:
	${LN} -s ${BUILDLINK_DIR}/lib/pkgconfig/lua-${_LUA_DOT_VERSION}.pc ${BUILDLINK_DIR}/lib/pkgconfig/lua.pc
.endif # LUA_BUILDLINK3_MK
