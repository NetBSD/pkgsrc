# $NetBSD: xfree.mk,v 1.17 2016/07/10 13:28:41 rillig Exp $

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
.for pkg in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
CHECK_BUILTIN.${pkg}:=	yes
USE_BUILTIN.${pkg}=		yes
.  sinclude "${BUILDLINK_PKGSRCDIR.${pkg}}/builtin.mk"
CHECK_BUILTIN.${pkg}:=	no
.endfor

.for pkg in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
IGNORE_PKG.${pkg}=	yes
.  if (defined(IS_BUILTIN.${pkg}) && !empty(IS_BUILTIN.${pkg}:M[yY][eE][sS]) ) && \
      exists(${FILESDIR}/xfree.${pkg})
FILES_LIST+=	${FILESDIR}/xfree.${pkg}
.  endif
.endfor
