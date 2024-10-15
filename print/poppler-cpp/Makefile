# $NetBSD: Makefile,v 1.45 2024/10/15 16:07:00 adam Exp $

PKGNAME=	poppler-cpp-${POPPLER_VERS}

COMMENT=	PDF rendering library (cpp wrapper)

CONFLICTS+=	poppler<0.4.5nb1

PKGCONFIG_OVERRIDE+=	poppler-cpp.pc.cmake

# Don't compile GTK+ test program.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GTK_TESTS=OFF
# Don't compile GLib wrapper which also needs gtk2
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GLIB=OFF
# Don't build and install the tools
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTILS=OFF
# Compile poppler cpp wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPP=ON
# Don't compile poppler qt5/6 wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=OFF

BUILD_DIRS=		cpp
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../converters/libiconv/buildlink3.mk"

CHECK_BUILTIN.iconv:=	yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=	no

.if ${USE_BUILTIN.iconv:U:tl} == no
CMAKE_CONFIGURE_ARGS+=	-DICONV_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.iconv}/include
CMAKE_CONFIGURE_ARGS+=	-DICONV_LIBRARIES:PATH=${BUILDLINK_PREFIX.iconv}/lib
LDFLAGS.Darwin+=	-liconv
.endif

.include "../../print/poppler/Makefile.common"

post-install:
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/poppler-cpp.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+=	poppler-${POPPLER_VERS}{,nb*}
.include "../../print/poppler/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
