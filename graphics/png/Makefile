# $NetBSD: Makefile,v 1.42 2002/07/19 14:33:08 fredb Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.2.4
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.simplesystems.org/pub/libpng/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes

LIBPNG_SO_MAJOR=	3
LIBPNG_SO_MINOR=	1

MAKEFILE=	scripts/makefile.std
MAKE_ENV+=	REALCC="${CC}"
MAKE_ENV+=	LIBPNG_SO_MAJOR=${LIBPNG_SO_MAJOR}
MAKE_ENV+=	LIBPNG_SO_MINOR=${LIBPNG_SO_MINOR}
PLIST_SUBST+=	LIBPNG_SO_MAJOR=${LIBPNG_SO_MAJOR}
PLIST_SUBST+=	LIBPNG_SO_MINOR=${LIBPNG_SO_MINOR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5

test: build
	@cd ${WRKSRC} && ${MAKE} -f ${MAKEFILE} test

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
