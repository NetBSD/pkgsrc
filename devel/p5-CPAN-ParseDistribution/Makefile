# $NetBSD: Makefile,v 1.15 2023/07/06 09:38:41 wiz Exp $
#

DISTNAME=	CPAN-ParseDistribution-1.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-ParseDistribution
COMMENT=	Index a file from the BackPAN to give name and version of the distr'n
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
TOOL_DEPENDS+=	p5-Parallel-ForkManager-[0-9]*:../../devel/p5-Parallel-ForkManager
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TOOL_DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
TOOL_DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip

PERL5_PACKLIST=	auto/CPAN/ParseDistribution/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
