# $NetBSD: module.mk,v 1.10 2020/07/11 15:30:52 nia Exp $
#
# This Makefile fragment is intended to be included by packages that
# install Lua modules.
#
# === Package-settable variables ===
#
# LUA_LINKER_MAGIC
#	This appends LDFLAGS to properly link Lua modules on non-ELF
#	linkers.
#
#	You probably want to set this to "no" if the package links
#	binaries that are not Lua modules.
#
#	Possible values: yes no
#	Default: yes
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

PRINT_PLIST_AWK+=	/^${LUA_DOCDIR:S|/|\\/|g}/ \
			{ gsub(/${LUA_DOCDIR:S|/|\\/|g}/, "$${LUA_DOCDIR}") }

LUA_EXAMPLESDIR=	share/examples/${PKGBASE}
PLIST_SUBST+=		LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR}

LUA_LINKER_MAGIC?=	yes

.if !empty(LUA_LINKER_MAGIC:M[yY][eE][sS])
LDFLAGS.Cygwin+=	-llua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
LDFLAGS.Darwin+=	-bundle -undefined dynamic_lookup
.endif

.if ${_LUA_VERSION} != "51" && ${_LUA_VERSION} != "52"
# Any Lua>=5.3 module using these flags is invalid,
# since Lua 5.3 and newer require "long long".
BUILDLINK_TRANSFORM+=	opt:-ansi:-std=c99
BUILDLINK_TRANSFORM+=	opt:-std=c89:-std=c99
BUILDLINK_TRANSFORM+=	opt:-std=c90:-std=c99
.endif

.endif  # LUA_MODULE_MK
