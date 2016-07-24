# $NetBSD: Makefile,v 1.1 2016/07/24 22:59:11 kamil Exp $

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
