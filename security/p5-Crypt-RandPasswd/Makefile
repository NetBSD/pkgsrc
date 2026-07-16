# $NetBSD: Makefile,v 1.31 2026/07/16 19:04:45 wiz Exp $
#

DISTNAME=		Crypt-RandPasswd-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-RandPasswd
COMMENT=		Random password generator based on FIPS-181
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/RandPasswd/.packlist

# Sometimes results in an endless loop.
TEST_TARGET=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
