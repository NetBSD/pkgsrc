# $NetBSD: termcap.buildlink3.mk,v 1.1 2008/02/29 22:41:13 jlam Exp $
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

CHECK_BUILTIN.termcap:=	yes
.  include "termcap.builtin.mk"
CHECK_BUILTIN.termcap:=	no

.  if !empty(USE_BUILTIN.termcap:M[yY][eE][sS])
.    if defined(BUILTIN_LIBNAME.termcap)
TERMCAP_TYPE=	${BUILTIN_LIBNAME.termcap}
.    else
TERMCAP_TYPE=	none
.    endif
.  else
TERMCAP_TYPE=	curses
.  endif

BUILD_DEFS+=	TERMCAP_TYPE

.endif	# TERMCAP_BUILDLINK3_MK

.if ${TERMCAP_TYPE} == "none"
PKG_FAIL_REASON=	"No usable termcap library found on the system."
.elif (${TERMCAP_TYPE} == "termcap") || \
      (${TERMCAP_TYPE} == "tinfo")
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ntermcap}
BUILDLINK_PACKAGES+=		termcap
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}termcap
BUILDLINK_LIBNAME.termcap?=	${BUILTIN_LIBNAME.termcap}
BUILDLINK_LDADD.termcap?=	${BUILDLINK_LIBNAME.termcap:S/^/-l/:S/^-l$//}
BUILDLINK_BUILTIN_MK.termcap=	../../mk/termcap.builtin.mk
.elif ${TERMCAP_TYPE} == "curses"
.  include "../../mk/curses.buildlink3.mk"
BUILDLINK_PREFIX.termcap?=	${BUILDLINK_PREFIX.curses}
BUILDLINK_LIBNAME.termcap?=	${BUILDLINK_LIBNAME.curses}
BUILDLINK_LDADD.termcap?=	${BUILDLINK_LDADD.curses}
.endif
