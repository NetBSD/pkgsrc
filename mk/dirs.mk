# $NetBSD: dirs.mk,v 1.4 2004/07/29 07:27:43 xtraeme Exp $
#

.if !defined(DIRS_MK)
DIRS_MK=		# defined

_USE_GNOME1_DIRS=	# empty
_USE_GNOME2_DIRS=	# empty
_USE_XDG_DIRS=		# empty
_USE_XDG_X11_DIRS=	# empty
_USE_XFREE86_DIRS=	# empty
_USE_XORG_DIRS=		# empty

.for dir in ${USE_DIRS}
pkg:=			${dir:C/-[^-]*$//}
ver:=			${dir:C/^.*-//}

.  if ${pkg} == "gnome1" && ${_USE_GNOME1_DIRS} < ${ver}
_USE_GNOME1_DIRS:=	${ver}
.  elif ${pkg} == "gnome2" && ${_USE_GNOME2_DIRS} < ${ver}
_USE_GNOME2_DIRS:=	${ver}
.  elif ${pkg} == "xdg" && ${_USE_XDG_DIRS} < ${ver} && !defined(USE_X11BASE)
_USE_XDG_DIRS:=		${ver}
.  elif ${pkg} == "xdg" && ${_USE_XDG_X11_DIRS} < ${ver} && defined(USE_X11BASE)
_USE_XDG_X11_DIRS:=	${ver}
.  elif ${pkg} == "xdg" && ${_USE_XFREE86_DIRS} < ${ver}
_USE_XFREE86_DIRS:=	${ver}
.  elif ${pkg} == "xdg" && ${_USE_XORG_DIRS} < ${ver}
_USE_XORG_DIRS:=	${ver}
.  endif

.endfor
.undef ver
.undef pkg
.undef dir

.if !empty(_USE_GNOME1_DIRS)
.  include "../../misc/gnome1-dirs/dirs.mk"
.endif

.if !empty(_USE_GNOME2_DIRS)
.  include "../../misc/gnome2-dirs/dirs.mk"
.endif

.if !empty(_USE_XDG_DIRS)
.  include "../../misc/xdg-dirs/dirs.mk"
.endif

.if !empty(_USE_XDG_X11_DIRS)
.  include "../../misc/xdg-x11-dirs/dirs.mk"
.endif

.if !empty(_USE_XFREE86_DIRS)
.  include "../../misc/XFree86-dirs/dirs.mk"
.endif

.if !empty(_USE_XORG_DIRS)
.  include "../../misc/xorg-dirs/dirs.mk"
.endif

.endif # !defined(DIRS_MK)
