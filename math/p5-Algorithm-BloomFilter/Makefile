# $NetBSD: Makefile,v 1.4 2019/08/11 13:21:45 wiz Exp $

DISTNAME=	Algorithm-BloomFilter-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://cpan.metacpan.org/authors/id/S/SM/SMUELLER/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SM/SMUELLER/
COMMENT=	Simple bloom filter data structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Algorithm/BloomFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
