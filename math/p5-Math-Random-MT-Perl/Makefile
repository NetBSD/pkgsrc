# $NetBSD: Makefile,v 1.23 2023/07/06 09:40:54 wiz Exp $
#

DISTNAME=	Math-Random-MT-Perl-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Random-MT-Perl
COMMENT=	Pure Perl Mersenne Twister Random Number Generator
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Math/Random/MT/Perl/.packlist

TOOL_DEPENDS+=	p5-Test-Number-Delta>=0:../../math/p5-Test-Number-Delta

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
