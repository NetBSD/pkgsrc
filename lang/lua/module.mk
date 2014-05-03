# $NetBSD: module.mk,v 1.6 2014/05/03 13:00:44 alnsn Exp $
#
# This Makefile fragment is intended to be included by packages that
# install Lua modules.
#
# === Defined variables ===
#
# LUA_LDIR
#	Path where Lua modules are installed.
#
# LUA_CDIR
#	Path where Lua C modules are installed. Not defined if
#	NO_BUILD variable is set to "yes".
#
# LUA_DOCDIR
#	Path where documentation files are installed.
#
# LUA_EXAMPLESDIR
#	Path where example files are installed.
#
# Keywords: lua
#

.if !defined(LUA_MODULE_MK)
LUA_MODULE_MK=	# defined

.if !defined(LUA_LUAVERSION_MK)
.include "../../lang/lua/luaversion.mk"
.endif

LUA_LDIR=	share/lua/${_LUA_DOT_VERSION}
PLIST_SUBST+=	LUA_LDIR=${LUA_LDIR}

PRINT_PLIST_AWK+=	/^${LUA_LDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_LDIR:S|/|\\/|g}/, "$${LUA_LDIR}") }

.if defined(NO_BUILD) && empty(NO_BUILD:M[Nn][Oo])
DEPENDS+=	${LUA_BASEDEPENDS}

.else
LUA_CDIR=	lib/lua/${_LUA_DOT_VERSION}
PLIST_SUBST+=	LUA_CDIR=${LUA_CDIR}

PRINT_PLIST_AWK+=	/^${LUA_CDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_CDIR:S|/|\\/|g}/, "$${LUA_CDIR}") }

.include "${LUA_PKGSRCDIR}/buildlink3.mk"
.endif

LUA_DOCDIR=	share/doc/${PKGBASE}
PLIST_SUBST+=	LUA_DOCDIR=${LUA_DOCDIR}

LUA_EXAMPLESDIR=	share/examples/${PKGBASE}
PLIST_SUBST+=		LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR}

.endif  # LUA_MODULE_MK
