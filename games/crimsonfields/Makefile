# $NetBSD: Makefile,v 1.34 2007/09/09 16:59:19 wiz Exp $
#

DISTNAME=		crimson-0.5.1
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
CATEGORIES=		games
MASTER_SITES=		http://crimson.seul.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://crimson.seul.org/
COMMENT=		Tactical war game in the tradition of Battle Isle

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
# not standard locale files
#USE_PKGLOCALEDIR=	no
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-bi2cf
CONFIGURE_ARGS+=	--enable-cf2bmp
CONFIGURE_ARGS+=	--enable-cfed
CONFIGURE_ARGS+=	--enable-comet

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
