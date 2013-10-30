# $NetBSD: luaversion.mk,v 1.2 2013/10/30 08:53:40 obache Exp $

# This file determins which Lua version is used as a dependency for
# a package.
#
# === User-settable variables ===
#
# LUA_VERSION_DEFAULT
#	The preferred lua version to use.
#
#	Possible values: 51 52
#	Default: 52
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
#	Possible values: 51 52
#	Default: 52 51
#
# LUA_VERSIONS_INCOMPATIBLE
#	The Lua versions that the package *cannot* build against.
#
#	Possible values: 51 52
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
#	Example: lua51
#
# Keywords: Lua
#

.if !defined (LUA_LUAVERSION_MK)
LUA_LUAVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		LUA_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	LUAPACKAGE

LUA_VERSION_DEFAULT?=	52
LUA_VERSIONS_ACCEPTED?=	52 51
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

.if ${_LUA_VERSION} == "52"
LUA_PACKAGE=		lua52
LUA_PKGSRCDIR=		../../lang/lua52
LUA_PKGPREFIX=		lua52
LUA_BASEDEPENDS=	lua52>=5.2<5.3${LUA_PKGSRCDIR}

.elif ${_LUA_VERSION} == "51"
LUA_PACKAGE=		lua51
LUA_PKGSRCDIR=		../../lang/lua51
LUA_PKGPREFIX=		lua51
LUA_BASEDEPENDS=	lua51>=5.1<5.2:${LUA_PKGSRCDIR}

.else
PKG_FAIL_REASION+=	"No valid Lua version found"

.endif

#LUA_DEPENDS=	${BUILDLINK_API_DEPENDS.${LUA_PACKAGE}}:${LUA_PKGSRCDIR}

.include "${LUA_PKGSRCDIR}/version.mk"
_LUA_DOT_VERSION=	${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

.endif  # LUA_LUAVERSION_MK
