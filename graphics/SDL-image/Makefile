# $NetBSD: Makefile,v 1.7 2002/08/27 19:15:13 jlam Exp $
#

DISTNAME=		SDL_image-1.2.1
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		load images as SDL surfaces

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
