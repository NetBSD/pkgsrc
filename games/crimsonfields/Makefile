# $NetBSD: Makefile,v 1.48 2023/11/12 13:21:30 wiz Exp $

DISTNAME=	crimson-0.5.3
PKGNAME=	${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://crimson.seul.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crimson.seul.org/
COMMENT=	Tactical war game in the tradition of Battle Isle
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

CONFIGURE_ARGS+=	--enable-bi2cf
CONFIGURE_ARGS+=	--enable-cf2bmp
CONFIGURE_ARGS+=	--enable-cfed
CONFIGURE_ARGS+=	--enable-comet

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
