# $NetBSD: xfree.mk,v 1.10 2004/03/29 05:43:32 jlam Exp $

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
.for _pkg_ in ${BUILDLINK_PACKAGES}
CHECK_BUILTIN.${_pkg_}=	yes
USE_BUILTIN.${_pkg_}=	yes
.endfor
.include "../../mk/buildlink3/bsd.builtin.mk"

.for _pkg_ in ${BUILDLINK_PACKAGES}
IGNORE_PKG.${_pkg_}=	yes
.  if !empty(IS_BUILTIN.${_pkg_}:M[yY][eE][sS]) && \
      exists(${FILESDIR}/xfree.${_pkg_})
FILES_LIST+=	${FILESDIR}/xfree.${_pkg_}
.  endif
.endfor
