# $NetBSD: Makefile,v 1.55 2004/03/18 22:40:40 ben Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.2.5
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	2
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

INSTALLATION_DIRS=	include lib man/man3 man/man5

post-build:
	cd ${WRKSRC}/scripts && \
		${SED} -e s\!@PREFIX@!${PREFIX}! <libpng.pc.in >libpng12.pc

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng12.pc ${PREFIX}/lib/pkgconfig/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
