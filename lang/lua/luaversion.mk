# $NetBSD: luaversion.mk,v 1.16 2022/06/28 09:39:29 nia Exp $

# This file determines which Lua version is used as a dependency for
# a package.
#
# === User-settable variables ===
#
# LUA_VERSION_DEFAULT
#	The preferred lua version to use.
#
#	Possible values: 51 52 53 54
#	Default: 53
#
# === Infrastructure variables ===
#
# LUA_VERSION_REQD
#	Lua version to use. This variable should not be set by
#	packages; it is ordinarily set by multiversion builds.
#
#	Possible values: ${LUA_VERSIONS_ACCEPTED}
#	Default: ${LUA_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# LUA_VERSIONS_ACCEPTED
#	The Lua versions that the package can build against. Order
#	is significant; those listed earlier are preferred over those
#	listed later.
#
#	Possible values: 51 52 53 54
#	Default: 54 53 52 51
#
# LUA_VERSIONS_INCOMPATIBLE
#	The Lua versions that the package *cannot* build against.
#
#	Possible values: 51 52 53 54
#	Default: <empty>
#
# LUA_SELF_CONFLICT
#	If set to "yes", CONFLICTS entries are added among the various
#	per-Lua-version variants of a multiversion package.
#
# === Defined variables ===
#
# LUA_PKGPREFIX
#	The prefix to use in PKGNAME for multiversion packages.
#
#	Example: lua53
#
# LUA_INCDIR
#	Relative path to include files.
#
#	Example: include/lua-5.3
#
# LUA_INTERPRETER
#	Full path to Lua interpreter.
#
# LUA_COMPILER
#	Full path to Lua bytecode compiler (luac).
#
# Keywords: Lua
#

.if !defined (LUA_LUAVERSION_MK)
LUA_LUAVERSION_MK=	# defined

# derive a Lua version from the package name if possible
# optionally handled quoted package names
.if defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:Mlua[0-9][0-9]-*) || \
    defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:M*-lua[0-9][0-9]-*)
LUA_VERSION_REQD?= ${PKGNAME_REQD:C/(^.*-|^)lua([0-9][0-9])-.*/\2/}
.elif defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:Mlua[0-9][0-9]-*) || \
    defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:M*-lua[0-9][0-9]-*)
LUA_VERSION_REQD?= ${PKGNAME_OLD:C/(^.*-|^)lua([0-9][0-9])-.*/\2/}
.endif

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		LUA_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	LUA_PACKAGE

LUA_VERSION_DEFAULT?=	54
LUA_VERSIONS_ACCEPTED?=	54 53 52 51
LUA_VERSIONS_INCOMPATIBLE?=# empty

#
# Resolve LUA_VERSIONS_INCOMPATBLE and generate the _OK vars.
#
.for v in ${LUA_VERSIONS_ACCEPTED}
.if empty(LUA_VERSIONS_INCOMPATIBLE:M${v})
_LUA_VERSION_${v}_OK=		yes
_LUA_VERSIONS_ACCEPTED+=	${v}
.endif
.endfor

# Pick a version
.if defined(LUA_VERSION_REQD)
.  if defined(_LUA_VERSION_${LUA_VERSION_REQD}_OK)
_LUA_VERSION=		${LUA_VERSION_REQD}
.  endif
.else
.  if defined(_LUA_VERSION_${LUA_VERSION_DEFAULT}_OK)
_LUA_VERSION?=		${LUA_VERSION_DEFAULT}
.  endif
.  for v in ${_LUA_VERSIONS_ACCEPTED}
.    if defined(_LUA_VERSION_${v}_OK)
_LUA_VERSION?=		${v}
.    endif
.  endfor
.endif

#
# Enable multiversion builds.
#
MULTI+=	LUA_VERSION_REQD=${_LUA_VERSION}

# In case nothing matched
_LUA_VERSION?=		none

#
# Handle self-conflicts
#
.if defined(LUA_SELF_CONFLICT) && !empty(LUA_SELF_CONFLICT:M[Yy][Ee][Ss])
.for v in ${_LUA_VERSIONS_ACCEPTED:N${_LUA_VERSION}}
CONFLICTS+=	${PKGNAME:S/lua${_LUA_VERSION}/lua${v}/:C/-[0-9].*$/-[0-9]*/}
.endfor
.endif

.if ${_LUA_VERSION} == "51"
LUA_PACKAGE=		lua51
LUA_PKGSRCDIR=		../../lang/lua51
LUA_PKGPREFIX=		lua51
LUA_BASEDEPENDS=	lua51>=5.1<5.2:${LUA_PKGSRCDIR}

.elif ${_LUA_VERSION} == "52"
LUA_PACKAGE=		lua52
LUA_PKGSRCDIR=		../../lang/lua52
LUA_PKGPREFIX=		lua52
LUA_BASEDEPENDS=	lua52>=5.2<5.3:${LUA_PKGSRCDIR}

.elif ${_LUA_VERSION} == "53"
LUA_PACKAGE=		lua53
LUA_PKGSRCDIR=		../../lang/lua53
LUA_PKGPREFIX=		lua53
LUA_BASEDEPENDS=	lua53>=5.3<5.4:${LUA_PKGSRCDIR}

.elif ${_LUA_VERSION} == "54"
LUA_PACKAGE=		lua54
LUA_PKGSRCDIR=		../../lang/lua54
LUA_PKGPREFIX=		lua54
LUA_BASEDEPENDS=	lua54>=5.4<5.5:${LUA_PKGSRCDIR}

.else
PKG_FAIL_REASON+=	"No valid Lua version found"

.endif

#LUA_DEPENDS=	${BUILDLINK_API_DEPENDS.${LUA_PACKAGE}}:${LUA_PKGSRCDIR}

.include "${LUA_PKGSRCDIR}/version.mk"
_LUA_DOT_VERSION=	${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

LUA_INCDIR=		include/lua-${_LUA_DOT_VERSION}
LUA_INTERPRETER=	${LOCALBASE}/bin/lua${_LUA_DOT_VERSION}
LUA_COMPILER=		${LOCALBASE}/bin/luac${_LUA_DOT_VERSION}

.endif  # LUA_LUAVERSION_MK
