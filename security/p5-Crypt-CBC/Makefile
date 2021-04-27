# $NetBSD: Makefile,v 1.47 2021/04/27 10:51:00 wiz Exp $

DISTNAME=		Crypt-CBC-3.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-CBC
COMMENT=		Perl5 cipher block chaining mode for various crypto algorithms

DEPENDS+=		p5-Math-Int128-[0-9]*:../../math/p5-Math-Int128
DEPENDS+=		p5-Crypt-PBKDF2-[0-9]*:../../security/p5-Crypt-PBKDF2
DEPENDS+=		p5-CryptX-[0-9]*:../../security/p5-CryptX

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/CBC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
