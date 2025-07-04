# $NetBSD: Makefile,v 1.21 2025/07/04 08:47:09 wiz Exp $

DISTNAME=	Algorithm-LUHN-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Algorithm::LUHN
COMMENT=	Calculate the Modulus 10 Double Add Double checksum
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/LUHN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
