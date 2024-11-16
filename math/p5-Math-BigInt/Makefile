# $NetBSD: Makefile,v 1.25 2024/11/16 12:05:58 wiz Exp $

DISTNAME=		Math-BigInt-2.003003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Math-BigInt
COMMENT=		Arbitrary size integer math perl package
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/BigInt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
