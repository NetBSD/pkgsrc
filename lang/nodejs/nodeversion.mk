# $NetBSD: nodeversion.mk,v 1.18 2024/05/22 05:07:10 triaxx Exp $

# This file determines which nodejs version is used as a dependency for
# a package.
#
# === User-settable variables ===
#
# NODE_VERSION_DEFAULT
#	The preferred node version to use.
#
#	Possible values: 18 20 22
#	Default: 20
#
# === Infrastructure variables ===
#
# NODE_VERSION_REQD
#	node version to use. This variable should not be set by
#	packages. Normally it is used by bulk build tools.
#
#	Possible values: ${NODE_VERSIONS_ACCEPTED}
#	Default: ${NODE_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# NODE_VERSIONS_ACCEPTED
#	The node versions that the package can build against. Order
#	is significant; those listed earlier are preferred over those
#	listed later.
#
#	Possible values: 18 20 22
#	Default: 18 20 22
#
# NODE_VERSIONS_INCOMPATIBLE
#	The node versions that the package *cannot* build against.
#
#	Possible values: 18 20 22
#	Default: <empty>
#
# Keywords: node
#

.if !defined (NODEJS_NODEVERSION_MK)
NODEJS_NODEVERSION_MK=	# defined

# derive a node version from the package name if possible
# optionally handled quoted package names
.if defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:Mnode[0-9]-*) || \
    defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:M*-node[0-9]-*)
NODE_VERSION_REQD?=	${PKGNAME_REQD:C/(^.*-|^)node([0-9])-.*/\2/}
.elif defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:Mnode[0-9]-*) || \
    defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:M*-node[0-9]-*)
NODE_VERSION_REQD?=	${PKGNAME_OLD:C/(^.*-|^)node([0-9])-.*/\2/}
.endif

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		NODE_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	NODE_PACKAGE

NODE_VERSION_DEFAULT?=		20
NODE_VERSIONS_ACCEPTED?=	18 20 22
NODE_VERSIONS_INCOMPATIBLE?=	# empty

# Resolve NODE_VERSIONS_INCOMPATIBLE and generate the _OK vars.
.for v in ${NODE_VERSIONS_ACCEPTED}
.  if empty(NODE_VERSIONS_INCOMPATIBLE:M${v})
_NODE_VERSION_${v}_OK=		yes
_NODE_VERSIONS_ACCEPTED+=	${v}
.  endif
.endfor

# Pick a version
.if defined(NODE_VERSION_REQD)
.  if defined(_NODE_VERSION_${NODE_VERSION_REQD}_OK)
_NODE_VERSION=		${NODE_VERSION_REQD}
.  endif
.else
.  if defined(_NODE_VERSION_${NODE_VERSION_DEFAULT}_OK)
_NODE_VERSION?=		${NODE_VERSION_DEFAULT}
.  endif
.  for v in ${_NODE_VERSIONS_ACCEPTED}
.    if defined(_NODE_VERSION_${v}_OK)
_NODE_VERSION?=		${v}
.    endif
.  endfor
.endif

# In case nothing matched
_NODE_VERSION?=		none

.if ${_NODE_VERSION} == "18"
.include "../../lang/nodejs18/buildlink3.mk"
.elif ${_NODE_VERSION} == "20"
.include "../../lang/nodejs20/buildlink3.mk"
.elif ${_NODE_VERSION} == "22"
.include "../../lang/nodejs/buildlink3.mk"
.else
PKG_FAIL_REASON+=	"No valid node version found"
.endif

# Variable assignment for multi-node packages
MULTI+=	NODE_VERSION_REQD=${_NODE_VERSION}

.endif  # NODEJS_NODEVERSION_MK
