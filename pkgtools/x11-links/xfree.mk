# $NetBSD: xfree.mk,v 1.4 2003/09/28 12:45:04 jlam Exp $

FILES_LIST=	${FILESDIR}/xfree

X11_MODULES=	MesaLib Xrender freetype2 glu xpm

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base XFree86 or not.
#
.for _module_ in ${X11_MODULES}
BUILDLINK_CHECK_BUILTIN.${_module_}=	YES
.endfor

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.for _module_ in ${X11_MODULES}
.  if !empty(BUILDLINK_IS_BUILTIN.${_module_}:M[yY][eE][sS])
FILES_LIST+=	${FILESDIR}/xfree.${_module_}
.  endif
.endfor
