# $NetBSD: Makefile,v 1.8 2006/03/10 22:47:35 rillig Exp $
#

DISTNAME=	mstream-1.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://kimmo.suominen.com/gwradio/
COMMENT=	Mserv player package to queue tracks to IceS

DEPENDS+=	ices-mp3>=0.3:../../audio/ices-mp3
DEPENDS+=	p5-MP3-Info>=1.0:../../audio/p5-MP3-Info

NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}

.include "../../mk/bsd.pkg.mk"
