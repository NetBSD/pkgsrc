# $NetBSD: Makefile,v 1.20 2012/12/12 10:22:37 wiz Exp $

DISTNAME=	AlephOne-20120514
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=marathon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://marathon.sourceforge.net/
COMMENT=	Classic 2.5D FPS game engine, updated to use SDL
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/AlephOne

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/AlephOne/

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.6
.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers>=1.31
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL_image+=	SDL_image>=1.2.6
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
