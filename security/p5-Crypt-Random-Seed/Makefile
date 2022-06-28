# $NetBSD: Makefile,v 1.12 2022/06/28 11:35:44 wiz Exp $

DISTNAME=		Crypt-Random-Seed-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Random-Seed
COMMENT=		Simple method to get strong randomness
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-Random-TESHA2>=0:../../security/p5-Crypt-Random-TESHA2

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/Seed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
