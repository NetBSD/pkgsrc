# $NetBSD: Makefile,v 1.6 2001/06/26 10:15:26 zuntum Exp $
#

DISTNAME=	lbreakout-001018
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=--disable-sound

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
