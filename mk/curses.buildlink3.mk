# $NetBSD: curses.buildlink3.mk,v 1.27 2018/08/18 00:14:39 ryoon Exp $
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
#	Possible: curses, ncurses, ncursesw, pdcurses
#	Default: (depends)
#
# === Package-settable variables ===
#
# USE_CURSES
#	This value represents the features the package needs from curses.
#	If the system curses does not provide those features, then
#	a more suitable curses is pulled in (normally ncurses).
#
#	Possible: wide
#	For more possible values, see curses.builtin.mk.
#	Default: (unset)
#
# FAKE_NCURSES
#	Some packages look exclusively for ncurses or ncursesw,
#	headers and libraries. This really is an error with the package,
#	but patching it can be both challenging and cumbersome.
#	Set this to YES to transform these to system curses.
#
#	Possible: YES, NO
#	Default: NO
#
# INCOMPAT_CURSES
#	If no test exists the missing curses feature then set this
#	to match the platform where system curses isn't suitable.
#	This can include the case where the system curses compiles fine,
#	but for some reason fails to work.
#
#	Default: (unset)
#
# === Variables set by this file ===
#
# CURSES_TYPE
#	The name of the selected curses implementation.

CURSES_BUILDLINK3_MK:=	${CURSES_BUILDlINK3_MK}+
.include "bsd.fast.prefs.mk"

.if !empty(CURSES_BUILDLINK3_MK:M+)

.if !defined(USE_CURSES) && !empty(PKG_OPTIONS:Mwide-curses)
USE_CURSES?=		wide
.endif

# _CURSES_PKGS is an exhaustive list of all of the curses implementations
# that may be used with curses.buildlink3.mk.
#
_CURSES_PKGS?=		curses ncurses ncursesw pdcurses

CHECK_BUILTIN.curses:=	yes
.  include "curses.builtin.mk"
CHECK_BUILTIN.curses:=	no

# Set the value of CURSES_DEFAULT depending on the platform and what's
# available in the base system.
#
.if defined(USE_BUILTIN.curses) && !empty(USE_BUILTIN.curses:M[yY][eE][sS])
CURSES_DEFAULT?=	curses
.elif !empty(USE_CURSES:U:Mwide) || !empty(PKG_OPTIONS:U:Mwide-curses)
CURSES_DEFAULT?=	ncursesw
.else
CURSES_DEFAULT?=	ncurses
.endif

_CURSES_ACCEPTED=	# empty
.if defined(USE_BUILTIN.curses) && !empty(USE_BUILTIN.curses:M[yY][eE][sS])
_CURSES_ACCEPTED+=	curses		# system curses exists
.endif
.if defined(USE_BUILTIN.cursesw) && !empty(USE_BUILTIN.cursesw:M[yY][eE][sS])
_CURSES_ACCEPTED+=	curses		# system curses exists
.endif
_CURSES_ACCEPTED+=	ncurses		# pkgsrc ncurses
_CURSES_ACCEPTED+=	ncursesw	# pkgsrc ncursesw
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

.PHONY: buildlink-curses-ncurses-h
buildlink-curses-ncurses-h:
	${RUN}								\
	src="${H_CURSES}";						\
	dest=${BUILDLINK_DIR}"/include/ncurses.h";			\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		${ECHO_BUILDLINK_MSG} "Linking ${H_CURSES} -> ncurses.h.";\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi


.endif	# CURSES_BUILDLINK3_MK

.if ${CURSES_TYPE} == "none"
PKG_FAIL_REASON+=	\
	"${_CURSES_TYPE} is not an acceptable curses type for ${PKGNAME}."
.elif ${CURSES_TYPE} == "curses"
.  include "curses.builtin.mk"
BUILDLINK_TREE+=		curses -curses
BUILDLINK_LDADD.curses?=	${BUILDLINK_LIBNAME.curses:S/^/-l/:S/^-l$//}
BUILDLINK_BUILTIN_MK.curses=	../../mk/curses.builtin.mk
.else
.  if ${CURSES_TYPE} == "ncurses"
USE_NCURSES=			yes
.    include "../../devel/ncurses/buildlink3.mk"
.  elif ${CURSES_TYPE} == "ncursesw"
.    include "../../devel/ncursesw/buildlink3.mk"
.  elif ${CURSES_TYPE} == "pdcurses"
.    include "../../devel/pdcurses/buildlink3.mk"
.  endif
.  for _var_ in PKGNAME PREFIX INCDIRS LIBDIRS LIBNAME LDADD
BUILDLINK_${_var_}.curses=	${BUILDLINK_${_var_}.${CURSES_TYPE}}
.  endfor
.endif

# Some packages only look for ncurses
# The correct action would be to write a patch and pass it upstream
# but by setting FAKE_NCURSES=yes in the package we can temporarily work
# around the short-coming.
.if defined(FAKE_NCURSES) && !empty(FAKE_NCURSES:M[yY][eE][sS])
.  if ${CURSES_TYPE} != "ncurses"
.    if ${CURSES_TYPE} != "ncursesw"
BUILDLINK_TARGETS+=		buildlink-curses-ncurses-h
BUILDLINK_TRANSFORM+=		l:ncursesw:${BUILDLINK_LIBNAME.curses}
.    endif
BUILDLINK_TRANSFORM+=		l:ncurses:${BUILDLINK_LIBNAME.curses}
.  endif
.endif
