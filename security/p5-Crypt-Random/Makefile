# $NetBSD: Makefile,v 1.41 2025/07/04 08:48:00 wiz Exp $

DISTNAME=		Crypt-Random-1.57
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Random
COMMENT=		Perl5 interface to /dev/random
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Class-Loader>=2.00:../../devel/p5-Class-Loader
DEPENDS+=		p5-Crypt-URandom>=0:../../security/p5-Crypt-URandom
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-Statistics-ChiSquare>=1:../../math/p5-Statistics-ChiSquare

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
