# $NetBSD: Makefile,v 1.14 2021/05/24 19:53:56 wiz Exp $
#

DISTNAME=	BSD-arc4random-1.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SJ/SJSZ/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BSD-arc4random
COMMENT=	Perl interface to the arc4 random number generator
LICENSE=	miros

PERL5_PACKLIST=	auto/BSD/arc4random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
