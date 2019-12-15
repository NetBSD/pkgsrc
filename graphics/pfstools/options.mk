# $NetBSD: options.mk,v 1.8 2019/12/15 21:32:52 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pfstools
PKG_SUPPORTED_OPTIONS=		imagemagick octave opengl qt
PKG_SUGGESTED_OPTIONS.Darwin+=	opengl

PLIST_VARS+=	im octave gl qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimagemagick)
.include "../../graphics/ImageMagick6/buildlink3.mk"
PLIST.im=	yes
CMAKE_ARGS+=	-DWITH_ImageMagick=ON
.else
CMAKE_ARGS+=	-DWITH_ImageMagick=OFF
.endif

.if !empty(PKG_OPTIONS:Moctave)
.include "../../math/octave/buildlink3.mk"
REPLACE_OCTAVE+=	src/octave/pfsoctavelum src/octave/pfsoctavergb
REPLACE_OCTAVE+=	src/octave/pfsstat
.include "../../math/octave/octave.mk"
PLIST.octave=	yes
PLIST_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR:S/${BUILDLINK_PREFIX.octave}\///}
PLIST_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR:S/${BUILDLINK_PREFIX.octave}\///}
CMAKE_ARGS+=	-DWITH_Octave=ON
.else
CMAKE_ARGS+=	-DWITH_Octave=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt5-qtbase/buildlink3.mk"
PLIST.qt=	yes
CMAKE_ARGS+=	-DWITH_QT=ON
.else
CMAKE_ARGS+=	-DWITH_QT=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.include "../../graphics/freeglut/buildlink3.mk"
.  endif
# XXX nasty hack
CXXFLAGS.NetBSD+=	-lpthread
PLIST.gl=	yes
CMAKE_ARGS+=	-DWITH_pfsglview=ON
.else
CMAKE_ARGS+=	-DWITH_pfsglview=OFF
.endif
