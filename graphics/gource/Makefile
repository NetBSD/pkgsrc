# $NetBSD: Makefile,v 1.3 2011/11/01 06:01:35 sbd Exp $
#

DISTNAME=	gource-0.37
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gource.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gource/
COMMENT=	software version control visualization
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
