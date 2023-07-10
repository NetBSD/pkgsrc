# $NetBSD: mysql.buildlink3.mk,v 1.39 2023/07/10 22:57:41 nia Exp $
#
# This file is included by packages that require some version of the
# MySQL database client.
#
# User-settable variables:
#
# MYSQL_VERSION_DEFAULT
#	The preferred MySQL version.
#
#	Possible: 57 56 80 mariadb1011 mariadb106 mariadb105 mariadb104
#	Default: mariadb106
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
BUILD_DEFS_EFFECTS+=	MYSQL_VERSION

_VARGROUPS+=		mysql
_USER_VARS.mysql=	MYSQL_VERSION_DEFAULT
_PKG_VARS.mysql=	MYSQL_VERSIONS_ACCEPTED
_SYS_VARS.mysql=	MYSQL_VERSION MYSQL_VERSION_REQD MYSQL_VERSIONS_ALL

#
# Set variables for all possible MySQL variants
#
MYSQL_VERSIONS_ALL=		80 57 56
MYSQL_VERSIONS_ALL+=		mariadb1011 mariadb106 mariadb105 mariadb104

MYSQL_PKGBASE.80=		mysql-client-8.0.*
MYSQL_PKGSRCDIR.80=		../../databases/mysql80-client

MYSQL_PKGBASE.57=		mysql-client-5.7.*
MYSQL_PKGSRCDIR.57=		../../databases/mysql57-client

MYSQL_PKGBASE.56=		mysql-client-5.6.*
MYSQL_PKGSRCDIR.56=		../../databases/mysql56-client

MYSQL_PKGBASE.mariadb104=	mariadb-client-10.4.*
MYSQL_PKGSRCDIR.mariadb104=	../../databases/mariadb104-client

MYSQL_PKGBASE.mariadb105=	mariadb-client-10.5.*
MYSQL_PKGSRCDIR.mariadb105=	../../databases/mariadb105-client

MYSQL_PKGBASE.mariadb106=	mariadb-client-10.6.*
MYSQL_PKGSRCDIR.mariadb106=	../../databases/mariadb106-client

MYSQL_PKGBASE.mariadb1011=	mariadb-client-10.11.*
MYSQL_PKGSRCDIR.mariadb1011=	../../databases/mariadb1011-client

.for ver in ${MYSQL_VERSIONS_ALL}
MYSQL_OK.${ver}=		no
MYSQL_INSTALLED.${ver}=		no
_SYS_VARS.mysql+=		MYSQL_PKGBASE.${ver} MYSQL_PKGSRCDIR.${ver}
.endfor

.include "../../mk/bsd.prefs.mk"

#
# Ordering here matters.  Unless a more specific version is requested, or if
# the default version is installed, the first accepted installed version will
# be chosen.
#
MYSQL_VERSION_DEFAULT?=		mariadb106
MYSQL_VERSIONS_ACCEPTED?=	57 56 80 mariadb1011 mariadb106 mariadb105 mariadb104

#
# Previous versions of this file used shouty caps in the version names.  We
# don't do that any longer, but do still support the older syntax.
#
MYSQL_VERSION_DEFAULT:=		${MYSQL_VERSION_DEFAULT:tl}
MYSQL_VERSIONS_ACCEPTED:=	${MYSQL_VERSIONS_ACCEPTED:tl}

#
# If version is acceptable, mark as OK and check to see if installed.
#
.for ver in ${MYSQL_VERSIONS_ACCEPTED}
MYSQL_OK.${ver}=		yes
MYSQL_INSTALLED.${ver}!=					\
	if ${PKG_INFO} -qe ${MYSQL_PKGBASE.${ver}:Q}; then	\
		${ECHO} yes;					\
	else							\
		${ECHO} no;					\
	fi
.endfor

#
# Selection process, first match wins:
#
#   - If a specific version is explicitly required, use it.
#   - Otherwise if the default version is installed, use that.
#   - Otherwise prefer an already installed version, in order of accepted.
#
# If no acceptable package is already installed:
#
#   - If the default is acceptable, use it.
#   - Otherwise require the first version listed as accepted.
#
.if defined(MYSQL_VERSION_REQD)
MYSQL_VERSION=	${MYSQL_VERSION_REQD}
.elif ${MYSQL_OK.${MYSQL_VERSION_DEFAULT}} == "yes" && \
      ${MYSQL_INSTALLED.${MYSQL_VERSION_DEFAULT}} == "yes"
MYSQL_VERSION=	${MYSQL_VERSION_DEFAULT}
.else
.  for ver in ${MYSQL_VERSIONS_ACCEPTED}
.    if ${MYSQL_INSTALLED.${ver}} == "yes"
MYSQL_VERSION?=	${ver}
.    endif
.  endfor
.endif
.if !defined(MYSQL_VERSION)
.  if ${MYSQL_OK.${MYSQL_VERSION_DEFAULT}} == "yes"
MYSQL_VERSION=	${MYSQL_VERSION_DEFAULT}
.  else
MYSQL_VERSION=	${MYSQL_VERSIONS_ACCEPTED:[1]}
.  endif
.endif

.if defined(MYSQL_PKGSRCDIR.${MYSQL_VERSION})
.  include "${MYSQL_PKGSRCDIR.${MYSQL_VERSION}}/buildlink3.mk"
.else
PKG_FAIL_REASON+=	"[mysql.buildlink3.mk] Invalid MySQL version '${MYSQL_VERSION}'."
.endif

.endif	# MYSQL_VERSION_MK
