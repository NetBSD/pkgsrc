# $NetBSD: Makefile,v 1.2 2001/08/29 22:41:15 jlam Exp $
#

DISTNAME=		SDL_image-1.2.0
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		graphics
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		image file loading library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	YES

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
