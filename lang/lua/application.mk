# $NetBSD: application.mk,v 1.5 2025/11/28 18:01:43 hauke Exp $
#
# This makefile fragment is intended to be included by packages that
# install Lua scripts.
#
# Package-settable variables:
#
# REPLACE_LUA
#	A list of Lua scripts to be installed, relative to ${WRKSRC}.
#
# Keywords: Lua
#

.if !defined(LUA_LUAVERSION_MK)
.include "../../lang/lua/luaversion.mk"
.endif

.if defined(REPLACE_LUA)
REPLACE_INTERPRETER+=	lua
REPLACE.lua.old=	.*lua[^[:space:]]*
REPLACE.lua.new=	${LUA_INTERPRETER}
REPLACE_FILES.lua=	${REPLACE_LUA}
.endif
