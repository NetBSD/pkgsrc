# $NetBSD: Makefile,v 1.7 2016/01/06 10:46:52 adam Exp $

DISTNAME=	SDL2_image-2.0.0
PKGREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces
LICENSE=	zlib

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	ac_cv_prog_ac_ct_OBJC=${CC:Q}

INSTALLATION_DIRS=	bin
PKGCONFIG_OVERRIDE=	SDL_image.pc.in
CHECK_PORTABILITY_SKIP=	external/tiff-4.0.3/configure

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${DESTDIR}${PREFIX}/bin/showimage2

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
