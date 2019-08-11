# $NetBSD: Makefile,v 1.23 2019/08/11 13:21:46 wiz Exp $

DISTNAME=	Math-BigInt-GMP-1.6006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-BigInt-GMP
COMMENT=	Perl module for arbitrary size integer math via the GMP library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-BigInt>=1.999812:../../math/p5-Math-BigInt

PERL5_PACKLIST=		auto/Math/BigInt/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
