# $NetBSD: Makefile,v 1.3 2017/06/05 14:23:18 ryoon Exp $

DISTNAME=	MooX-StrictConstructor-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HARTZELL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~hartzell/MooX-StrictConstructor/
COMMENT=	Make your Moo-based object constructors blow up on unknown attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-indirect-[0-9]*:../../devel/p5-indirect
DEPENDS+=	p5-bareword-filehandles-[0-9]*:../../devel/p5-bareword-filehandles
DEPENDS+=	p5-multidimensional-[0-9]*:../../devel/p5-multidimensional
DEPENDS+=	p5-strictures-[0-9]*:../../devel/p5-strictures
BUILD_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage
BUILD_DEPENDS+=	p5-Pod-Coverage-TrustPod-[0-9]*:../../textproc/p5-Pod-Coverage-TrustPod

PERL5_PACKLIST=		auto/MooX/StrictConstructor/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
