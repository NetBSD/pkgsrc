# $NetBSD: Makefile,v 1.30 2019/06/30 20:16:39 nia Exp $
#

DISTNAME=		Crypt-Random-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Random
COMMENT=		Perl5 interface to /dev/random

DEPENDS+=		p5-Class-Loader>=2.00:../../devel/p5-Class-Loader
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
