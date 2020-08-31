# $NetBSD: Makefile,v 1.5 2020/08/31 18:10:12 wiz Exp $

DISTNAME=	Algorithm-BloomFilter-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://cpan.metacpan.org/authors/id/S/SM/SMUELLER/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SM/SMUELLER/
COMMENT=	Simple bloom filter data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Algorithm/BloomFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
