# $NetBSD: buildlink2.mk,v 1.1 2003/01/26 21:38:23 salo Exp $
#
# This Makefile fragment is included by packages that use lua.
#

.if !defined(LUA_BUILDLINK2_MK)
LUA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lua
BUILDLINK_DEPENDS.lua?=		lua>=4.0
BUILDLINK_PKGSRCDIR.lua?=	../../lang/lua

EVAL_PREFIX+=	BUILDLINK_PREFIX.lua=lua
BUILDLINK_PREFIX.lua_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lua+=	include/lauxlib.h
BUILDLINK_FILES.lua+=	include/lua.h
BUILDLINK_FILES.lua+=	include/luadebug.h
BUILDLINK_FILES.lua+=	include/lualib.h
BUILDLINK_FILES.lua+=	lib/liblua.*
BUILDLINK_FILES.lua+=	lib/liblualib.*

BUILDLINK_TARGETS+=	lua-buildlink

lua-buildlink: _BUILDLINK_USE

.endif	# LUA_BUILDLINK2_MK
