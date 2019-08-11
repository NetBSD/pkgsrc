# $NetBSD: Makefile,v 1.21 2019/08/11 13:22:51 wiz Exp $

DISTNAME=		Crypt-DH-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-DH
COMMENT=		Perl5 module for the Diffie-Hellman key exchange system
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Math-BigInt-GMP-[0-9]*:../../math/p5-Math-BigInt-GMP
DEPENDS+=		p5-Math-BigInt-Pari-[0-9]*:../../math/p5-Math-BigInt-Pari
DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Crypt/DH/.packlist
MAKE_PARAMS+=		--skipdeps

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
