# $NetBSD: Makefile,v 1.27 2022/06/28 11:33:58 wiz Exp $

DISTNAME=	Geo-Distance-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BLUEFEET/Geo-Distance-0.20
COMMENT=	Calculate Distances and Closest Locations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
DEPENDS+=	p5-Const-Fast-[0-9]*:../../devel/p5-Const-Fast
DEPENDS+=	p5-GIS-Distance-[0-9]*:../../geography/p5-GIS-Distance
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

# test failures for 0.24:
# https://github.com/bluefeet/Geo-Distance/issues/18
PERL5_PACKLIST=		auto/Geo/Distance/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
