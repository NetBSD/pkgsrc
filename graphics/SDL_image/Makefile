# $NetBSD: Makefile,v 1.4 2003/05/05 13:29:14 jmmv Exp $
#

DISTNAME=		SDL_image-1.2.2
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		YES
USE_X11=		YES

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
