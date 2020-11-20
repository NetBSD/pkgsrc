# $NetBSD: Makefile,v 1.26 2020/11/20 19:08:06 wiz Exp $

.include "../../print/poppler/Makefile.common"

PKGNAME=	poppler-cpp-${POPPLER_VERS}

COMMENT=	PDF rendering library (cpp wrapper)

CONFLICTS+=	poppler<0.4.5nb1

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-cpp.pc.cmake

# Don't compile GTK+ test program.
CMAKE_ARGS+=	-DBUILD_GTK_TESTS=OFF
# Don't compile GLib wrapper which also needs gtk2
CMAKE_ARGS+=	-DENABLE_GLIB=OFF
# Don't build and install the tools
CMAKE_ARGS+=	-DENABLE_UTILS=OFF
# Compile poppler cpp wrapper.
CMAKE_ARGS+=	-DENABLE_CPP=ON
# Don't compile poppler qt5 wrapper.
CMAKE_ARGS+=	-DENABLE_QT5=OFF
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=	-DENABLE_LIBCURL=OFF

LDFLAGS.SunOS+=		-liconv

BUILDLINK_API_DEPENDS.poppler+=	poppler-${POPPLER_VERS}{,nb*}
.include "../../print/poppler/buildlink3.mk"

BUILD_DIRS=		cpp
INSTALL_DIRS=		cpp

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../converters/libiconv/buildlink3.mk"

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
CMAKE_ARGS+=	-DICONV_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.iconv}/include
CMAKE_ARGS+=	-DICONV_LIBRARIES:PATH=${BUILDLINK_PREFIX.iconv}/lib
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-cpp.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
