# $NetBSD: Makefile,v 1.16.2.1 2011/12/07 08:33:11 tron Exp $
#

DISTNAME=		PAR-1.005
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PAR/RSCHUPP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/PAR/
COMMENT=		Cross-Platform Packaging and Debugging Tool
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
DEPENDS+=		{perl>=5.10.1,p5-AutoLoader>5.66}:../../devel/p5-AutoLoader
DEPENDS+=		p5-IO-Compress>=2.017:../../devel/p5-IO-Compress
DEPENDS+=		p5-Module-ScanDeps>=0.45:../../devel/p5-Module-ScanDeps
DEPENDS+=		p5-Module-Signature>=0.35:../../security/p5-Module-Signature
DEPENDS+=		p5-PAR-Dist>=0.32:../../devel/p5-PAR-Dist

PERL5_PACKLIST=		auto/PAR/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
