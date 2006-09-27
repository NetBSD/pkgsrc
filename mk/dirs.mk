# $NetBSD: dirs.mk,v 1.8 2006/09/27 15:18:15 joerg Exp $
#

.if !defined(DIRS_MK)
DIRS_MK=		# defined

_USE_GNOME1_DIRS=	# empty
_USE_GNOME2_DIRS=	# empty
_USE_TEXMF_DIRS=	# empty
_USE_THEME_DIRS=	# empty
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
.  elif ${pkg} == "texmf" && ${_USE_TEXMF_DIRS} < ${ver}
_USE_TEXMF_DIRS:=	${ver}
.  elif ${pkg} == "theme" && ${_USE_THEME_DIRS} < ${ver}
_USE_THEME_DIRS:=	${ver}
.  elif ${pkg} == "xdg" && ${_USE_XDG_DIRS} < ${ver} && !defined(USE_X11BASE)
_USE_XDG_DIRS:=		${ver}
.  elif ${pkg} == "xdg-x11" && ${_USE_XDG_X11_DIRS} < ${ver} && \
	defined(USE_X11BASE)
_USE_XDG_X11_DIRS:=	${ver}
.  elif ${pkg} == "xorg" && ${_USE_XORG_DIRS} < ${ver}
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

.if !empty(_USE_TEXMF_DIRS)
.  include "../../print/texmf-dirs/dirs.mk"
.endif

.if !empty(_USE_THEME_DIRS)
.  include "../../misc/theme-dirs/dirs.mk"
.endif

.if !empty(_USE_XDG_DIRS)
.  include "../../misc/xdg-dirs/dirs.mk"
.endif

.if !empty(_USE_XDG_X11_DIRS)
.  include "../../misc/xdg-x11-dirs/dirs.mk"
.endif

.if !empty(_USE_XORG_DIRS)
.  include "../../misc/xorg-dirs/dirs.mk"
.endif

.endif # !defined(DIRS_MK)
