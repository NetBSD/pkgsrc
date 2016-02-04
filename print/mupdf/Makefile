# $NetBSD: Makefile,v 1.34 2016/02/04 11:50:24 leot Exp $

DISTNAME=	mupdf-1.8-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://mupdf.com/downloads/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://mupdf.com/
COMMENT=	Lightweight PDF viewer and toolkit
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

INSTALLATION_DIRS+=	bin include lib/pkgconfig
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
LDFLAGS=		${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		XCFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		build=release

CFLAGS+=	-DJBIG_NO_MEMENTO
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

.include "options.mk"

# Remove thirdparty directory in order to use the libraries provided by pkgsrc
# mujs directory is an exception and should not be removed (MuJS is the
# default Javascript interpreter for mupdf).
post-extract:
	${RM} -fr \
	    ${WRKSRC}/thirdparty/curl \
	    ${WRKSRC}/thirdparty/freetype \
	    ${WRKSRC}/thirdparty/glfw \
	    ${WRKSRC}/thirdparty/jbig2dec \
	    ${WRKSRC}/thirdparty/jpeg \
	    ${WRKSRC}/thirdparty/openjpeg \
	    ${WRKSRC}/thirdparty/zlib

post-build:
	sed -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/mupdf.pc > ${WRKSRC}/mupdf.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/mupdf.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
