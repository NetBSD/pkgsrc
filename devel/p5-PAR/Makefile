# $NetBSD: Makefile,v 1.8 2008/08/11 13:11:19 he Exp $
#

DISTNAME=		PAR-0.982
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PAR/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/PAR/
COMMENT=		Cross-Platform Packaging and Debugging Tool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Archive-Zip>=1:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-Module-ScanDeps>=0.45:../../devel/p5-Module-ScanDeps
DEPENDS+=		p5-PAR-Dist>=0.22:../../devel/p5-PAR-Dist
DEPENDS+=		p5-Module-Signature>=0.35:../../security/p5-Module-Signature
DEPENDS+=		p5-Compress-Zlib>=1.30:../../devel/p5-Compress-Zlib
DEPENDS+=		p5-AutoLoader>=5.63:../../devel/p5-AutoLoader

PERL5_PACKLIST=		auto/PAR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
