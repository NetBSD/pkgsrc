# $NetBSD: Makefile,v 1.1.1.1 2002/05/05 22:13:38 rh Exp $
#

DISTNAME=	lbreakout2-2.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/ \
			--with-doc-path=${LOCALBASE}/doc/

.include "../../graphics/png/buildlink.mk"
.include "../../audio/SDL-mixer/buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
