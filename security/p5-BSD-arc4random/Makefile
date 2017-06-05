# $NetBSD: Makefile,v 1.8 2017/06/05 14:24:28 ryoon Exp $
#

DISTNAME=	BSD-arc4random-1.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SJ/SJSZ/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sjsz/BSD-arc4random/
COMMENT=	Perl interface to the arc4 random number generator
LICENSE=	miros

PERL5_PACKLIST=	auto/BSD/arc4random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
