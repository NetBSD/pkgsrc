# $NetBSD: Makefile,v 1.23 2017/09/17 20:07:00 wiz Exp $

DISTNAME=		Math-GMP-2.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-GMP/
COMMENT=		Perl 5 module for high speed arbitrary size integer math
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=	p5-Devel-CheckLib>=0:../../devel/p5-Devel-CheckLib
BUILD_DEPENDS+=	p5-Test-YAML-Meta>=0.03:../../devel/p5-Test-YAML-Meta

PERL5_PACKLIST=		auto/Math/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
