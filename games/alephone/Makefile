# $NetBSD: Makefile,v 1.9 2009/12/10 06:10:02 obache Exp $
#

DISTNAME=	AlephOne-20091015
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=marathon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://marathon.sourceforge.net/
COMMENT=	Classic 2.5D FPS game engine, updated to use SDL
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	share/doc/AlephOne

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/AlephOne/

.include "../../audio/SDL_sound/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.6
.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers>=1.31
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_image+=	SDL_image>=1.2.6
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
