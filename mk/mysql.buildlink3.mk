# $NetBSD: mysql.buildlink3.mk,v 1.10 2010/03/05 13:47:06 taca Exp $
#
# This file is included by packages that require some version of the
# MySQL database client.
#
# === User-settable variables ===
#
# MYSQL_VERSION_DEFAULT
#	The preferred MySQL version.
#
#	Possible: 51 50 41
#	Default: 50
#
# === Package-settable variables ===
#
# MYSQL_VERSIONS_ACCEPTED
#	The list of MySQL versions that the package accepts.
#
#	Possible: (see MYSQL_VERSION_DEFAULT)
#	Default: (all)
#

.if !defined(MYSQL_VERSION_MK)
MYSQL_VERSION_MK=	# defined

_VARGROUPS+=		mysql
_USER_VARS.mysql=	MYSQL_VERSION_DEFAULT
_PKG_VARS.mysql=	MYSQL_VERSIONS_ACCEPTED
_SYS_VARS.mysql=	MYSQL_PKGSRCDIR

.include "../../mk/bsd.prefs.mk"

MYSQL_VERSION_DEFAULT?=		50
MYSQL_VERSIONS_ACCEPTED?=	51 50 41

# transform the list into individual variables
.for mv in ${MYSQL_VERSIONS_ACCEPTED}
_MYSQL_VERSION_${mv}_OK=	yes
.endfor

# check what is installed
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.16)
_MYSQL_VERSION_51_INSTALLED=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.15)
_MYSQL_VERSION_50_INSTALLED=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
_MYSQL_VERSION_41_INSTALLED=	yes
.endif

# if a version is explicitely required, take it
.if defined(MYSQL_VERSION_REQD)
_MYSQL_VERSION=	${MYSQL_VERSION_REQD}
.endif
# if the default is already installed, it is first choice
.if !defined(_MYSQL_VERSION)
.  if defined(_MYSQL_VERSION_${MYSQL_VERSION_DEFAULT}_OK)
.    if defined(_MYSQL_VERSION_${MYSQL_VERSION_DEFAULT}_INSTALLED)
_MYSQL_VERSION=	${MYSQL_VERSION_DEFAULT}
.    endif
.  endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_MYSQL_VERSION)
.  for mv in ${MYSQL_VERSIONS_ACCEPTED}
.    if defined(_MYSQL_VERSION_${mv}_INSTALLED)
_MYSQL_VERSION?=	${mv}
.    else
# keep information as last resort - see below
_MYSQL_VERSION_FIRSTACCEPTED?=	${mv}
.    endif
.  endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_MYSQL_VERSION)
.  if defined(_MYSQL_VERSION_${MYSQL_VERSION_DEFAULT}_OK)
_MYSQL_VERSION=	${MYSQL_VERSION_DEFAULT}
.  endif
.endif
# take the first one accepted by the package
.if !defined(_MYSQL_VERSION)
_MYSQL_VERSION=	${_MYSQL_VERSION_FIRSTACCEPTED}
.endif

#
# set variables for the version we decided to use:
#
.if ${_MYSQL_VERSION} == "51"
MYSQL_PKGSRCDIR=	../../databases/mysql51-client
.elif ${_MYSQL_VERSION} == "50"
MYSQL_PKGSRCDIR=	../../databases/mysql5-client
.elif ${_MYSQL_VERSION} == "41"
MYSQL_PKGSRCDIR=	../../databases/mysql4-client
.else
# force an error
PKG_FAIL_REASON+=	"[mysql.buildlink3.mk] ${_MYSQL_VERSION} is not a valid mysql package."
.endif

.include "${MYSQL_PKGSRCDIR}/buildlink3.mk"

.endif	# MYSQL_VERSION_MK
