# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:08 tv Exp $
#

DISTNAME=	Audio-CD-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/~jano/files/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://home.wanadoo.nl/~jano/disc-cover.html
COMMENT=	Audio-CD perl module for use with disc-cover

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/CD/.packlist

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
