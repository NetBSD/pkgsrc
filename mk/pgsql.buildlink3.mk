# $NetBSD: pgsql.buildlink3.mk,v 1.6 2005/02/07 04:12:49 dan Exp $

.if !defined(PGVERSION_MK)
PGVERSION_MK=	defined

.include "../../mk/bsd.prefs.mk"

PGSQL_VERSION_DEFAULT?=		74
PGSQL_VERSIONS_ACCEPTED?=	80 74 73

# transform the list into individual variables
.for pv in ${PGSQL_VERSIONS_ACCEPTED}
_PGSQL_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/lib/libecpg.so.4.2)
_PGSQL_VERSION_80_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/lib/libecpg.so.4.1)
_PGSQL_VERSION_74_INSTALLED=	yes
.endif
.if exists(${LOCALBASE}/lib/libecpg.so.3)
_PGSQL_VERSION_73_INSTALLED=yes
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

#
# set variables for the version we decided to use:
#
.if ${_PGSQL_VERSION} == "80"
PGPKGSRCDIR=	../../databases/postgresql80-lib
.elif ${_PGSQL_VERSION} == "74"
PGPKGSRCDIR=	../../databases/postgresql74-lib
.elif ${_PGSQL_VERSION} == "73"
PGPKGSRCDIR=	../../databases/postgresql73-lib
.else
# force an error
PKG_SKIP_REASON+=	"${_PGSQL_VERSION} is not a valid package"
.endif

.if (defined(USE_BUILDLINK3) && empty(USE_BUILDLINK3:M[nN][oO]))
.    include "${PGPKGSRCDIR}/buildlink3.mk"
PGSQL_PREFIX=	${BUILDLINK_PREFIX.postgresql${_PGSQL_VERSION}-lib}
.endif

.endif	# PGVERSION_MK
