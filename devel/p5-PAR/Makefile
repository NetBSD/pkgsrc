# $NetBSD: Makefile,v 1.43 2024/11/16 12:04:50 wiz Exp $
#

DISTNAME=		PAR-1.020
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PAR/RSCHUPP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/PAR
COMMENT=		Cross-Platform Packaging and Debugging Tool
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-PAR-Dist>=0.32:../../devel/p5-PAR-Dist

PERL5_PACKLIST=		auto/PAR/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
