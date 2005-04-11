# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:16 tv Exp $
#

DISTNAME=		Crypt-Random-1.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		# empty
SVR4_PKGNAME=		p5cra
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Random/
COMMENT=		Perl5 interface to /dev/random

DEPENDS+=		p5-Class-Loader>=2.00:../../devel/p5-Class-Loader
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
