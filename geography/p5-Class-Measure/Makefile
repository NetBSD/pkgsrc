# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:57 wiz Exp $

DISTNAME=	Class-Measure-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BL/BLUEFEET/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Class::Measure
COMMENT=	Create, compare, and convert units of measurement
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/Class/Measure/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
