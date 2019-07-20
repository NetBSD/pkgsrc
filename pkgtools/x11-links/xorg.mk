# $NetBSD: xorg.mk,v 1.34 2019/07/20 21:09:48 wiz Exp $
#
# This is for X.org, but use "xfree" files also.

FILES_LIST=	${FILESDIR}/xorg

# XXX: what about xaw?

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../multimedia/libvdpau/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXevie/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXpresent/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

# XXX  what is ${X11_MODULES} ?

# Check if any headers and libraries for ${X11_MODULES} found in
# ${X11BASE} actually belong to the base Xorg or not.
#
# XXX: maybe skip iconv and zlib too?
.for pkg in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
CHECK_BUILTIN.${pkg}:=	yes
.  sinclude "${BUILDLINK_PKGSRCDIR.${pkg}}/builtin.mk"
CHECK_BUILTIN.${pkg}:=	no
.endfor

.for pkg in ${BUILDLINK_TREE:N-*:Nx11-links:O:u}
IGNORE_PKG.${pkg}=	yes
.  if defined(USE_BUILTIN.${pkg}) && \
      !empty(USE_BUILTIN.${pkg}:M[yY][eE][sS])
.    if exists(${FILESDIR}/xorg.${pkg})
FILES_LIST+=		${FILESDIR}/xorg.${pkg}
.    elif exists(${FILESDIR}/xfree.${pkg})
FILES_LIST+=		${FILESDIR}/xfree.${pkg}
.    endif
.  endif
.endfor
