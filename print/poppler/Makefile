# $NetBSD: Makefile,v 1.86 2022/02/06 08:36:18 wiz Exp $

.include "../../print/poppler/Makefile.common"

PKGREVISION=	1
COMMENT=	PDF rendering library

PKGCONFIG_OVERRIDE+=	poppler.pc.cmake

INSTALLATION_DIRS+=	include/poppler share/doc/poppler

# Don't compile GTK+ test program.
CMAKE_ARGS+=	-DBUILD_GTK_TESTS=OFF
# Don't compile GLib wrapper which also needs gtk2
CMAKE_ARGS+=	-DENABLE_GLIB=OFF
# Don't build and install the tools
CMAKE_ARGS+=	-DENABLE_UTILS=OFF
# Don't compile poppler cpp wrapper.
CMAKE_ARGS+=	-DENABLE_CPP=OFF
# Don't compile poppler qt5 wrapper.
CMAKE_ARGS+=	-DENABLE_QT5=OFF
# Don't compile poppler qt6 wrapper.
CMAKE_ARGS+=	-DENABLE_QT6=OFF
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=	-DENABLE_LIBCURL=OFF

.include "../../mk/bsd.prefs.mk"

# Passing "-ansi" turns "long long" support off on FreeBSD/amd64:
.if ${OPSYS} == "FreeBSD" && ${MACHINE_ARCH} == "x86_64"
CFLAGS+=	-D__LONG_LONG_SUPPORTED=
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/poppler/
	${INSTALL_MAN} ${WRKSRC}/README-XPDF ${DESTDIR}${PREFIX}/share/doc/poppler/
	${RMDIR} ${DESTDIR}${PREFIX}/include/poppler || ${TRUE}

.include "../../devel/nss/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
