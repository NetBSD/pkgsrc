# $NetBSD: terminfo.buildlink3.mk,v 1.4 2013/11/19 11:43:19 obache Exp $
#
# This Makefile fragment is meant to be included by packages that require
# any terminfo implementation instead of one particular one.  The available
# terminfo implementations are "terminfo" if built-in, "ncurses", and
# "pdcurses".
#
# If a package genuinely requires ncurses or pdcurses, then it should
# directly include the appropriate buildlink3.mk instead of this file in
# the package Makefile.
#
# === User-settable variables ===
#
# TERMINFO_DEFAULT
#	This value represents the type of terminfo we wish to use on the
#	system.  Setting this to "terminfo" means that the system terminfo
#	implementation is fine.
#
#	Possible: terminfo, ncurses, pdcurses
#	Default: (depends)
#
# === Variables set by this file ===
#
# TERMINFO_TYPE
#	The name of the selected terminfo implementation.

TERMINFO_BUILDLINK3_MK:=	${TERMINFO_BUILDLINK3_MK}+
.include "bsd.fast.prefs.mk"

.if !empty(TERMINFO_BUILDLINK3_MK:M+)

# _TERMINFO_PKGS is an exhaustive list of all of the terminfo implementations
# that may be used with terminfo.buildlink3.mk.
#
_TERMINFO_PKGS?=		terminfo ncurses pdcurses
_TERMINFO_TYPES?=		terminfo tinfo

CHECK_BUILTIN.terminfo:=	yes
.  include "terminfo.builtin.mk"
CHECK_BUILTIN.terminfo:=	no

# Set the value of TERMINFO_DEFAULT depending on the platform and what's
# available in the base system.
#
.if defined(USE_BUILTIN.terminfo) && !empty(USE_BUILTIN.terminfo:M[yY][eE][sS])
TERMINFO_DEFAULT?=	terminfo
.else
TERMINFO_DEFAULT?=	ncurses
.endif

_TERMINFO_ACCEPTED=	# empty
.if defined(USE_BUILTIN.terminfo) && !empty(USE_BUILTIN.terminfo:M[yY][eE][sS])
_TERMINFO_ACCEPTED+=	terminfo	# system terminfo exists
.endif
_TERMINFO_ACCEPTED+=	ncurses		# pkgsrc ncurses
_TERMINFO_ACCEPTED+=	pdcurses	# pkgsrc pdcurses

_TERMINFO_TYPE=		${TERMINFO_DEFAULT}
.  if !empty(_TERMINFO_ACCEPTED:M${_TERMINFO_TYPE})
TERMINFO_TYPE=		${_TERMINFO_TYPE}
.  else
TERMINFO_TYPE=		none
.  endif

BUILD_DEFS+=		TERMINFO_DEFAULT
BUILD_DEFS_EFFECTS+=	TERMINFO_TYPE

# Most GNU configure scripts will try finding every terminfo implementation,
# so prevent them from finding any except for the one we decide upon.
#
# There is special handling for packages that can be provided by pkgsrc,
# e.g. curses -- see terminfo.builtin.mk for details.
#
.if empty(TERMINFO_TYPE:Mnone)
.  for _tcap_ in ${_TERMINFO_TYPES}
.    if empty(TERMINFO_TYPE:M${_tcap_})
BUILDLINK_TRANSFORM+=		l:${_tcap_}:${BUILDLINK_LIBNAME.terminfo}
.    endif
.  endfor
.endif

.endif	# TERMINFO_BUILDLINK3_MK

.if ${TERMINFO_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_TERMINFO_TYPE} is not an acceptable terminfo type for ${PKGNAME}."
.elif ${TERMINFO_TYPE} == "terminfo"
BUILDLINK_TREE+=		terminfo -terminfo
BUILDLINK_LIBNAME.terminfo?=	${BUILTIN_LIBNAME.terminfo}
BUILDLINK_LDADD.terminfo?=	${BUILDLINK_LIBNAME.terminfo:S/^/-l/:S/^-l$//}
BUILDLINK_BUILTIN_MK.terminfo=	../../mk/terminfo.builtin.mk
.elif ${TERMINFO_TYPE} == "ncurses"
USE_NCURSES=			yes
.  include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_PREFIX.terminfo?=	${BUILDLINK_PREFIX.ncurses}
BUILDLINK_LIBNAME.terminfo?=	${BUILDLINK_LIBNAME.ncurses}
BUILDLINK_LDADD.terminfo?=	${BUILDLINK_LDADD.ncurses}
.elif ${TERMINFO_TYPE} == "pdcurses"
.  include "../../devel/pdcurses/buildlink3.mk"
BUILDLINK_PREFIX.terminfo?=	${BUILDLINK_PREFIX.pdcurses}
BUILDLINK_LIBNAME.terminfo?=	${BUILDLINK_LIBNAME.pdcurses}
BUILDLINK_LDADD.terminfo?=	${BUILDLINK_LDADD.pdcurses}
.endif
