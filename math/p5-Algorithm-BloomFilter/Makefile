# $NetBSD: Makefile,v 1.9 2022/06/28 11:34:38 wiz Exp $

DISTNAME=	Algorithm-BloomFilter-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Algorithm::BloomFilter
COMMENT=	Simple bloom filter data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Algorithm/BloomFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
