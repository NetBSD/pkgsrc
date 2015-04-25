# $NetBSD: Makefile,v 1.22 2015/04/25 14:22:53 tnn Exp $
#

DISTNAME=	d2x-0.2.5
PKGREVISION=	14
CATEGORIES=	games x11
MASTER_SITES=	http://icculus.org/d2x/src/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://icculus.org/d2x/
COMMENT=	Descent II port

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

D2X_DATA=		${PREFIX}/share/games/${PKGBASE}
REQD_DIRS=		${D2X_DATA}
MESSAGE_SUBST+=		D2X_DATA=${D2X_DATA}

#
# Network disabled for now, since only IPX is supported which NetBSD doesn't
# support
#
CONFIGURE_ARGS+=	--disable-network
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-sharepath=${D2X_DATA:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
