# $NetBSD: Makefile,v 1.11 2019/08/11 13:22:50 wiz Exp $
#

DISTNAME=	BSD-arc4random-1.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SJ/SJSZ/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BSD-arc4random
COMMENT=	Perl interface to the arc4 random number generator
LICENSE=	miros

PERL5_PACKLIST=	auto/BSD/arc4random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
