# $NetBSD: buildlink3.mk,v 1.18 2011/05/17 11:34:04 obache Exp $

BUILDLINK_TREE+=	GraphicsMagick

.if !defined(GRAPHICSMAGICK_BUILDLINK3_MK)
GRAPHICSMAGICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GraphicsMagick+=	GraphicsMagick>=1.2
BUILDLINK_ABI_DEPENDS.GraphicsMagick?=	GraphicsMagick>=1.3.12nb4
BUILDLINK_PKGSRCDIR.GraphicsMagick?=	../../graphics/GraphicsMagick

.include "../../mk/bsd.fast.prefs.mk"

_GM_PRE_X11_OPTION!= \
	if ${PKG_INFO} -qe 'GraphicsMagick<=1.3.12nb4'; then		\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi

pkgbase := GraphicsMagick
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.GraphicsMagick:Mghostscript)
.include "../../print/ghostscript/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.GraphicsMagick:Mjasper)
.include "../../graphics/jasper/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.GraphicsMagick:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
.endif
.if ${_GM_PRE_X11_OPTION} == "yes" || !empty(PKG_BUILD_OPTIONS.GraphicsMagick:Mx11)
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GRAPHICSMAGICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-GraphicsMagick
