# $NetBSD: Makefile,v 1.2 2010/02/26 13:42:17 joerg Exp $
#

DISTNAME=	mupdf-r937
PKGNAME=	${DISTNAME:S/-r/-0.0./}
CATEGORIES=	print
MASTER_SITES=	http://ccxvii.net/mupdf/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccxvii.net/mupdf/
COMMENT=	Lightweight PDF viewer and toolkit
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	jam-[0-9]*:../../devel/jam

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

WRKSRC=	${WRKDIR}/mupdf
MAKE_ENV+=	OS=pkgsrc
MAKE_ENV+=	FT=${BUILDLINK_PREFIX.freetype2}

INSTALLATION_DIRS+=	bin include lib/pkgconfig share/doc/mupdf

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam '-sBUILD=release'
	sed -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/mupdf.pc > ${WRKSRC}/mupdf.pc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/mupdf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fitz/fitz.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/fitz/fitz_base.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/fitz/fitz_draw.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/fitz/fitz_stream.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/fitz/fitz_tree.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/mupdf/mupdf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/build/*/libmupdf.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mupdf.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mupdf

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
