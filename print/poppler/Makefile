# $NetBSD: Makefile,v 1.105 2024/10/15 16:07:00 adam Exp $

COMMENT=	PDF rendering library

SUPERSEDES+=	poppler-glib-[0-9]*

PKGCONFIG_OVERRIDE+=	poppler.pc.cmake

INSTALLATION_DIRS+=	include/poppler share/doc/poppler

# Don't compile GTK+ test program.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GTK_TESTS=OFF
# Compile GLib wrapper which also needs gtk2
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GLIB=ON
# Don't build and install the tools
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTILS=OFF
# Don't compile poppler cpp wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPP=OFF
# Don't compile poppler qt5/6 wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=OFF
# Don't run gperf if it's present
CMAKE_CONFIGURE_ARGS+=	-DRUN_GPERF_IF_PRESENT=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# MacOS Xcode does not provide /usr/include, so be explicit
CMAKE_CONFIGURE_ARGS+=	-DGLIB2_INCLUDE_DIRS=${PREFIX}/include
.endif

.if ${USE_CROSS_COMPILE:tl} == "yes"
ALL_ENV+=		PKG_CONFIG_SYSROOT_DIR=${CROSS_DESTDIR:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_SYSROOT:STRING=${CROSS_DESTDIR:Q}
.endif

# Passing "-ansi" turns "long long" support off on FreeBSD/amd64:
.if ${OPSYS} == "FreeBSD" && ${MACHINE_ARCH} == "x86_64"
CFLAGS+=	-D__LONG_LONG_SUPPORTED=
.endif

.include "../../print/poppler/Makefile.common"

post-install:
	${INSTALL_MAN} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/poppler/
	${INSTALL_MAN} ${WRKSRC}/README-XPDF ${DESTDIR}${PREFIX}/share/doc/poppler/
	${RMDIR} ${DESTDIR}${PREFIX}/include/poppler || ${TRUE}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=   glib2>=2.41.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=      build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=   cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
