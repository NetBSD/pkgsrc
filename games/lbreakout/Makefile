# $NetBSD: Makefile,v 1.8 2001/08/15 19:41:44 rh Exp $
#

DISTNAME=	lbreakout-010315
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK_ONLY=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-sound

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
