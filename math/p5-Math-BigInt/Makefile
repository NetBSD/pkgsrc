# $NetBSD: Makefile,v 1.22 2023/07/06 09:40:52 wiz Exp $

DISTNAME=		Math-BigInt-1.999837
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
