# $NetBSD: xfree.mk,v 1.16 2009/03/20 19:25:13 joerg Exp $

FILES_LIST=	${FILESDIR}/xfree

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base XFree86 or not.
#
.for _pkg_ in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
CHECK_BUILTIN.${_pkg_}:=	yes
USE_BUILTIN.${_pkg_}=		yes
.  sinclude "${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk"
CHECK_BUILTIN.${_pkg_}:=	no
.endfor

.for _pkg_ in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
IGNORE_PKG.${_pkg_}=	yes
.  if (defined(IS_BUILTIN.${_pkg_}) && !empty(IS_BUILTIN.${_pkg_}:M[yY][eE][sS]) ) && \
      exists(${FILESDIR}/xfree.${_pkg_})
FILES_LIST+=	${FILESDIR}/xfree.${_pkg_}
.  endif
.endfor
