# $NetBSD: bdb.buildlink3.mk,v 1.7 2004/04/25 15:06:10 minskim Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Berkeley DB implementation.  db.buildlink3.mk will:
#
#       * set BDBBASE to the base directory of the Berkeley DB files;
#       * set BDB_TYPE to the Berkeley DB implementation used.
#
# There are two variables that can be used to tweak the selection of
# the Berkeley DB implementation:
#
# BDB_DEFAULT is a user-settable variable whose value is the default
#       Berkeley DB implementation to use.
#
# BDB_ACCEPTED is a package-settable list of Berkeley DB implementations
#       that may be used by the package.

BDB_BUILDLINK3_MK:=	${BDB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BDB_BUILDLINK3_MK:M+)
BDB_DEFAULT?=	# empty
BDB_ACCEPTED?=	${_BDB_PKGS}

# This is an exhaustive list of all of the Berkeley DB implementations
# that may be used with bdb.buildlink3.mk, in order of precedence.
#
_BDB_PKGS?=	native db4 db3 db2

_BDB_PKGBASE.db2=	db
.  for _bdb_ in ${_BDB_PKGS}
_BDB_PKGBASE.${_bdb_}?=	${_bdb_}
.  endfor

_BDB_DEFAULT=	${BDB_DEFAULT}
_BDB_ACCEPTED=	${BDB_ACCEPTED}

# Mark the acceptable Berkeley DB packages and check which, if any, are
# already installed.
#
.  for _bdb_ in ${_BDB_ACCEPTED:Nnative}
_BDB_OK.${_bdb_}=	yes
.    if !defined(_BDB_INSTALLED.${_bdb_})
_BDB_INSTALLED.${_bdb_}!=	\
	if ${PKG_INFO} -qe ${_BDB_PKGBASE.${_bdb_}}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_BDB_INSTALLED.${_bdb_}=${_BDB_INSTALLED.${_bdb_}}
.    endif
.  endfor

USE_DB185?=		yes
_BDB_OK.native?=	no
_BDB_INSTALLED.native?=	no
.  if exists(/usr/include/db.h)
_BDB_OK.native!=	\
	if ${GREP} -q "^\#define.*HASHVERSION.*2$$" /usr/include/db.h; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(_BDB_OK.native:M[yY][eE][sS])
_BDB_INSTALLED.native=	yes
_BDB_INCDIRS=		include
_BDB_TRANSFORM=		# empty
.    endif
.  endif
.  if !empty(_BDB_OK.native:M[nN][oO]) && exists(/usr/include/db1/db.h)
_BDB_OK.native=		yes
_BDB_INSTALLED.native=	yes
_BDB_INCDIRS=		include/db1
_BDB_TRANSFORM=		l:db:db1
.  endif
.  if !empty(USE_DB185:M[nN][oO])
_BDB_OK.native=		no
_BDB_INSTALLED.native=	no
_BDB_INCDIRS=		# empty
_BDB_TRANSFORM=		# empty
.  endif

.  if !defined(_BDB_TYPE)
#
# Prefer the default one if it's accepted,...
#
.    if !empty(_BDB_DEFAULT) && \
	defined(_BDB_OK.${_BDB_DEFAULT}) && \
	!empty(_BDB_OK.${_BDB_DEFAULT}:M[yY][eE][sS])
_BDB_TYPE=	${_BDB_DEFAULT}
.    endif
#
# ...otherwise, use one of the installed Berkeley DB packages,...
#
.    for _bdb_ in ${_BDB_ACCEPTED}
.      if !empty(_BDB_INSTALLED.${_bdb_}:M[yY][eE][sS])
_BDB_TYPE?=	${_bdb_}
.      else
_BDB_FIRSTACCEPTED?=	${_bdb_}
.      endif
.    endfor
#
# ...otherwise, just use the first accepted Berkeley DB package.
#
.    if defined(_BDB_FIRSTACCEPTED)
_BDB_TYPE?=	${_BDB_FIRSTACCEPTED}
.    endif
_BDB_TYPE?=	none
MAKEFLAGS+=	_BDB_TYPE=${_BDB_TYPE}
.  endif

BDB_TYPE=	${_BDB_TYPE}
BUILD_DEFS+=	BDB_TYPE
BUILD_DEFS+=	BDBBASE

.endif	# BDB_BUILDLINK3_MK

.if ${BDB_TYPE} == "none"
PKG_FAIL_REASON=	"No acceptable Berkeley DB implementation found."
.else
.  if ${BDB_TYPE} == "native"
IS_BUILTIN.db-native=		yes
USE_BUILTIN.db-native=		yes
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ndb-native}
BUILDLINK_PACKAGES+=		db-native
BUILDLINK_INCDIRS.db-native?=	${_BDB_INCDIRS}
BUILDLINK_TRANSFORM?=		${_BDB_TRANSFORM}
BDBBASE=	${BUILDLINK_PREFIX.db-native}
.  elif ${BDB_TYPE} == "db4"
BDBBASE=	${BUILDLINK_PREFIX.db4}
.    include "../../databases/db4/buildlink3.mk"
.  elif ${BDB_TYPE} == "db3"
BDBBASE=	${BUILDLINK_PREFIX.db3}
.    include "../../databases/db3/buildlink3.mk"
.  elif ${BDB_TYPE} == "db2"
BDBBASE=	${BUILDLINK_PREFIX.db2}
.    include "../../databases/db/buildlink3.mk"
.  endif
.endif
