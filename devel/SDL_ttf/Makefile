# $NetBSD: Makefile,v 1.10 2003/05/02 11:54:19 wiz Exp $
#

DISTNAME=	SDL_ttf-2.0.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	use TrueType fonts in your SDL applications

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
