# $NetBSD: Makefile,v 1.25 2018/08/22 09:44:23 wiz Exp $
#

DISTNAME=	MooseX-Role-Parameterized-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Role-Parameterized
COMMENT=	Roles with composition parameters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Moose>=2.0300:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Module-Build-Tiny>=0.037:../../devel/p5-Module-Build-Tiny
BUILD_DEPENDS+=	p5-MooseX-Role-WithOverloading-[0-9]*:../../devel/p5-MooseX-Role-WithOverloading
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
#     Module::Build::Tiny 0.037 missing
#     CPAN::Meta::Check             0.007  missing
#     MooseX::Role::WithOverloading   any  missing
#     Test::Requires                  any  missing
# for make test
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Role/Parameterized/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PERL5_PACKLIST=	auto/MooseX/Role/Parameterized/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
