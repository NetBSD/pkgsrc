# $NetBSD: Makefile,v 1.3 2005/01/16 04:01:31 kim Exp $
#

DISTNAME=	mstream-1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://kimmo.suominen.com/gwradio/
COMMENT=	Mserv player package to queue tracks to IceS

DEPENDS+=	ices-mp3>=0.3:../../audio/ices-mp3
DEPENDS+=	p5-MP3-Info>=1.0:../../audio/p5-MP3-Info

NO_CONFIGURE=	# defined
USE_PERL5=	# defined

MODDIR=		${PREFIX}/share/ices-mp3

MAKE_PARAMS+=	PREFIX=${PREFIX}
MAKE_PARAMS+=	MODDIR=${MODDIR}
MAKE_PARAMS+=	PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
