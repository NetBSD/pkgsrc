# $NetBSD: Makefile,v 1.12 2022/06/28 11:32:50 wiz Exp $

DISTNAME=	MooX-StrictConstructor-0.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HARTZELL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-StrictConstructor
COMMENT=	Make your Moo-based object constructors blow up on unknown attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-indirect-[0-9]*:../../devel/p5-indirect
DEPENDS+=	p5-bareword-filehandles-[0-9]*:../../devel/p5-bareword-filehandles
DEPENDS+=	p5-multidimensional-[0-9]*:../../devel/p5-multidimensional
DEPENDS+=	p5-strictures-[0-9]*:../../devel/p5-strictures

TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
TEST_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage
TEST_DEPENDS+=	p5-Pod-Coverage-TrustPod-[0-9]*:../../textproc/p5-Pod-Coverage-TrustPod

PERL5_PACKLIST=		auto/MooX/StrictConstructor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
