# $NetBSD: Makefile,v 1.13 2009/05/24 15:53:19 zafer Exp $
#

DISTNAME=	mstream-1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_BACKUP}

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
