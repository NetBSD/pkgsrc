# $NetBSD: Makefile,v 1.56 2018/08/22 09:44:16 wiz Exp $

DISTNAME=	Module-Build-0.4224
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build
COMMENT=	Build and install Perl modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-ExtUtils-CBuilder>=0.27:../../devel/p5-ExtUtils-CBuilder
#DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:../../devel/p5-ExtUtils-ParseXS
# needed for tests
BUILD_DEPENDS+=	p5-CPAN-Meta>=2.142060:../../devel/p5-CPAN-Meta
# one test not skipped if,
# (but getting cyclic dependency if enabled as BUILD_DEPENDS)
#DEPENDS+=	p5-PAR-Dist-[0-9]*:../../devel/p5-PAR-Dist
DEPENDS+=	p5-inc-latest-[0-9]*:../../devel/p5-inc-latest

.include "options.mk"

USE_LANGUAGES=	c       # For the tests
#BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist
# For the tests:
USE_TOOLS+=		perl

PERL5_PACKLIST=	auto/Module/Build/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
