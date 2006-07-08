# $NetBSD: bdb.buildlink3.mk,v 1.17 2006/07/08 23:11:17 jlam Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Berkeley DB implementation.  It abstracts finding the
# appropriate library, choosing among built-in or pkgsrc-provided
# db-1.85, and choosing among db[234].
#
# There is a default version for db[234], which is db4 unless already
# set (e.g. in /etc/mk.conf).  While it is nice to have fewer versions
# installed, the real problem is installed dynamic libraries that link
# against bdb.  These cannot be used with a program linked against a
# different version, and hence this Makefile is written to cause only
# one version to be used whenever possible.
#
# This Makefile can handle several cases:
#   package requires db-1.85
#   package can use any of db[234]
#   package can use db-1.85 or any of db[234]
#   package can use db-1.85 which is builtin and some subset of db[234]
# This Makefile does not handle
#   packages that need a specific version, e.g. db2
#     [in such cases, include ../../database/db2/buildlink3.mk directly]
#   packages that can use e.g. db3 or db4, but not db2
#     [there is no good way to handle this at present]
#
# bdb.buildlink3.mk will:
#
#       * set BDBBASE to the base directory of the Berkeley DB files;
#	* set BDB_LIBS to the library option needed to link against
#	  the Berkeley DB library;
#       * set BDB_TYPE to the Berkeley DB implementation used.
#
# There are two user-settable variables that can be used to control
# the selection of the Berkeley DB implementation:
#
# BDB_DEFAULT is a user-settable variable whose value represents the
#	package we use when either a db-1.85 interface isn't required,
#	or a db-1.85 interface is required, but it's not built-in.
#       This should be set in /etc/mk.conf, and should not be set by pkg
#	Makefiles. 
#
# BDB185_DEFAULT is a user-settable variable whose value represents the
#	package we use when a db-1.85 interface is required.  It defaults
#	to "db1" if it's built-in, or to ${BDB_DEFAULT} otherwise.
#
# BDB_ACCEPTED is a package-settable list of Berkeley DB implementations
#       that may be used by the package.  Note that if the list does not
#	include db1 and does not include BDB_DEFAULT, the package will not
#	build - this is the second unhandled case above.
#
# Note for when databases/db1 is imported:
#   (1) Remove the section that conditionally sets the default
#	value for BDB185_DEFAULT and always set it to be "db1".
#   (2) Remove the special case for ${BDB_TYPE} == "db1" at the end.
#   (3) Move mk/db1.builtin.mk to databases/db1/builtin.mk.

BDB_BUILDLINK3_MK:=	${BDB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BDB_BUILDLINK3_MK:M+)

# If the package specified a list of acceptable Berkeley DB packages,
# set USE_DB185 to yes if db1 is included, and otherwise no, thus
# preferring to use db1.  Assume that the package's configure process
# should know how to probe for the libraries and headers on its own.
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

# Decide what to use when DB185 is required.  If builtin db1 is
# present, use it, and if not use DBD_DEFAULT.
#
CHECK_BUILTIN.db1:=	yes
.  include "../../mk/db1.builtin.mk"
CHECK_BUILTIN.db1:=	no
.  if defined(IS_BUILTIN.db1) && !empty(IS_BUILTIN.db1:M[yY][eE][sS])
BDB185_DEFAULT?=	db1
.  else
BDB185_DEFAULT?=	${BDB_DEFAULT}
.  endif

_BDB_PKGSRCDIR.db2=		../../databases/db
.  for _bdb_ in ${_BDB_PKGS}
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

# Note that if BDB_ACCEPTED does not contain db1 or BDB_DEFAULT, this
# results in BDB_TYPE being none (rather than the most preferred value
# in BDB_ACCEPTED, which might or might not be better.)
.  if !empty(_BDB_ACCEPTED:M${_BDB_TYPE})
BDB_TYPE=	${_BDB_TYPE}
.  else
BDB_TYPE=	none
.  endif

# Define some public variables to refer to package-specific variables.
BDBBASE=	${BUILDLINK_PREFIX.${BDB_TYPE}}
BDB_LIBS=	${BUILDLINK_LDADD.${BDB_TYPE}}

BUILD_DEFS+=	BDB_TYPE
BUILD_DEFS+=	BDBBASE

.endif	# BDB_BUILDLINK3_MK

.if ${BDB_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_BDB_TYPE} is not an acceptable Berkeley DB type for ${PKGNAME}."
.elif ${BDB_TYPE} == "db1"
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ndb1}
BUILDLINK_PACKAGES+=		db1
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}db1
BUILDLINK_BUILTIN_MK.db1=	../../mk/db1.builtin.mk
.else
.  include "${_BDB_PKGSRCDIR.${BDB_TYPE}}/buildlink3.mk"
.endif
