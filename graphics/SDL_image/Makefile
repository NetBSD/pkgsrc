# $NetBSD: Makefile,v 1.10 2003/12/13 20:14:26 ben Exp $
#

DISTNAME=		SDL_image-1.2.3
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-tif

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${PREFIX}/bin

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
