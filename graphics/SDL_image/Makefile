# $NetBSD: Makefile,v 1.8 2003/09/09 13:36:56 adam Exp $
#

DISTNAME=		SDL_image-1.2.3
#PKGREVISION=		2
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		YES
USE_X11=		YES

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
