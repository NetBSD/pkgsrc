# $NetBSD: Makefile,v 1.1 2026/07/24 13:59:29 wen Exp $

DISTNAME=	Crypt-URandom-Token-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STIGTSP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-URandom
COMMENT=	Perl5 module to provide non blocking randomness
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Crypt-URandom>=0.40:../../security/p5-Crypt-URandom
TEST_DEPENDS+=	p5-Test-Exception>=0.43:../../devel/p5-Test-Exception

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Crypt/URandom/Token/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
