# $NetBSD: Makefile,v 1.16 2003/07/21 16:49:53 martti Exp $
#

DISTNAME=	lbreakout-010315
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--disable-sound

.include "../../devel/SDL/buildlink2.mk"

PTHREAD_LIBS=		-lpthread

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../mk/bsd.pkg.mk"
