# $NetBSD: Makefile,v 1.14 2003/05/02 11:55:01 wiz Exp $
#

DISTNAME=	lbreakout-010315
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	breakout-style arcade game

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
