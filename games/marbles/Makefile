# $NetBSD: Makefile,v 1.1.1.1 2002/05/05 23:01:06 hubertf Exp $
#

DISTNAME=	marbles-1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-like puzzle

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-profile-path=${LOCALBASE}/share/games/

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
