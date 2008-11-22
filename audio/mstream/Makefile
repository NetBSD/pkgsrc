# $NetBSD: Makefile,v 1.12 2008/11/22 08:03:30 kim Exp $
#

DISTNAME=	mstream-1.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://kimmo.suominen.com/gwradio/
COMMENT=	Mserv player package to queue tracks to IceS

DEPENDS+=	ices-mp3>=0.3:../../audio/ices-mp3
DEPENDS+=	p5-MP3-Info>=1.0:../../audio/p5-MP3-Info

NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run

DATADIR=	${LOCALBASE}/share/mstream
MODDIR=		${LOCALBASE}/share/ices-mp3

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	DATADIR=${DATADIR:Q}
MAKE_FLAGS+=	MODDIR=${MODDIR:Q}
MAKE_FLAGS+=	PERL=${PERL5:Q}

.include "../../mk/bsd.pkg.mk"
