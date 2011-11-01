# $NetBSD: Makefile,v 1.10 2011/11/01 06:02:26 sbd Exp $
#

DISTNAME=	mupdf-0.8-source
PKGNAME=	mupdf-0.8
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://ccxvii.net/mupdf/download/ \
		http://ccxvii.net/mupdf/download/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupdf.com/
COMMENT=	Lightweight PDF viewer and toolkit
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/mupdf-0.8
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake

USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	bin include lib/pkgconfig
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
LDFLAGS=	-Wl,-rpath,${X11BASE}/lib
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

post-build:
	sed -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/mupdf.pc > ${WRKSRC}/mupdf.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/mupdf.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
