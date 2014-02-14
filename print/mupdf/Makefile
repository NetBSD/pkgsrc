# $NetBSD: Makefile,v 1.21 2014/02/14 17:49:41 drochner Exp $

DISTNAME=	mupdf-1.3-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://mupdf.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupdf.com/
COMMENT=	Lightweight PDF viewer and toolkit
LICENSE=	gnu-agpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

SUBST_CLASSES+=			makerules
SUBST_STAGE.makerules=		post-patch
SUBST_MESSAGE.makerules=	Fixing CFLAGS for openjpeg in Makerules.
SUBST_FILES.makerules=		Makerules
SUBST_VARS.makerules+=		PREFIX

INSTALLATION_DIRS+=	bin include lib/pkgconfig
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
LDFLAGS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	V8_PRESENT=no
MAKE_FLAGS+=	build=release

.include "options.mk"

# Remove thirdparty directory in order to use the libraries provided by pkgsrc
post-extract:
	${RM} -fr ${WRKSRC}/thirdparty

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
