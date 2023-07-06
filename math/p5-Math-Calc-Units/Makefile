# $NetBSD: Makefile,v 1.8 2023/07/06 09:40:53 wiz Exp $

DISTNAME=	Math-Calc-Units-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SF/SFINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Math::Calc::Units
COMMENT=	Human-readable unit-aware calculator
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Calc/Units/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
