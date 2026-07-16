# $NetBSD: Makefile,v 1.39 2026/07/16 19:04:45 wiz Exp $

DISTNAME=		Crypt-Primes-0.52
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Primes
COMMENT=		Perl5 module for provable prime number generation

DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Primes/.packlist
REPLACE_PERL+=		lib/Crypt/Primes.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
