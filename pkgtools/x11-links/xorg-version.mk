# $NetBSD: xorg-version.mk,v 1.2.12.1 2013/01/24 10:40:07 spz Exp $
#
# This Makefile fragment is included by Makefiles that need to access
# the X11_TYPE and version number of an X.org distribution.
#
# The following variables are provided by this file:
#
#    BUILTIN_X11_TYPE.xorg is the X11_TYPE of the X.org distribution
#	and is simply "xorg".
#
#    BUILTIN_X11_VERSION.xorg is the version number of the X.org
#	distribution detected on the system.
#

BUILTIN_X11_TYPE.xorg=	xorg

BUILTIN_FIND_FILES_VAR:=		CF_XORG CF_XORG_VERSION CF_VERSION_OLD XQUARTZ
BUILTIN_FIND_FILES.CF_XORG=		${X11BASE}/lib/X11/config/xorg.cf
BUILTIN_FIND_FILES.CF_XORG_VERSION=	${X11BASE}/lib/X11/config/xorgversion.def
BUILTIN_FIND_FILES.CF_VERSION_OLD=	${X11BASE}/lib/X11/config/version.def
.include "../../mk/buildlink3/find-files.mk"

.if !defined(BUILTIN_XORG_VERSION_FILE)
BUILTIN_XORG_VERSION_FILE=	__nonexistent__
.  if exists(${CF_XORG_VERSION})
BUILTIN_XORG_VERSION_FILE=	${CF_XORG_VERSION}
.  elif exists(${CF_VERSION_OLD})
BUILTIN_XORG_VERSION_FILE=	${CF_VERSION_OLD}
.  endif
.endif
MAKEVARS+=	BUILTIN_XORG_VERSION_FILE

.if !defined(BUILTIN_X11_VERSION.xorg)
.  if exists(${BUILTIN_XORG_VERSION_FILE})
BUILTIN_X11_VERSION.xorg!=						\
	${AWK} '/\#define[ 	]*XORG_VERSION_MAJOR/ { M = $$3 }	\
		/\#define[ 	]*XORG_VERSION_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]*XORG_VERSION_PATCH/ { p = "."$$3 }	\
		/\#define[ 	]*XORG_VERSION_SNAP/ { s = "."$$3 }	\
		END { if (s == ".0") s = "";				\
		      if (p == ".0" && s == "") p = "";			\
		      printf "%s%s%s%s\n", M, m, p, s }'		\
		${BUILTIN_XORG_VERSION_FILE}
.  endif
.endif
MAKEVARS+=	BUILTIN_X11_VERSION.xorg
