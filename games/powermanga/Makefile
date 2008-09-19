# $NetBSD: Makefile,v 1.20 2008/09/19 19:16:45 joerg Exp $
#

DISTNAME=	powermanga-0.79
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
MAKE_ENV+=	TOUCH=${TOUCH:Q} WRKSRC=${WRKSRC:Q}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
