# $NetBSD: Makefile,v 1.31 2020/09/20 08:13:20 wiz Exp $

DISTNAME=	Audio-CD-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.vanhemert.co.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vanhemert.co.uk/disc-cover-1_5_6/
COMMENT=	Audio-CD perl module for use with disc-cover
LICENSE=	artistic

PERL5_PACKLIST=		auto/Audio/CD/.packlist

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
