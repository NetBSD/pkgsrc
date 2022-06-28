# $NetBSD: Makefile,v 1.39 2022/06/28 11:32:59 wiz Exp $
#

DISTNAME=		PAR-1.017
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PAR/RSCHUPP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/PAR
COMMENT=		Cross-Platform Packaging and Debugging Tool
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
#DEPENDS+=		{perl>=5.10.1,p5-AutoLoader>5.66}:../../devel/p5-AutoLoader
#DEPENDS+=		{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=1.3
DEPENDS+=		p5-PAR-Dist>=0.32:../../devel/p5-PAR-Dist

PERL5_PACKLIST=		auto/PAR/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
