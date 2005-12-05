# $NetBSD: Makefile,v 1.23 2005/12/05 20:50:16 rillig Exp $

DISTNAME=	lbreakout-010315
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PTHREAD_LIBS=${PTHREAD_LIBS:Q}
CONFIGURE_ARGS+=	--disable-sound

.include "../../devel/SDL/buildlink3.mk"

PTHREAD_LIBS=		-lpthread

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../mk/bsd.pkg.mk"
