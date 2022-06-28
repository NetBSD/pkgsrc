# $NetBSD: Makefile,v 1.7 2022/06/28 11:34:39 wiz Exp $

DISTNAME=	Math-Calc-Units-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SF/SFINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Math::Calc::Units
COMMENT=	Human-readable unit-aware calculator
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Calc/Units/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
