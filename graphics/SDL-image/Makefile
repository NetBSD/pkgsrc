# $NetBSD: Makefile,v 1.6 2002/03/23 02:04:51 wiz Exp $
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

USE_BUILDLINK_ONLY=	YES

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
