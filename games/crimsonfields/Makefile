# $NetBSD: Makefile,v 1.23 2005/03/27 15:43:34 wiz Exp $
#

DISTNAME=		crimson-0.4.7
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://crimson.seul.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://crimson.seul.org/
COMMENT=		Tactical war game in the tradition of Battle Isle

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
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
