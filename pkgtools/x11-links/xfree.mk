# $NetBSD: xfree.mk,v 1.9 2004/03/11 00:47:01 jlam Exp $

FILES_LIST=	${FILESDIR}/xfree

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

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base XFree86 or not.
#
.for _module_ in ${BUILDLINK_PACKAGES}
CHECK_BUILTIN.${_module_}=	yes
.  if exists(${BUILDLINK_PKGSRCDIR.${_module_}}/builtin.mk)
.    include "${BUILDLINK_PKGSRCDIR.${_module_}}/builtin.mk"
.    if !empty(IS_BUILTIN.${_module_}:M[yY][eE][sS]) && \
        exists(${FILESDIR}/xfree.${_module_})
FILES_LIST+=	${FILESDIR}/xfree.${_module_}
.    endif
.  endif
.endfor
