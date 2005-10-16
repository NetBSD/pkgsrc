# $NetBSD: xfree.mk,v 1.12 2005/10/16 08:57:30 seb Exp $

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
.include "../../x11/renderext/buildlink3.mk"
.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base XFree86 or not.
#
.for _pkg_ in ${BUILDLINK_PACKAGES:Nx11-links}
CHECK_BUILTIN.${_pkg_}:=	yes
USE_BUILTIN.${_pkg_}=		yes
.  sinclude "${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk"
CHECK_BUILTIN.${_pkg_}:=	no
.endfor

.for _pkg_ in ${BUILDLINK_PACKAGES:Nx11-links}
IGNORE_PKG.${_pkg_}=	yes
.  if !empty(IS_BUILTIN.${_pkg_}:M[yY][eE][sS]) && \
      exists(${FILESDIR}/xfree.${_pkg_})
FILES_LIST+=	${FILESDIR}/xfree.${_pkg_}
.  endif
.endfor
