# $NetBSD: builtin.mk,v 1.4 2004/03/30 17:04:06 jlam Exp $

.if !defined(XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
XF86_VERSION=  3.3
.  if !exists(${_X11_CONFIG_VERSION_DEF})
XF86_VERSION=	0
.  else
_XF86_MAJOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MAJOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_MINOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MINOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_PATCH!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_PATCH/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_SNAP!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_SNAP/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_TEENY=	${_XF86_PATCH}.${_XF86_SNAP}
.    if !empty(_XF86_TEENY:M0.0)
XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}
.    else
XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}.${_XF86_TEENY}
.    endif
.  endif
BUILDLINK_VARS+=	XF86_VERSION
.endif

USE_BUILTIN.x11-links?=	no

# Xrandr won't build without the X Extension library which is only present
# in XFree86>=4.3; ignore it when checking dependencies or buildlinking.
#
.if !exists(${X11BASE}/include/X11/extensions/extutil.h)
IGNORE_PKG.Xrandr=	yes
IGNORE_PKG.randrext=	yes
.endif
