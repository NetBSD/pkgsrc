# $NetBSD: Makefile,v 1.1.1.1 2006/05/15 14:59:52 seb Exp $

DISTNAME=	Module-Install-0.62
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5moi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install/
COMMENT=	Perl5 module for building and installing Perl modules

DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Archive-Tar>=0.23:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-ExtUtils-ParseXS-[0-9]*:../../devel/p5-ExtUtils-ParseXS
DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Module-CoreList-[0-9]*:../../devel/p5-Module-CoreList
DEPENDS+=	p5-Module-ScanDeps>=0.28:../../devel/p5-Module-ScanDeps
DEPENDS+=	p5-PAR-Dist>=0.03:../../devel/p5-PAR-Dist

PERL5_PACKLIST=		auto/Module/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
