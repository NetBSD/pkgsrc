# $NetBSD: Makefile,v 1.16 2012/12/08 23:09:39 adam Exp $

DISTNAME=	mupdf-1.1-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://ccxvii.net/mupdf/download/ \
		http://ccxvii.net/mupdf/download/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupdf.com/
COMMENT=	Lightweight PDF viewer and toolkit
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

INSTALLATION_DIRS+=	bin include lib/pkgconfig
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}
LDFLAGS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

post-build:
	sed -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/mupdf.pc > ${WRKSRC}/mupdf.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/mupdf.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
