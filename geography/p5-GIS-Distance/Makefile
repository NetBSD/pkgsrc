# $NetBSD: Makefile,v 1.3 2021/05/24 19:52:18 wiz Exp $

DISTNAME=	GIS-Distance-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLUEFEET/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/GIS::Distance
COMMENT=	Calculate geographic distances
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
DEPENDS+=	p5-strictures-[0-9]*:../../devel/p5-strictures
DEPENDS+=	p5-Const-Fast-[0-9]*:../../devel/p5-Const-Fast
DEPENDS+=	p5-Class-Measure-[0-9]*:../../geography/p5-Class-Measure
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/GIS/Distance/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
