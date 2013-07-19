# $NetBSD: readline.buildlink3.mk,v 1.3 2013/07/19 14:35:37 ryoon Exp $
#
# This Makefile fragment is meant to be included by packages that require
# any readline implementation instead of one particular one.  The available
# readline/editline implementations are "editline" and "readline".
#
# If a package genuinely requires editline or readline, then it should
# directly include the appropriate buildlink3.mk instead of this file in
# the package Makefile.
#
# === User-settable variables ===
#
# READLINE_DEFAULT
#	This value represents the type of readline we wish to use on the
#	system.  Setting this to "editline" means that the system libedit
#	implementation is fine or pkgsrc "editline" should be used.
#
#	Possible: editline readline
#	Default: (depends)
#
# === Variables set by this file ===
#
# READLINE_TYPE
#	The name of the selected readline implementation, editline or
#	readline.

EDITLINEREADLINE_BUILDLINK3_MK:=	${EDITLINEREADLINE_BUILDLINK3_MK}+
.include "bsd.fast.prefs.mk"

.if !empty(EDITLINEREADLINE_BUILDLINK3_MK:M+)

# _READLINE_PKGS is an exhaustive list of all of the readline implementations
# that may be used with readline.buildlink3.mk.
#
_READLINE_PKGS?=	editline readline

CHECK_BUILTIN.editlinereadline:=	yes
.include "readline.builtin.mk"
CHECK_BUILTIN.editlinereadline:=	no

# Set the value of READLINE_DEFAULT depending on the platform and what's
# available in the base system.
#
.if defined(IS_BUILTIN.editline) && \
	!empty(IS_BUILTIN.editline:M[Yy][Ee][Ss])
READLINE_DEFAULT?=	editline
.elif defined(IS_BUILTIN.readline) && \
	!empty(IS_BUILTIN.readline:M[Yy][Ee][Ss])
READLINE_DEFAULT?=	readline
.else
READLINE_DEFAULT?=	editline
.endif


_READLINE_ACCEPTED=	${_READLINE_PKGS} # both are provided by pkgsrc.

_READLINE_TYPE=		${READLINE_DEFAULT}
.  if !empty(_READLINE_ACCEPTED:M${_READLINE_TYPE})
READLINE_TYPE=		${_READLINE_TYPE}
.  else
READLINE_TYPE=		none
.  endif

BUILD_DEFS+=		READLINE_DEFAULT
BUILD_DEFS_EFFECTS+=	READLINE_TYPE

# _PKG_USE_READLINE is a flag for use by the readline packages' buildlink3.mk
# files to indicate that the headers and libraries should be usable as
# <readline.h> etc. and -lreadline etc.
#
_PKG_USE_READLINE=	yes

.endif	# EDITLINEREADLINE_BUILDLINK3_MK

.if ${READLINE_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_READLINE_TYPE} is not an acceptable readline type for ${PKGNAME}."
.elif ${READLINE_TYPE} == "editline"
.  include "../../devel/editline/buildlink3.mk"
BUILDLINK_PREFIX.editlinereadline?=	${BUILDLINK_PREFIX.editline}
BUILDLINK_LIBNAME.editlinereadline?=	${BUILDLINK_LIBNAME.editline}
BUILDLINK_LDADD.editlinereadline?=	${BUILDLINK_LDADD.editline}
.elif ${READLINE_TYPE} == "readline"
.  include "../../devel/readline/buildlink3.mk"
BUILDLINK_PREFIX.editlinereadline?=	${BUILDLINK_PREFIX.readline}
BUILDLINK_LIBNAME.editlinereadline?=	${BUILDLINK_LIBNAME.readline}
BUILDLINK_LDADD.editlinereadline?=	${BUILDLINK_LDADD.readline}
.endif
