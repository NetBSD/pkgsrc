# $NetBSD: Makefile,v 1.19 2022/07/14 23:46:20 dholland Exp $

DISTNAME=	SDL2_image-2.0.5
PKGREVISION=	6
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces
LICENSE=	zlib

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	ac_cv_prog_ac_ct_OBJC=${CC:Q}

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
