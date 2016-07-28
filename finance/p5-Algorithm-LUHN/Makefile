# $NetBSD: Makefile,v 1.10 2016/07/28 06:57:07 wen Exp $

DISTNAME=	Algorithm-LUHN-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Algorithm::LUHN
COMMENT=	Calculate the Modulus 10 Double Add Double checksum

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/LUHN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
