# $NetBSD: Makefile,v 1.65 2022/06/28 11:32:45 wiz Exp $

DISTNAME=	Module-Build-0.4231
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build
COMMENT=	Build and install Perl modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-inc-latest-[0-9]*:../../devel/p5-inc-latest

TEST_DEPENDS+=	p5-PAR-Dist-[0-9]*:../../devel/p5-PAR-Dist
# For the tests:
USE_TOOLS+=	perl

.include "options.mk"

#BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
