# $NetBSD: Makefile,v 1.19 2005/03/27 15:43:37 wiz Exp $

DISTNAME=	SDL_image-1.2.4
PKGREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-tif

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
