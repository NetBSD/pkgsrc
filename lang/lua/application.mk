# $NetBSD: application.mk,v 1.2 2013/10/30 06:53:19 dholland Exp $
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

.include "../../lang/lua/luaversion.mk"

.if defined(REPLACE_LUA)
REPLACE_INTERPRETER+=	lua
REPLACE.lua.old=	.*lua
REPLACE.lua.new=	${PREFIX}/bin/lua
REPLACE_FILES.lua=	${REPLACE_LUA}
.endif
