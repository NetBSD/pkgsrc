# $NetBSD: Makefile,v 1.48 2023/07/06 09:39:35 wiz Exp $

DISTNAME=	Moo-2.005005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Moo
COMMENT=	Minimalist Object Orientation (with Moose compatiblity)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers>=1.10:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Devel-GlobalDestruction>=0.11:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Module-Runtime>=0.014:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Role-Tiny>=2.002003:../../devel/p5-Role-Tiny
DEPENDS+=	p5-strictures>=2.000000:../../devel/p5-strictures
DEPENDS+=	p5-Import-Into>=1.002000:../../devel/p5-Import-Into
DEPENDS+=	p5-Sub-Quote>=2.003001:../../devel/p5-Sub-Quote

PERL5_PACKLIST=	auto/Moo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
