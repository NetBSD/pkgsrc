# $NetBSD: curses.buildlink3.mk,v 1.15 2010/02/07 09:46:13 roy Exp $
#
# This Makefile fragment is meant to be included by packages that require
# any curses implementation instead of one particular one.  The available
# curses implementations are "curses" if built-in, "ncurses", and
# "pdcurses".
#
# If a package genuinely requires ncurses or pdcurses, then it should
# directly include the appropriate buildlink3.mk instead of this file in
# the package Makefile.
#
# === User-settable variables ===
#
# CURSES_DEFAULT
#	This value represents the type of curses we wish to use on the
#	system.  Setting this to "curses" means that the system curses
#	implementation is fine.
#
#	Possible: curses, ncurses, pdcurses
#	Default: (depends)
#
# === Variables set by this file ===
#
# CURSES_TYPE
#	The name of the selected curses implementation.

CURSES_BUILDLINK3_MK:=	${CURSES_BUILDLINK3_MK}+
.include "bsd.fast.prefs.mk"

.if !empty(CURSES_BUILDLINK3_MK:M+)

# _CURSES_PKGS is an exhaustive list of all of the curses implementations
# that may be used with curses.buildlink3.mk.
#
_CURSES_PKGS?=		curses ncurses pdcurses

CHECK_BUILTIN.curses:=	yes
.  include "curses.builtin.mk"
CHECK_BUILTIN.curses:=	no

# Set the value of CURSES_DEFAULT depending on the platform and what's
# available in the base system.
#
.if defined(USE_BUILTIN.curses) && !empty(USE_BUILTIN.curses:M[yY][eE][sS])
CURSES_DEFAULT?=	curses
.else
CURSES_DEFAULT?=	ncurses
.endif

_CURSES_ACCEPTED=	# empty
.if defined(USE_BUILTIN.curses) && !empty(USE_BUILTIN.curses:M[yY][eE][sS])
_CURSES_ACCEPTED+=	curses		# system curses exists
.endif
_CURSES_ACCEPTED+=	ncurses		# pkgsrc ncurses
_CURSES_ACCEPTED+=	pdcurses	# pkgsrc pdcurses

_CURSES_TYPE=		${CURSES_DEFAULT}
.  if !empty(_CURSES_ACCEPTED:M${_CURSES_TYPE})
CURSES_TYPE=		${_CURSES_TYPE}
.  else
CURSES_TYPE=		none
.  endif

BUILD_DEFS+=		CURSES_DEFAULT
BUILD_DEFS_EFFECTS+=	CURSES_TYPE

# _PKG_USE_CURSES is a flag for use by the curses packages' buildlink3.mk
# files to indicate that the headers and libraries should be usable as
# <curses.h> and -lcurses.
#
_PKG_USE_CURSES=	yes

.endif	# CURSES_BUILDLINK3_MK

.if ${CURSES_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_CURSES_TYPE} is not an acceptable curses type for ${PKGNAME}."
.elif ${CURSES_TYPE} == "curses"
BUILDLINK_TREE+=		curses -curses
BUILDLINK_LDADD.curses?=	${BUILDLINK_LIBNAME.curses:S/^/-l/:S/^-l$//}
BUILDLINK_BUILTIN_MK.curses=	../../mk/curses.builtin.mk
.elif ${CURSES_TYPE} == "ncurses"
daaaaa
USE_NCURSES=			yes
.  include "../../devel/ncurses/buildlink3.mkxx"
BUILDLINK_PREFIX.curses?=	${BUILDLINK_PREFIX.ncurses}
BUILDLINK_LIBNAME.curses?=	${BUILDLINK_LIBNAME.ncurses}
BUILDLINK_LDADD.curses?=	${BUILDLINK_LDADD.ncurses}
.elif ${CURSES_TYPE} == "pdcurses"
.  include "../../devel/pdcurses/buildlink3.mk"
BUILDLINK_PREFIX.curses?=	${BUILDLINK_PREFIX.pdcurses}
BUILDLINK_LIBNAME.curses?=	${BUILDLINK_LIBNAME.pdcurses}
BUILDLINK_LDADD.curses?=	${BUILDLINK_LDADD.pdcurses}
.endif
