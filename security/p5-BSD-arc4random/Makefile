# $NetBSD: Makefile,v 1.1 2012/06/02 14:29:42 bsiegert Exp $
#

DISTNAME=	BSD-arc4random-1.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SJ/SJSZ/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sjsz/BSD-arc4random/
COMMENT=	Perl interface to the arc4 random number generator
LICENSE=	miros

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/BSD/arc4random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
