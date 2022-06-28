# $NetBSD: Makefile,v 1.32 2022/06/28 11:34:40 wiz Exp $

DISTNAME=	Math-GMP-2.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-GMP
COMMENT=	Perl 5 module for high speed arbitrary size integer math
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	p5-Alien-GMP-[0-9]*:../../math/p5-Alien-GMP

PERL5_PACKLIST=	auto/Math/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
