# $NetBSD: Makefile,v 1.13 2018/09/01 20:46:07 bsiegert Exp $

DISTNAME?=	${MESA_DISTNAME}
PKGNAME=	MesaLib7-${MESA_PKGVERSION}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MESA_SITES}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	Graphics library similar to SGI's OpenGL

GNU_CONFIGURE_PREFIX=	${LOCALBASE}/MesaLib7

DISTFILES+=		MesaLib-${MESA_VERSION}${EXTRACT_SUFX}
MESA_DISTNAME= 		MesaLib-${MESA_VERSION}
MESA_SITES=		ftp://freedesktop.org/pub/mesa/older-versions/7.x/${MESA_VERSION}/
MESA_VERSION=		7.11.2
MESA_PKGVERSION=	${MESA_VERSION}

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c99 c++
USE_TOOLS+=		automake bison flex gmake pkg-config makedepend
WRKSRC=			${WRKDIR}/Mesa-${MESA_VERSION}
DIST_SUBDIR=		Mesa-${MESA_PKGVERSION}

CONFLICTS+=	xf86driproto<2.0.4

PLIST_VARS=		dri nodri

BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/MesaLib7/lib

PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/glw/glw.pc.in

CONFIGURE_ARGS+=	--disable-glu
CONFIGURE_ARGS+=	--disable-glut
CONFIGURE_ARGS+=	--disable-motif
CONFIGURE_ARGS+=	--with-gallium-drivers=""
CONFIGURE_ARGS+=	--disable-gallium-llvm
CONFIGURE_ARGS+=	--disable-egl

.include "glx-config.mk"

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 7.11.2

MAKE_ENV+=		MAKE=${GMAKE:Q}

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mccc)
CFLAGS+=	-D__FUNCTION__=__FILE__
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as -fvisibility=hidden
.endif

BUILDLINK_TRANSFORM.MirBSD+=	rm:-fvisibility=hidden

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
# XXX This is not quite enough: we will need to patch the makefile
# because it bogusly tries to reuse objects for native tools and target
# libraries, and for cross-compiling the objects need to be built
# separately.  Alternatively, we could just update Mesa to something
# less prehistoric...
SUBST_CLASSES+=		nativecc
SUBST_STAGE.nativecc=	pre-configure
SUBST_MESSAGE.nativecc=	Fix makefiles to compile tools with native cc.
SUBST_FILES.nativecc+=	src/glsl/Makefile
SUBST_SED.nativecc+=	-e 's,$$(CC),$$(APP_CC),g'
SUBST_SED.nativecc+=	-e 's,$$(CXX),$$(APP_CXX),g'
MAKE_FLAGS+=		APP_CC=${NATIVE_CC:Q}
MAKE_FLAGS+=		APP_CXX=${NATIVE_CXX:Q}
.endif

.include "options.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*)
##
## NetBSD 3.x and later have pthread stubs in libc
##
PTHREAD_STUBLIB=
.else
##
## Other platforms may or may not have stubs provided by libc, but pulling in
## threading support via the pthread.buildlink3.mk definitions will provide
## all the necessary interfaces.  This matches the standard configuration for
## most platforms as they appear in "${WRKSRC}/configs", and is necessary
## for successful linking with libGL under many platforms.
##
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_STUBLIB= ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
.endif
PKGSRC_MAKE_ENV+=	PTHREAD_STUBLIB=${PTHREAD_STUBLIB:Q}
MAKE_ENV+=		PTHREAD_STUBLIB=${PTHREAD_STUBLIB:Q}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CROSS_COMPILING=yes
.endif

pre-configure:
	cd ${WRKSRC} && ${MAKE} configure

post-extract:
.if !empty(PKG_OPTIONS:Mdri) && (${OPSYS} == "SunOS")
	${CP} ${FILESDIR}/mapfile.externs ${WRKSRC}/src/mesa/drivers/dri/
.endif
	${CP} ${FILESDIR}/gen_matypes.awk ${WRKSRC}/src/mesa/x86
	${CP} ${FILESDIR}/gen_matypes.sh ${WRKSRC}/src/mesa/x86
	${CHMOD} a+x ${WRKSRC}/src/mesa/x86/gen_matypes.sh

#
# remove include files installed respectively by ../glu and ../glut
#
pre-install:
	${RM} -f ${WRKSRC}/include/GL/glu*.h

.include "../../lang/python/tool.mk"
BUILDLINK_DEPMETHOD.libxml2?=	build
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
