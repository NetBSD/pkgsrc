# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:21 wiz Exp $

DISTNAME=		Crypt-Curve25519-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Curve25519/
COMMENT=		Perl5 module for the elliptic-curve Diffie-Hellman key exchange
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		p5-Math-BigInt-GMP-[0-9]*:../../math/p5-Math-BigInt-GMP
#DEPENDS+=		p5-Math-BigInt-Pari-[0-9]*:../../math/p5-Math-BigInt-Pari
#DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/Curve25519/.packlist
MAKE_PARAMS+=		--skipdeps

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
