# $NetBSD: Makefile,v 1.28 2022/06/28 11:30:55 wiz Exp $
#

DISTNAME=	mstream-1.3
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://software.kimmo.suominen.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kimmo.suominen.com/gwradio/
COMMENT=	Mserv player package to queue tracks to IceS

DEPENDS+=	ices-mp3>=0.3:../../audio/ices-mp3
DEPENDS+=	p5-MP3-Info>=1.0:../../audio/p5-MP3-Info

NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run

DATADIR=	${PREFIX}/share/mstream
MODDIR=		${PREFIX}/share/ices-mp3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DATADIR=${DATADIR}
MAKE_FLAGS+=	MODDIR=${MODDIR}
MAKE_FLAGS+=	PERL=${PERL5:Q}

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	DATADIR=${DESTDIR}${DATADIR}
INSTALL_MAKE_FLAGS+=	MODDIR=${DESTDIR}${MODDIR}

.include "../../mk/bsd.pkg.mk"
