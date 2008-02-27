# $NetBSD: termlib.buildlink3.mk,v 1.2 2008/02/27 06:10:25 jlam Exp $
#
# This Makefile fragment is meant to be included by packages that require
# a basic termlib implementation.
#
# === Variables set by this file ===
#
# TERMLIB_TYPE
#	The name of the selected termlib implementation.

TERMLIB_BUILDLINK3_MK:=	${TERMLIB_BUILDLINK3_MK}+

.include "bsd.fast.prefs.mk"

.if !empty(TERMLIB_BUILDLINK3_MK:M+)

CHECK_BUILTIN.termlib:=	yes
.  include "termlib.builtin.mk"
CHECK_BUILTIN.termlib:=	no

.  if !empty(USE_BUILTIN.termlib:M[yY][eE][sS])
.    if defined(BUILTIN_LIBNAME.termlib)
TERMLIB_TYPE=	${BUILTIN_LIBNAME.termlib}
.    else
TERMLIB_TYPE=	none
.    endif
.  else
TERMLIB_TYPE=	curses
.  endif

BUILD_DEFS+=	TERMLIB_TYPE

.endif	# TERMLIB_BUILDLINK3_MK

.if ${TERMLIB_TYPE} == "none"
PKG_FAIL_REASON=	"No usable terminal library found on the system."
.elif (${TERMLIB_TYPE} == "termcap")
BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ntermlib}
BUILDLINK_PACKAGES+=		termlib
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}termlib
BUILDLINK_LIBNAME.termlib?=	termcap
BUILDLINK_LDADD.termlib?=	${BUILDLINK_LIBNAME.termlib:S/^/-l/}
BUILDLINK_BUILTIN_MK.termlib=	../../mk/termlib.builtin.mk
.elif ${TERMLIB_TYPE} == "curses"
.  include "../../mk/curses.buildlink3.mk"
BUILDLINK_LIBNAME.termlib?=	${BUILDLINK_LIBNAME.curses}
BUILDLINK_LDADD.termlib?=	${BUILDLINK_LDADD.curses}
.endif
