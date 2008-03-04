# $NetBSD: Makefile,v 1.5 2008/03/04 11:02:24 rillig Exp $
#

DISTNAME=		PAR-0.89
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/
COMMENT=		Cross-Platform Packaging and Debugging Tool

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-Module-ScanDeps>=0.45:../../devel/p5-Module-ScanDeps
DEPENDS+=		p5-PAR-Dist>=0.06:../../devel/p5-PAR-Dist
DEPENDS+=		p5-Module-Signature>=0.35:../../security/p5-Module-Signature

PERL5_PACKLIST=		auto/PAR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
