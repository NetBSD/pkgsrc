# $NetBSD: pgsql.buildlink3.mk,v 1.59 2022/06/28 09:38:38 nia Exp $
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
# PGSQL_VERSION

.if !defined(PGVERSION_MK)
PGVERSION_MK=	defined

_VARGROUPS+=		pgsql
_USER_VARS.pgsql=	PGSQL_VERSION_DEFAULT
_PKG_VARS.pgsql=	PGSQL_VERSIONS_ACCEPTED
_SYS_VARS.pgsql=	PG_LIB_EXT PGSQL_TYPE PGPKGSRCDIR

.include "../../mk/bsd.prefs.mk"

PGSQL_VERSION_DEFAULT?=		14
PGSQL_VERSIONS_ACCEPTED?=	14 13 12 11 10

# transform the list into individual variables
.for pv in ${PGSQL_VERSIONS_ACCEPTED}
_PGSQL_VERSION_${pv}_OK=	yes
.endfor

.if ${SHLIB_TYPE} == "dylib"
PG_LIB_EXT=dylib
.else
PG_LIB_EXT=so
.endif

# check what is installed
.if ${OPSYS} == "Darwin"
.  if exists(${LOCALBASE}/lib/libecpg.6.14.dylib)
_PGSQL_VERSION_14_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.13.dylib)
_PGSQL_VERSION_13_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.12.dylib)
_PGSQL_VERSION_12_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.11.dylib)
_PGSQL_VERSION_11_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.6.10.dylib)
_PGSQL_VERSION_10_INSTALLED=	yes
.  endif
.else
.  if exists(${LOCALBASE}/lib/libecpg.so.6.14)
_PGSQL_VERSION_14_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.13)
_PGSQL_VERSION_13_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.12)
_PGSQL_VERSION_12_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.11)
_PGSQL_VERSION_11_INSTALLED=	yes
.  endif
.  if exists(${LOCALBASE}/lib/libecpg.so.6.10)
_PGSQL_VERSION_10_INSTALLED=	yes
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
.if ${_PGSQL_VERSION} == "14"
PGSQL_TYPE=	postgresql14-client
PGPKGSRCDIR=	../../databases/postgresql14-client
.elif ${_PGSQL_VERSION} == "13"
PGSQL_TYPE=	postgresql13-client
PGPKGSRCDIR=	../../databases/postgresql13-client
.elif ${_PGSQL_VERSION} == "12"
PGSQL_TYPE=	postgresql12-client
PGPKGSRCDIR=	../../databases/postgresql12-client
.elif ${_PGSQL_VERSION} == "11"
PGSQL_TYPE=	postgresql11-client
PGPKGSRCDIR=	../../databases/postgresql11-client
.elif ${_PGSQL_VERSION} == "10"
PGSQL_TYPE=	postgresql10-client
PGPKGSRCDIR=	../../databases/postgresql10-client
.else
# force an error
PGSQL_TYPE=		none
PKG_FAIL_REASON+=	"${_PGSQL_VERSION} is not a valid package"
.endif

.include "${PGPKGSRCDIR}/buildlink3.mk"
PGSQL_PREFIX=	${BUILDLINK_PREFIX.${PGSQL_TYPE}}

PGSQL_VERSION=	${_PGSQL_VERSION}

.endif	# PGVERSION_MK
