# $NetBSD: mysql.buildlink3.mk,v 1.20 2015/04/16 20:24:15 ryoon Exp $
#
# This file is included by packages that require some version of the
# MySQL database client.
#
# === User-settable variables ===
#
# MYSQL_VERSION_DEFAULT
#	The preferred MySQL version.
#
#	Possible: 56 55 51 MARIADB55
#	Default: 55
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

MYSQL_VERSION_DEFAULT?=		55
MYSQL_VERSIONS_ACCEPTED?=	56 55 51 MARIADB55

# transform the list into individual variables
.for mv in ${MYSQL_VERSIONS_ACCEPTED}
_MYSQL_VERSION_${mv}_OK=	yes
.endfor

# check what is installed
.if ${OPSYS} == "Darwin"
.  if exists(${LOCALBASE}/lib/libmysqlclient.18.dylib)
.    if exists(${LOCALBASE}/include/mysql/mysql/client_authentication.h)
_MYSQL_VERSION_56_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	56
.    else
_MYSQL_VERSION_55_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	55
.    endif
.  endif
.  if exists(${LOCALBASE}/lib/mysql/libmysqlclient.16.dylib)
_MYSQL_VERSION_51_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	51
.  endif
.else
.  if exists(${LOCALBASE}/lib/libmysqlclient.so.18)
.    if exists(${LOCALBASE}/include/mysql/mysql/client_authentication.h)
_MYSQL_VERSION_56_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	56
.    elif exists(${LOCALBASE}/share/mariadb)
_MYSQL_VERSION_MARIADB55_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	MARIADB55
.    else
_MYSQL_VERSION_55_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	55
.    endif
.  endif
.  if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.16)
_MYSQL_VERSION_51_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	51
.  endif
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
.if ${_MYSQL_VERSION} == "56"
MYSQL_PKGSRCDIR=	../../databases/mysql56-client
.elif ${_MYSQL_VERSION} == "MARIADB55"
MYSQL_PKGSRCDIR=	../../databases/mariadb55-client
.elif ${_MYSQL_VERSION} == "55"
MYSQL_PKGSRCDIR=	../../databases/mysql55-client
.elif ${_MYSQL_VERSION} == "51"
MYSQL_PKGSRCDIR=	../../databases/mysql51-client
.else
# force an error
PKG_FAIL_REASON+=	"[mysql.buildlink3.mk] ${_MYSQL_VERSION} is not a valid mysql package."
.endif

#
# check installed version aginst required:
#
.if defined(_MYSQL_VERSION_INSTALLED)
.  if ${_MYSQL_VERSION} != ${_MYSQL_VERSION_INSTALLED}
PKG_FAIL_REASON+=	"${PKGBASE} requires mysql-${_MYSQL_VERSION}, but mysql-${_MYSQL_VERSION_INSTALLED} is already installed."
.  endif
.endif

.include "${MYSQL_PKGSRCDIR}/buildlink3.mk"

.endif	# MYSQL_VERSION_MK
