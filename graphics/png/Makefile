# $NetBSD: Makefile,v 1.39.2.1 2002/05/11 02:09:14 jlam Exp $

# On update, don't forget to increase shared library major/minor's in
# accordance with changes (patch-aa).
DISTNAME=	libpng-1.2.1
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		ftp://ftp.simplesystems.org/pub/libpng/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/png/src/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.libpng.org/pub/png/
COMMENT=	Library for manipulating PNG images

USE_BUILDLINK2_ONLY=	yes
USE_LIBTOOL=		yes
MAKE_ENV+=		REALCC="${BUILDLINK_CC}"

MAKEFILE=	scripts/makefile.std

post-install:
	${INSTALL_MAN} ${WRKSRC}/libpng.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/libpngpf.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/png.5 ${PREFIX}/man/man5

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
