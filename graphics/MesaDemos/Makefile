# $NetBSD: Makefile,v 1.50 2022/08/11 05:08:38 gutteridge Exp $

DISTNAME=	mesa-demos-8.4.0
PKGNAME=	${DISTNAME:S/mesa-demos/MesaDemos/}
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/demos/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/demos/
COMMENT=	OpenGL examples and Demos
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		bitmap
SUBST_STAGE.bitmap=	pre-configure
SUBST_MESSAGE.bitmap=	Avoid conflict with x11/bitmap and graphics/glx-utils
SUBST_FILES.bitmap=	src/glsl/Makefile.in
SUBST_FILES.bitmap+=	src/xdemos/Makefile.in
SUBST_SED.bitmap=	-e 's/bitmap$$(EXEEXT)/bitmap_mesademos$$(EXEEXT)/g'
SUBST_SED.bitmap+=	-e 's/glxgears$$(EXEEXT)/glxgears_mesademos$$(EXEEXT)/g'
SUBST_SED.bitmap+=	-e 's/glxinfo$$(EXEEXT)/glxinfo_mesademos$$(EXEEXT)/g'

# Mesa library features.
PLIST_VARS+=		egl glesv2 osmesa

# Appended in options.mk.
EGL_PROGS+=		eglkms peglgears

.include "../../graphics/MesaLib/buildlink3.mk"
.if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
PLIST.egl=		yes
.  if !empty(MESALIB_SUPPORTS_GLESv2:M[Yy][Ee][Ss])
PLIST.glesv2=		yes
.  else
CONFIGURE_ARGS+=	--disable-gles2
.  endif
# eglfbdev.c:43:10: fatal error: linux/kd.h: No such file or directory
CONFIGURE_ARGS+=	--disable-gles1
CONFIGURE_ARGS+=	--enable-egl
.else
CONFIGURE_ARGS+=	--disable-egl
.endif

.if !empty(MESALIB_SUPPORTS_OSMESA:M[Yy][Ee][Ss])
PLIST.osmesa=		yes
CONFIGURE_ARGS+=	--enable-osmesa
.else
CONFIGURE_ARGS+=	--disable-osmesa
.endif

.include "options.mk"

post-install:
.if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
.  for prog in ${EGL_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/egl/opengl/${prog} ${DESTDIR}${PREFIX}/bin
.  endfor
.endif

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
