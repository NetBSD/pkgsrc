# $NetBSD: Makefile,v 1.10 2001/10/23 13:14:54 jlam Exp $
#

DISTNAME=	lbreakout-010315
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-sound

.include "../../mk/x11.buildlink.mk"
.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
