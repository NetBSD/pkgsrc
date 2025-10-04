# $NetBSD: Makefile,v 1.61 2025/10/04 14:38:42 kikadf Exp $

DISTNAME=	SDL_image-1.2.12
PKGREVISION=	16
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces
LICENSE=	zlib

CONFLICTS=		SDL-image-[0-9]*

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-tif
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ENV+=		OBJC=${CC:Q}

INSTALLATION_DIRS=	bin
PKGCONFIG_OVERRIDE=	SDL_image.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && (${OPSYS_VERSION} < 100500 || ${SDL12_TYPE:U:tl} == "compat")
CONFIGURE_ARGS+=	--disable-imageio
.endif

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${DESTDIR}${PREFIX}/bin

BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
