# $NetBSD: Makefile,v 1.4 2001/11/26 06:49:37 jlam Exp $
#

DISTNAME=	Audio-CD-0.04-disc-cover-1.1.0
PKGNAME=	p5-Audio-CD-0.04-disc-cover-1.1.0
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio
MASTER_SITES=	http://www.liacs.nl/~jvhemert/disc-cover/download/libraries/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.liacs.nl/~jvhemert/disc-cover/
COMMENT=	Audio-CD perl module for use with disc-cover

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/CD/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../audio/libcdaudio/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
