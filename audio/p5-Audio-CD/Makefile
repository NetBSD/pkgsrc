# $NetBSD: Makefile,v 1.8 2004/12/20 11:30:55 grant Exp $
#

DISTNAME=	Audio-CD-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio perl5
MASTER_SITES=	http://homepages.cwi.nl/~jvhemert/files/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://homepages.cwi.nl/~jvhemert/disc-cover.html
COMMENT=	Audio-CD perl module for use with disc-cover

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/CD/.packlist

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
