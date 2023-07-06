# $NetBSD: Makefile,v 1.19 2023/07/06 09:40:54 wiz Exp $
#

DISTNAME=	Math-Random-MT-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Random-MT
COMMENT=	The Mersenne Twister PRNG
LICENSE=	modified-bsd

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Math/Random/MT/.packlist

DEPENDS+=	p5-Test-Number-Delta>=0:../../math/p5-Test-Number-Delta

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
