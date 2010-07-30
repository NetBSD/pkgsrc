# $NetBSD: options.mk,v 1.2 2010/07/30 10:36:25 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pfstools
PKG_SUPPORTED_OPTIONS=	gdal imagemagick openexr octave qt opengl

PLIST_VARS+=	gdal im exr octave qt gl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgdal)
.include "../../geography/gdal-lib/buildlink3.mk"
PLIST.gdal=	yes
CONFIGURE_ARGS+=	--enable-gdal
.else
CONFIGURE_ARGS+=	--disable-gdal
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
.include "../../graphics/ImageMagick/buildlink3.mk"
PLIST.im=	yes
CONFIGURE_ARGS+=	--enable-imagemagick
.else
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
PLIST.exr=	yes
CONFIGURE_ARGS+=	--enable-openexr
.else
CONFIGURE_ARGS+=	--disable-openexr
.endif

.if !empty(PKG_OPTIONS:Moctave)
.include "../../math/octave/buildlink3.mk"
REPLACE_OCTAVE+=	src/octave/pfsoctavelum src/octave/pfsoctavergb
REPLACE_OCTAVE+=	src/octave/pfsstat
.include "../../math/octave/octave.mk"
PLIST.octave=	yes
PLIST_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR:S/${BUILDLINK_PREFIX.octave}\///}
PLIST_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR:S/${BUILDLINK_PREFIX.octave}\///}
USE_TOOLS+=	gmake
USE_LANGUAGES+=	fortran77
CONFIGURE_ARGS+=	--enable-octave
.else
CONFIGURE_ARGS+=	--disable-octave
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
PLIST.qt=	yes
USE_TOOLS+=	gmake
CONFIGURE_ARGS+=	--enable-qt
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.include "../../graphics/glut/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-opengl
PLIST.gl=	yes
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif
