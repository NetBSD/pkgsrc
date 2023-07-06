# $NetBSD: Makefile,v 1.33 2023/07/06 09:40:52 wiz Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Arbitrary length integer extension module for Perl
HOMEPAGE=	https://metacpan.org/release/Math-BigInteger

PERL5_PACKLIST=		auto/Math/BigInteger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
