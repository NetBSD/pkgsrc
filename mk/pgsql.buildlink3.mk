# $NetBSD: pgsql.buildlink3.mk,v 1.41 2016/02/25 21:39:07 tnn Exp $
#
# User-settable variables:
#
# PGSQL_VERSION_DEFAULT
#
# Package-settable variables:
#
# PGSQL_VERSIONS_ACCEPTED
#
# Variables set by this file:
#
# PG_LIB_EXT
# PGSQL_TYPE
# PGPKGSRCDIR

.if !defined(PGVERSION_MK)
PGVERSION_MK=	defined

_VARGROUPS+=		pgsql
_USER_VARS.pgsql=	PGSQL_VERSION_DEFAULT
_PKG_VARS.pgsql=	PGSQL_VERSIONS_ACCEPTED
_SYS_VARS.pgsql=	PG_LIB_EXT PGSQL_TYPE PGPKGSRCDIR

.include "../../mk/bsd.prefs.mk"

PGSQL_VERSION_DEFAULT?=		93
PGSQL_VERSIONS_ACCEPTED?=	95 94 93 92 91

# transform the list into individual variables
.for pv in ${PGSQL_VERSIONS_ACCEPTED}
_PGSQL_VERSION_${pv}_OK=	yes
.endfor

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PG_LIB_EXT=dylib
.else
PG_LIB_EXT=so
.endif

# check what is installed
.if ${OPSYS} == "Darwin"
.  if exists(${LOCALBASE}/lib/libecpg.6.7.dylib)
_PGSQL_VERSION_95_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.6.dylib)
_PGSQL_VERSION_94_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.5.dylib)
_PGSQL_VERSION_93_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.4.dylib)
_PGSQL_VERSION_92_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.3.dylib)
_PGSQL_VERSION_91_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.2.dylib)
_PGSQL_VERSION_90_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.1.dylib)
_PGSQL_VERSION_84_INSTALLED=	yes
.  endif
.else
.  if exists(${LOCALBASE}/lib/libecpg.so.6.7)
_PGSQL_VERSION_95_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.6)
_PGSQL_VERSION_94_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.5)
_PGSQL_VERSION_93_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.4)
_PGSQL_VERSION_92_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.3)
_PGSQL_VERSION_91_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.2)
_PGSQL_VERSION_90_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.1)
_PGSQL_VERSION_84_INSTALLED=	yes
.  endif
.endif

# if a version is explicitely required, take it
.if defined(PGSQL_VERSION_REQD)
_PGSQL_VERSION=	${PGSQL_VERSION_REQD}
.endif
# if the default is already installed, it is first choice
.if !defined(_PGSQL_VERSION)
.if defined(_PGSQL_VERSION_${PGSQL_VERSION_DEFAULT}_OK)
.if defined(_PGSQL_VERSION_${PGSQL_VERSION_DEFAULT}_INSTALLED)
_PGSQL_VERSION=	${PGSQL_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PGSQL_VERSION)
.for pv in ${PGSQL_VERSIONS_ACCEPTED}
.if defined(_PGSQL_VERSION_${pv}_INSTALLED)
_PGSQL_VERSION?=	${pv}
.else
# keep information as last resort - see below
_PGSQL_VERSION_FIRSTACCEPTED?=	${pv}
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_PGSQL_VERSION)
.if defined(_PGSQL_VERSION_${PGSQL_VERSION_DEFAULT}_OK)
_PGSQL_VERSION=	${PGSQL_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_PGSQL_VERSION)
_PGSQL_VERSION=	${_PGSQL_VERSION_FIRSTACCEPTED}
.endif

# set variables for the version we decided to use:
.if ${_PGSQL_VERSION} == "95"
PGSQL_TYPE=	postgresql95-client
PGPKGSRCDIR=	../../databases/postgresql95-client
.elif ${_PGSQL_VERSION} == "94"
PGSQL_TYPE=	postgresql94-client
PGPKGSRCDIR=	../../databases/postgresql94-client
.elif ${_PGSQL_VERSION} == "93"
PGSQL_TYPE=	postgresql93-client
PGPKGSRCDIR=	../../databases/postgresql93-client
.elif ${_PGSQL_VERSION} == "92"
PGSQL_TYPE=	postgresql92-client
PGPKGSRCDIR=	../../databases/postgresql92-client
.elif ${_PGSQL_VERSION} == "91"
PGSQL_TYPE=	postgresql91-client
PGPKGSRCDIR=	../../databases/postgresql91-client
.else
# force an error
PGSQL_TYPE=		none
PKG_FAIL_REASON+=	"${_PGSQL_VERSION} is not a valid package"
.endif

.include "${PGPKGSRCDIR}/buildlink3.mk"
PGSQL_PREFIX=	${BUILDLINK_PREFIX.${PGSQL_TYPE}}

PGSQL_VERSION=	${_PGSQL_VERSION}

.endif	# PGVERSION_MK
