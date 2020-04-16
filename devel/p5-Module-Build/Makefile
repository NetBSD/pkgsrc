# $NetBSD: Makefile,v 1.61 2020/04/16 11:16:59 mef Exp $

DISTNAME=	Module-Build-0.4231
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build
COMMENT=	Build and install Perl modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-inc-latest-[0-9]*:../../devel/p5-inc-latest

TEST_DEPENDS+=	p5-CPAN-Meta>=2.142060:../../devel/p5-CPAN-Meta
TEST_DEPENDS+=	p5-PAR-Dist-[0-9]*:../../devel/p5-PAR-Dist
# For the tests:
USE_TOOLS+=	perl

.include "options.mk"

#BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
