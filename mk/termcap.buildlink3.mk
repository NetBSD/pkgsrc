# $NetBSD: termcap.buildlink3.mk,v 1.10 2013/10/19 19:12:41 roy Exp $
#
# This Makefile fragment is meant to be included by packages that require
# a termcap implementation that supports the basic termcap functions:
#
#	tgetent, tgetstr, tgetflag, tgetnum, tgoto, tputs
#
# === Variables set by this file ===
#
# TERMCAP_TYPE
#	The name of the selected termcap implementation.

TERMCAP_BUILDLINK3_MK:=	${TERMCAP_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(TERMCAP_BUILDLINK3_MK:M+)

# _TERMCAP_TYPES is an exhaustive list of all of the termcap
#	implementations that may be found.
#
_TERMCAP_TYPES?=	terminfo curses termcap termlib tinfo

CHECK_BUILTIN.termcap:=	yes
.  include "termcap.builtin.mk"
CHECK_BUILTIN.termcap:=	no

.if !empty(USE_BUILTIN.termcap:M[yY][eE][sS])
.  if defined(BUILTIN_LIBNAME.termcap)
TERMCAP_TYPE=	${BUILTIN_LIBNAME.termcap}
.  else
TERMCAP_TYPE=	none
.  endif
.else
TERMCAP_TYPE=	curses		# pkgsrc termcap is curses
.endif
BUILD_DEFS_EFFECTS+=	TERMCAP_TYPE

# Most GNU configure scripts will try finding every termcap implementation,
# so prevent them from finding any except for the one we decide upon.
#
# There is special handling for packages that can be provided by pkgsrc,
# e.g. curses -- see termcap.builtin.mk for details.
#
.  for _tcap_ in ${_TERMCAP_TYPES:Ntermcap:Ncurses}
.    if empty(TERMCAP_TYPE:M${_tcap_}) \
	&& (!defined(TERMINFO_TYPE) || empty(TERMINFO_TYPE:M${_tcap_})) \
	&& (!defined(CURSES_TYPE) || empty(CURSES_TYPE:M${_tcap_}))
BUILDLINK_TRANSFORM+=		rm:-l${_tcap_}
.    endif
.  endfor
BUILDLINK_TRANSFORM+=		l:termcap:${BUILDLINK_LIBNAME.termcap}

.endif	# TERMCAP_BUILDLINK3_MK

.if ${TERMCAP_TYPE} == "none"
PKG_FAIL_REASON=	"No usable termcap library found on the system."
.elif (${TERMCAP_TYPE} == "terminfo") || \
      (${TERMCAP_TYPE} == "termlib") || \
      (${TERMCAP_TYPE} == "termcap") || \
      (${TERMCAP_TYPE} == "tinfo")
BUILDLINK_TREE+=		termcap -termcap
BUILDLINK_LIBNAME.termcap?=	${BUILTIN_LIBNAME.termcap}
BUILDLINK_LDADD.termcap?=	${BUILDLINK_LIBNAME.termcap:S/^/-l/:S/^-l$//}
BUILDLINK_BUILTIN_MK.termcap=	../../mk/termcap.builtin.mk
.elif ${TERMCAP_TYPE} == "curses"
.  include "../../mk/curses.buildlink3.mk"
BUILDLINK_PREFIX.termcap?=	${BUILDLINK_PREFIX.curses}
BUILDLINK_LIBNAME.termcap?=	${BUILDLINK_LIBNAME.curses}
BUILDLINK_LDADD.termcap?=	${BUILDLINK_LDADD.curses}
.endif
