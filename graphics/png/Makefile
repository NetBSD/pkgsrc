# $NetBSD: Makefile,v 1.73 2005/12/27 17:34:53 reed Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.2.8
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.simplesystems.org/pub/libpng/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
TEST_TARGET=	test

LIBPNG_SO_MAJOR=	3
LIBPNG_SO_MINOR=	2

MAKEFILE=	scripts/makefile.std
MAKE_ENV+=	REALCC=${CC:Q}
MAKE_ENV+=	LIBPNG_SO_MAJOR=${LIBPNG_SO_MAJOR:Q}
MAKE_ENV+=	LIBPNG_SO_MINOR=${LIBPNG_SO_MINOR:Q}

INSTALLATION_DIRS=	include lib/pkgconfig ${PKGMANDIR}/man3 ${PKGMANDIR}/man5

PKGCONFIG_OVERRIDE=	scripts/libpng.pc.in

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		post-patch
SUBST_FILES.pc=		scripts/libpng.pc.in
SUBST_SED.pc=		-e 's,@PREFIX@,${PREFIX},'
SUBST_MESSAGE.pc=	"Fixing libpng.pc.in."

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng.pc.in \
		${PREFIX}/lib/pkgconfig/libpng12.pc

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
