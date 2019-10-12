# $NetBSD: Makefile,v 1.38 2019/10/12 20:00:30 rillig Exp $
#

DISTNAME=	fillets-ng-1.0.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://fillets.sourceforge.net/
COMMENT=	Puzzle game about witty fish saving the world sokoban style
LICENSE=	gnu-gpl-v2

DEPENDS+=	fillets-ng-data>=1.0.1:../../games/fillets-ng-data

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-sdltest

LDFLAGS.DragonFly=	-lX11
LDFLAGS.SunOS+=		-lX11

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	fillets.6
SUBST_MESSAGE.man=	Fixing documentation path in the manual page.
SUBST_SED.man=		-e "s,/usr/share/doc/fillets-ng/html/manual.html,${PREFIX}/share/doc/fillets-ng/manual.html,"

LUA_VERSIONS_ACCEPTED=	51

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
