# $NetBSD: bdb.buildlink3.mk,v 1.13 2005/01/09 23:56:21 jlam Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Berkeley DB implementation.  bdb.buildlink3.mk will:
#
#       * set BDBBASE to the base directory of the Berkeley DB files;
#	* set BDB_LIBS to the library option needed to link against
#	  the Berkeley DB library;
#       * set BDB_TYPE to the Berkeley DB implementation used.
#
# There are two variables that can be used to tweak the selection of
# the Berkeley DB implementation:
#
# BDB_DEFAULT is a user-settable variable whose value represents the
#	package we use when either a db-1.85 interface isn't required,
#	or a db-1.85 interface is required, but it's not built-in.
#
# BDB185_DEFAULT is a user-settable variable whose value represents the
#	package we use when a db-1.85 interface is required.  It defaults
#	to "db1" if it's built-in, or to ${BDB_DEFAULT} otherwise.
#
# BDB_ACCEPTED is a package-settable list of Berkeley DB implementations
#       that may be used by the package.
#
# Note for when databases/db1 is imported:
#   (1) Remove the section that conditionally sets the default
#	value for BDB185_DEFAULT and always set it to be "db1".
#   (2) Remove the special case for ${BDB_TYPE} == "db1" at the end.
#   (3) Move mk/db1.builtin.mk to databases/db1/builtin.mk.

BDB_BUILDLINK3_MK:=	${BDB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BDB_BUILDLINK3_MK:M+)

# If we've specified a list of acceptable Berkeley DB packages and it
# doesn't include db1, then don't set USE_DB185 to yes.  The package's
# configure process should know how to probe for the libraries and
# headers on its own.
#
.  if defined(BDB_ACCEPTED) && empty(BDB_ACCEPTED:Mdb1)
USE_DB185?=	no
.  else
USE_DB185?=	yes
.  endif

# _BDB_PKGS is an exhaustive list of all of the Berkeley DB
# implementations that may be used with bdb.buildlink3.mk.
#
_BDB_PKGS?=	db1 db2 db3 db4

BDB_DEFAULT?=	db4
BDB_ACCEPTED?=	${_BDB_PKGS}

CHECK_BUILTIN.db1:=	yes
.  include "../../mk/db1.builtin.mk"
CHECK_BUILTIN.db1:=	no
.  if defined(IS_BUILTIN.db1) && !empty(IS_BUILTIN.db1:M[yY][eE][sS])
BDB185_DEFAULT?=	db1
.  else
BDB185_DEFAULT?=	${BDB_DEFAULT}
.  endif

_BDB_PKGBASE.db2=		db
_BDB_PKGSRCDIR.db2=		../../databases/db
.  for _bdb_ in ${_BDB_PKGS}
_BDB_PKGBASE.${_bdb_}?=		${_bdb_}
_BDB_PKGSRCDIR.${_bdb_}?=	../../databases/${_bdb_}
.  endfor

_BDB_DEFAULT=		${BDB_DEFAULT}
_BDB185_DEFAULT=	${BDB185_DEFAULT}
_BDB_ACCEPTED=		${BDB_ACCEPTED}

.  if !defined(_BDB_TYPE)
.    if !empty(USE_DB185:M[yY][eE][sS])
_BDB_TYPE=	${_BDB185_DEFAULT}
.    else
_BDB_TYPE=	${_BDB_DEFAULT}
.    endif
.  endif

.  if !empty(_BDB_ACCEPTED:M${_BDB_TYPE})
BDB_TYPE=	${_BDB_TYPE}
.  else
BDB_TYPE=	none
.  endif

# Define some public variables to refer to package-specific variables.
BDBBASE=	${BUILDLINK_PREFIX.${_BDB_PKGBASE.${BDB_TYPE}}}
BDB_LIBS=	${BUILDLINK_LDADD.${_BDB_PKGBASE.${BDB_TYPE}}}

BUILD_DEFS+=	BDB_TYPE
BUILD_DEFS+=	BDBBASE

.endif	# BDB_BUILDLINK3_MK

.if ${BDB_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_BDB_TYPE} is not an acceptable Berkeley DB type for ${PKGNAME}."
.elif ${BDB_TYPE} == "db1"
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ndb1}
BUILDLINK_PACKAGES+=		db1
BUILDLINK_BUILTIN_MK.db1=	../../mk/db1.builtin.mk
.else
.  include "${_BDB_PKGSRCDIR.${BDB_TYPE}}/buildlink3.mk"
.endif
