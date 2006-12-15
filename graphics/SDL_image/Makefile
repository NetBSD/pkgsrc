# $NetBSD: Makefile,v 1.26 2006/12/15 14:34:20 wiz Exp $

DISTNAME=	SDL_image-1.2.5
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-tif

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${PREFIX}/bin

BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
