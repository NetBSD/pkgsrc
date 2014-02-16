# $NetBSD: Makefile,v 1.38 2014/02/16 18:02:35 sno Exp $
#

DISTNAME=	Module-Build-0.4205
PKGNAME=	p5-${DISTNAME}0
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build
COMMENT=	Build and install Perl modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-ExtUtils-CBuilder>=0.27:../../devel/p5-ExtUtils-CBuilder
#DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:../../devel/p5-ExtUtils-ParseXS

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
