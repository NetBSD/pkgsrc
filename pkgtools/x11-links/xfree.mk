# $NetBSD: xfree.mk,v 1.7 2004/02/17 16:50:26 jlam Exp $

FILES_LIST=	${FILESDIR}/xfree

X11_MODULES=	MesaLib glu
X11_MODULES+=	freetype2
X11_MODULES+=	xpm
X11_MODULES+=	Xft2 Xrender expat fontconfig render
X11_MODULES+=	Xrandr randrext
X11_MODULES+=	xcursor

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base XFree86 or not.
#
.for _module_ in ${X11_MODULES}
BUILDLINK_CHECK_BUILTIN.${_module_}=	YES
.endfor

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/render/buildlink3.mk"
.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.for _module_ in ${X11_MODULES}
.  if !empty(BUILDLINK_IS_BUILTIN.${_module_}:M[yY][eE][sS])
FILES_LIST+=	${FILESDIR}/xfree.${_module_}
.  endif
.endfor
