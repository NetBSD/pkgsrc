# $NetBSD: curses.buildlink3.mk,v 1.33 2024/05/06 08:27:54 jperkin Exp $
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
# User-settable variables:
#
# CURSES_DEFAULT
#	This value represents the type of curses we wish to use on the
#	system.  Setting this to "curses" means that the system curses
#	implementation is fine.
#
#	Possible: curses, ncurses, pdcurses
#	Default: (depends)
#
# Package-settable variables:
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
#	Some packages look exclusively for ncurses headers and libraries.
#	This really is an error with the package, but patching it can be
#	both challenging and cumbersome.  Set this to YES to transform
#	these to system curses.
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
# System-defined variables:
#
# CURSES_TYPE
#	The name of the selected curses implementation.

CURSES_BUILDLINK3_MK:=	${CURSES_BUILDLINK3_MK}+
.include "bsd.fast.prefs.mk"

.if !empty(CURSES_BUILDLINK3_MK:M+)

.if !defined(USE_CURSES) && !empty(PKG_OPTIONS:Mwide-curses)
USE_CURSES?=		wide
.endif

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
.if defined(USE_BUILTIN.cursesw) && !empty(USE_BUILTIN.cursesw:M[yY][eE][sS])
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
.    include "../devel/ncurses/buildlink3.mk"
.  elif ${CURSES_TYPE} == "pdcurses"
.    include "../devel/pdcurses/buildlink3.mk"
.  endif
.  for var in BUILDLINK_PKGNAME BUILDLINK_PREFIX BUILDLINK_INCDIRS \
	      BUILDLINK_LIBDIRS BUILDLINK_LIBNAME BUILDLINK_LDADD
${var}.curses=			${${var}.${CURSES_TYPE}}
.  endfor
.endif

# Some packages only look for ncurses
# The correct action would be to write a patch and pass it upstream
# but by setting FAKE_NCURSES=yes in the package we can temporarily work
# around the short-coming.
.if defined(FAKE_NCURSES) && !empty(FAKE_NCURSES:M[yY][eE][sS])
.  if ${CURSES_TYPE} != "ncurses"
BUILDLINK_TARGETS+=		buildlink-curses-ncurses-h
BUILDLINK_TRANSFORM+=		l:ncursesw:${BUILDLINK_LIBNAME.curses}
BUILDLINK_TRANSFORM+=		l:ncurses:${BUILDLINK_LIBNAME.curses}
.  endif
.endif

_VARGROUPS+=		curses
_USER_VARS.curses=	CURSES_DEFAULT
_PKG_VARS.curses=	FAKE_NCURSES USE_CURSES
_SYS_VARS.curses=	PKG_OPTIONS CURSES_TYPE BUILDLINK_BUILTIN_MK.curses \
			BUILDLINK_PKGNAME.curses \
			BUILDLINK_PREFIX.curses BUILDLINK_INCDIRS.curses \
			BUILDLINK_LIBDIRS.curses BUILDLINK_LIBNAME.curses \
			BUILDLINK_LDADD.curses
_USE_VARS.curses=	USE_BUILTIN.curses USE_BUILTIN.cursesw
_DEF_VARS.curses=	USE_CURSES _CURSES_PKGS CHECK_BUILTIN.curses \
			_CURSES_ACCEPTED _CURSES_TYPE _PKG_USE_CURSES \
			H_CURSES BUILDLINK_TARGETS BUILDLINK_TRANSFORM
