# $NetBSD: xorg.mk,v 1.2 2005/10/16 08:57:30 seb Exp $
#
# This is for X.org, but use "xfree" files also.

FILES_LIST=	${FILESDIR}/xorg

# libXdamage and damageext only in pkgsrc-wip so not used here
# XXX: what about xaw?

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../x11/Xcomposite/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/renderext/buildlink3.mk"
.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

# XXX  what is ${X11_MODULES} ?

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base Xorg or not.
#
# XXX: maybe skip iconv and zlib too?
.for _pkg_ in ${BUILDLINK_PACKAGES:Nx11-links}
CHECK_BUILTIN.${_pkg_}:=	yes
USE_BUILTIN.${_pkg_}=		yes
.  sinclude "${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk"
CHECK_BUILTIN.${_pkg_}:=	no
.endfor

.for _pkg_ in ${BUILDLINK_PACKAGES:Nx11-links}
IGNORE_PKG.${_pkg_}=	yes
.  if !empty(IS_BUILTIN.${_pkg_}:M[yY][eE][sS])
.    if exists(${FILESDIR}/xorg.${_pkg_})
FILES_LIST+=	${FILESDIR}/xorg.${_pkg_}
.    elif exists(${FILESDIR}/xfree.${_pkg_})
FILES_LIST+=	${FILESDIR}/xfree.${_pkg_}
.    endif
.  endif
.endfor
