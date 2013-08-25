# $NetBSD: Makefile,v 1.1 2013/08/25 06:17:35 wen Exp $

DISTNAME=	Archive-Any-Lite-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Any-Lite/
COMMENT=	Simple CPAN package extractor
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-Archive-Tar>=0:../../archivers/p5-Archive-Tar
DEPENDS+=		p5-Archive-Zip>=0:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-PathTools>=0:../../devel/p5-PathTools
DEPENDS+=		p5-IO-Zlib>=0:../../devel/p5-IO-Zlib
DEPENDS+=		p5-IO-Compress>=0:../../devel/p5-IO-Compress

BUILD_DEPENDS+=		p5-Test-UseAllModules>=0:../../devel/p5-Test-UseAllModules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Archive/Any/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
