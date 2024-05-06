# $NetBSD: Makefile,v 1.1 2024/05/06 18:05:31 nia Exp $

DISTNAME=	SDL2_image-2.0.1
CATEGORIES=	graphics devel
MASTER_SITES=	https://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces
LICENSE=	zlib

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-imageio
CONFIGURE_ARGS+=	--disable-sdltest

# No runtime loading, bake everything in.
CONFIGURE_ARGS+=	--disable-jpg-shared
CONFIGURE_ARGS+=	--disable-png-shared
CONFIGURE_ARGS+=	--disable-tif-shared
CONFIGURE_ARGS+=	--disable-webp-shared

INSTALLATION_DIRS=	bin
PKGCONFIG_OVERRIDE=	SDL2_image.pc.in

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${DESTDIR}${PREFIX}/bin/showimage2

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
