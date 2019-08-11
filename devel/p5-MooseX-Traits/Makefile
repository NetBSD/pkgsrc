# $NetBSD: Makefile,v 1.22 2019/08/11 13:20:00 wiz Exp $

DISTNAME=	MooseX-Traits-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Traits
COMMENT=	Automatically apply roles at object creation time
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple
BUILD_DEPENDS+= p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+= p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
BUILD_DEPENDS+= p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager


USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Traits/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
