# $NetBSD: Makefile,v 1.3 2020/03/20 11:57:40 nia Exp $

DISTNAME=	barrage-1.0.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Rather destructive action game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
