# $NetBSD: module.mk,v 1.2 2009/01/24 02:56:19 obache Exp $
#
# This Makefile fragment is intended to be included by packages that
# install Lua packages.

.if !defined(LUA_MODULE_MK)
LUA_MODULE_MK=	# defined

.include "../../lang/lua/version.mk"

_LUA_VERSION=	${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

LUA_PKGPREFIX=	lua
LUA_LDIR=	share/lua/${_LUA_VERSION}
PLIST_SUBST+=	LUA_LDIR=${LUA_LDIR}

PRINT_PLIST_AWK+=	/^@dirrm share\/lua$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${LUA_LDIR:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${LUA_LDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_LDIR:S|/|\\/|g}/, "$${LUA_LDIR}"); print; next; }

.if defined(NO_BUILD) && empty(NO_BUILD:M[Nn][Oo])
DEPENDS+=	lua-${_LUA_VERSION}.*:../../lang/lua
.else
LUA_CDIR=	lib/lua/${_LUA_VERSION}
PLIST_SUBST+=	LUA_CDIR=${LUA_CDIR}

BUILDLINK_API_DEPENDS.lua+=	lua-${_LUA_VERSION}.*

PRINT_PLIST_AWK+=	/^@dirrm lib\/lua$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${LUA_CDIR:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${LUA_CDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_CDIR:S|/|\\/|g}/, "$${LUA_CDIR}"); print; next; }

.include "../../lang/lua/buildlink3.mk"
.endif

.endif  # LUA_MODULE_MK
