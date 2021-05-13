# $NetBSD: mysql.buildlink3.mk,v 1.32 2021/05/13 15:29:04 jdolecek Exp $
#
# This file is included by packages that require some version of the
# MySQL database client.
#
# User-settable variables:
#
# MYSQL_VERSION_DEFAULT
#	The preferred MySQL version.
#
#	Possible: 57 56 80 MARIADB104
#	Default: 57
#
# Package-settable variables:
#
# MYSQL_VERSIONS_ACCEPTED
#	The list of MySQL versions that the package accepts.
#
#	Possible: (see MYSQL_VERSION_DEFAULT)
#	Default: (all)
#
# Variables set by this file:
#
# MYSQL_VERSION

.if !defined(MYSQL_VERSION_MK)
MYSQL_VERSION_MK=	# defined

BUILD_DEFS+=		MYSQL_VERSION_DEFAULT
BUILD_DEFS_EFFECTS+=	MYSQL_PKGSRCDIR

_VARGROUPS+=		mysql
_USER_VARS.mysql=	MYSQL_VERSION_DEFAULT
_PKG_VARS.mysql=	MYSQL_VERSIONS_ACCEPTED
_SYS_VARS.mysql=	MYSQL_PKGSRCDIR

.include "../../mk/bsd.prefs.mk"

MYSQL_VERSION_DEFAULT?=		57
MYSQL_VERSIONS_ACCEPTED?=	57 56 80 MARIADB104

# transform the list into individual variables
.for mv in ${MYSQL_VERSIONS_ACCEPTED}
_MYSQL_VERSION_${mv}_OK=	yes
.endfor

# check what is installed
.if ${OPSYS} == "Darwin"
_MYSQL_SO_80=	21.dylib
_MYSQL_SO_57=	20.dylib
_MYSQL_SO_56=	18.dylib
.else
_MYSQL_SO_80=	so.21
_MYSQL_SO_57=	so.20
_MYSQL_SO_56=	so.18
.endif

.if exists(${LOCALBASE}/lib/libmysqlclient.${_MYSQL_SO_80})
_MYSQL_VERSION_80_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	80
.endif
.if exists(${LOCALBASE}/lib/libmysqlclient.${_MYSQL_SO_57})
_MYSQL_VERSION_57_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	57
.elif exists(${LOCALBASE}/lib/libmysqlclient.${_MYSQL_SO_56})
_MYSQL_VERSION_56_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	56
.elif exists(${LOCALBASE}/lib/libmariadb.so.3)
_MYSQL_VERSION_MARIADB104_INSTALLED=	yes
_MYSQL_VERSION_INSTALLED=	MARIADB104
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
.if ${_MYSQL_VERSION} == "80"
MYSQL_PKGSRCDIR=	../../databases/mysql80-client
.elif ${_MYSQL_VERSION} == "57"
MYSQL_PKGSRCDIR=	../../databases/mysql57-client
.elif ${_MYSQL_VERSION} == "56"
MYSQL_PKGSRCDIR=	../../databases/mysql56-client
.elif ${_MYSQL_VERSION} == "MARIADB104"
MYSQL_PKGSRCDIR=	../../databases/mariadb104-client
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

.if defined(MYSQL_PKGSRCDIR)
.include "${MYSQL_PKGSRCDIR}/buildlink3.mk"
.endif

MYSQL_VERSION=		${_MYSQL_VERSION}

.endif	# MYSQL_VERSION_MK
