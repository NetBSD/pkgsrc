# $NetBSD: Makefile,v 1.3 2002/09/11 10:16:19 wiz Exp $
#

DISTNAME=	lbreakout2-2.3.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/ \
			--with-doc-path=${LOCALBASE}/share/doc/html/

.include "../../graphics/png/buildlink2.mk"
.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
