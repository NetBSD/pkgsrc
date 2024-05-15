# $NetBSD: Makefile,v 1.118 2024/05/15 21:00:43 wiz Exp $

DISTNAME=	mupdf-1.24.0-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	print
MASTER_SITES=	https://mupdf.com/downloads/archive/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://mupdf.com/
COMMENT=	Lightweight PDF, XPS and E-book viewer and toolkit
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600
LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib

MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		XCFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		XLIBS=${LIBS:Q}
MAKE_FLAGS+=		build=release
MAKE_FLAGS+=		USE_SYSTEM_LIBS=yes
MAKE_FLAGS+=		USE_SYSTEM_MUJS=yes

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "options.mk"

INSTALLATION_DIRS+=	bin include lib/pkgconfig
INSTALLATION_DIRS+=	share/pixmaps share/applications

REPLACE_INTERPRETER+=	shell
REPLACE.shell.old=	.*/bin/bash
REPLACE.shell.new=	${SH}
REPLACE_FILES.shell+=	scripts/hexdump.sh

# Remove thirdparty directory in order to use the libraries provided by pkgsrc
# thirdparty/lcms2 is not removed intentionally because ICC support requires
# the internal lcms2 library. ICC support is essential to display some PDF
# files with proper colors.
post-extract:
	${RUN}${RM} -fr \
	    ${WRKSRC}/thirdparty/curl \
	    ${WRKSRC}/thirdparty/freeglut \
	    ${WRKSRC}/thirdparty/freetype \
	    ${WRKSRC}/thirdparty/gumbo-parser \
	    ${WRKSRC}/thirdparty/harfbuzz \
	    ${WRKSRC}/thirdparty/jbig2dec \
	    ${WRKSRC}/thirdparty/leptonica \
	    ${WRKSRC}/thirdparty/libjpeg \
	    ${WRKSRC}/thirdparty/mujs \
	    ${WRKSRC}/thirdparty/openjpeg \
	    ${WRKSRC}/thirdparty/tesseract \
	    ${WRKSRC}/thirdparty/zlib

post-build:
	${RUN}${SED} -e "s,@PREFIX@,${PREFIX}," -e "s,@VERSION@,${PKGVERSION_NOREV}," \
	     ${FILESDIR}/mupdf.pc > ${WRKSRC}/mupdf.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/mupdf.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${FILESDIR}/mupdf.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/mupdf.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${MV} ${DESTDIR}${PREFIX}/bin/mupdf-x11 ${DESTDIR}${PREFIX}/bin/mupdf
# do not toggle executable bit on static libs.
.for i in libmupdf libmupdf-third
	${RUN}${CHMOD} -x ${DESTDIR}${PREFIX}/lib/${i}.a
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.7
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
# XXX: mupdf needs lcms2-art fork
#BUILDLINK_API_DEPENDS.lcms2+= lcms2>=2.9
#.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/mujs/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
