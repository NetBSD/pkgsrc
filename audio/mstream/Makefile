# $NetBSD: Makefile,v 1.1.1.1 2004/04/25 00:33:15 kim Exp $
#

DISTNAME=	mstream-0.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://kimmo.suominen.com/gwradio/
COMMENT=	Mserv player package to queue tracks to IceS

DEPENDS+=	ices-mp3>=0.3:../../audio/ices-mp3

NO_CONFIGURE=	# defined
USE_PERL5=	# defined

MODDIR=		${PREFIX}/share/ices-mp3

MAKE_PARAMS+=	PREFIX=${PREFIX}
MAKE_PARAMS+=	MODDIR=${MODDIR}
MAKE_PARAMS+=	PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
