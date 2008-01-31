# $NetBSD: bdb.buildlink3.mk,v 1.21 2008/01/31 12:45:08 rillig Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a Berkeley DB (BDB) implementation and that are not restricted
# to a single one. The available BDB implementations are db1
# (if builtin) and db[234].
#
# FIXME: This Makefile cannot handle packages that can use only a
# subset of { db2 db3 db4 }.
#
# === User-settable variables ===
#
# BDB_DEFAULT
#	This value represents the package we use when either a db-1.85
#	interface isn't required, or a db-1.85 interface is required,
#	but it's not built-in.
#
#	FIXME: Improve the wording of the text above so that one can
#	understand it.
#
#	Possible: db1 db2 db3 db4
#	Default: db4
#
# BDB185_DEFAULT
#	The package we use when a db-1.85 interface is required.
#	It defaults to "db1" if it's built-in, or to ${BDB_DEFAULT}
#	otherwise.
#
# === Package-settable variables ===
#
# BDB_ACCEPTED
#	The list of Berkeley DB implementations that can be used by the
#	package.
#
#	FIXME: If the list does not include db1 and does not include
#	BDB_DEFAULT, the package will not build at the moment.
#
# === Variables set by this file ===
#
# BDB_TYPE
#	The name of the selected BDB implementation.
#
# BDBBASE
#	The base directory of the selected BDB implementation. It has
#	subdirectories include/ and lib/.
#
# BDB_LIBS
#	Linker flags to link against the BDB library.

# Note for when databases/db1 is imported:
#   (1) Remove the section that conditionally sets the default
#	value for BDB185_DEFAULT and always set it to be "db1".
#   (2) Remove the special case for ${BDB_TYPE} == "db1" at the end.
#   (3) Move mk/db1.builtin.mk to databases/db1/builtin.mk.

BDB_BUILDLINK3_MK:=	${BDB_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

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
.  include "db1.builtin.mk"
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

BUILD_DEFS+=		BDB_DEFAULT BDB185_DEFAULT
BUILD_DEFS_EFFECTS+=	BDBBASE BDB_LIBS BDB_TYPE

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
