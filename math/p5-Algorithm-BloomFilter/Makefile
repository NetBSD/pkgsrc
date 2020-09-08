# $NetBSD: Makefile,v 1.7 2020/09/08 13:16:42 wiz Exp $

DISTNAME=	Algorithm-BloomFilter-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SM/SMUELLER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Algorithm::BloomFilter
COMMENT=	Simple bloom filter data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Algorithm/BloomFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
