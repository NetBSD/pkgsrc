# $NetBSD: Makefile,v 1.60 2004/04/27 19:36:27 tv Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.2.5
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	4
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

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	test

LIBPNG_SO_MAJOR=	3
LIBPNG_SO_MINOR=	1

MAKEFILE=	scripts/makefile.std
MAKE_ENV+=	REALCC="${CC}"
MAKE_ENV+=	LIBPNG_SO_MAJOR=${LIBPNG_SO_MAJOR}
MAKE_ENV+=	LIBPNG_SO_MINOR=${LIBPNG_SO_MINOR}
PLIST_SUBST+=	LIBPNG_SO_MAJOR=${LIBPNG_SO_MAJOR}
PLIST_SUBST+=	LIBPNG_SO_MINOR=${LIBPNG_SO_MINOR}

INSTALLATION_DIRS=	include lib/pkgconfig man/man3 man/man5

PKGCONFIG_OVERRIDE=	scripts/libpng12.pc.in

SUBST_CLASSES=		pc
SUBST_STAGE.pc=		post-patch
SUBST_FILES.pc=		scripts/libpng.pc.in
SUBST_SED.pc=		s\!@PREFIX@!${PREFIX}!
SUBST_MESSAGE.pc=	"Fixing libpng.pc.in."

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng.pc.in \
		${PREFIX}/lib/pkgconfig/libpng12.pc

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
