# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:02 veego Exp $
#

DISTNAME=	Audio-CD-0.04-disc-cover-1.1.0
PKGNAME=	p5-Audio-CD-0.04-disc-cover-1.1.0
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio
MASTER_SITES=	http://www.liacs.nl/~jvhemert/disc-cover/download/libraries/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.liacs.nl/~jvhemert/disc-cover/
COMMENT=	Audio-CD perl module for use with disc-cover

DEPENDS+=	libcdaudio>=0.99.4nb1:../../audio/libcdaudio

USE_PERL5=	yes
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Audio/CD/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
