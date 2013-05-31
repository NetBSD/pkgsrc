# $NetBSD: Makefile,v 1.20 2013/05/31 12:39:37 wiz Exp $

DISTNAME=	Audio-CD-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5acd
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.vanhemert.co.uk/files/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.vanhemert.co.uk/disc-cover.html
COMMENT=	Audio-CD perl module for use with disc-cover
LICENSE=	artistic

PERL5_PACKLIST=		auto/Audio/CD/.packlist

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
