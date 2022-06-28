# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:43 wiz Exp $

DISTNAME=		Crypt-PBKDF2-0.161520
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-PBKDF2
COMMENT=		PBKDF2 password hashing algorithm
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=		p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=		p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=		p5-Digest-SHA3-[0-9]*:../../security/p5-Digest-SHA3
TEST_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/Crypt/PBKDF2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
