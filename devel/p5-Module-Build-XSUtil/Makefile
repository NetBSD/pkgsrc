# $NetBSD: Makefile,v 1.4 2015/04/25 01:22:04 mef Exp $
#

DISTNAME=	Module-Build-XSUtil-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build-XSUtil
COMMENT=	Module::Build class for building XS modules
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-Devel-CheckCompiler>=0.02:../../devel/p5-Devel-CheckCompiler

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/XSUtil/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
