# $NetBSD: Makefile,v 1.2 2002/08/27 19:01:22 jlam Exp $
#

DISTNAME=	ltris-1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
