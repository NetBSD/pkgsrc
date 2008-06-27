# $NetBSD: Makefile,v 1.7 2008/06/27 18:07:02 he Exp $
#

DISTNAME=		PAR-0.89
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/
COMMENT=		Cross-Platform Packaging and Debugging Tool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-Module-ScanDeps>=0.45:../../devel/p5-Module-ScanDeps
DEPENDS+=		p5-PAR-Dist>=0.06:../../devel/p5-PAR-Dist
DEPENDS+=		p5-Module-Signature>=0.35:../../security/p5-Module-Signature
DEPENDS+=		p5-Compress-Zlib>=1.30:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=		auto/PAR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
