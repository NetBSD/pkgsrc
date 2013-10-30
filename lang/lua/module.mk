# $NetBSD: module.mk,v 1.5 2013/10/30 06:18:09 dholland Exp $
#
# This Makefile fragment is intended to be included by packages that
# install Lua packages.

.if !defined(LUA_MODULE_MK)
LUA_MODULE_MK=	# defined

.include "../../lang/lua/luaversion.mk"

LUA_LDIR=	share/lua/${_LUA_DOT_VERSION}
PLIST_SUBST+=	LUA_LDIR=${LUA_LDIR}

.if defined(NO_BUILD) && empty(NO_BUILD:M[Nn][Oo])
DEPENDS+=	${LUA_BASEDEPENDS}

.else
LUA_CDIR=	lib/lua/${_LUA_DOT_VERSION}
PLIST_SUBST+=	LUA_CDIR=${LUA_CDIR}

PRINT_PLIST_AWK+=	/^${LUA_LDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_LDIR:S|/|\\/|g}/, "$${LUA_LDIR}") }
PRINT_PLIST_AWK+=	/^${LUA_CDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_CDIR:S|/|\\/|g}/, "$${LUA_CDIR}") }

.include "${LUA_PKGSRCDIR}/buildlink3.mk"
.endif

.endif  # LUA_MODULE_MK
