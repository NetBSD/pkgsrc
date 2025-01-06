# $NetBSD: Makefile,v 1.16 2025/01/06 21:49:13 ktnb Exp $
#

DISTNAME=	hex-a-hop-1.1.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hexahop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hexahop.sourceforge.net/
COMMENT=	Hexagonal tile-based puzzle game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
