# $NetBSD: Makefile,v 1.25 2013/10/28 15:40:09 wen Exp $

DISTNAME=	App-Cmd-0.322
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-Cmd/
COMMENT=	Perl 5 module to write command line apps with less suffering
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.13:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-Load>=0.06:../../devel/p5-Class-Load
DEPENDS+=	p5-Data-OptList-[0-9]*:../../devel/p5-Data-OptList
DEPENDS+=	p5-Getopt-Long>=2.39:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Getopt-Long-Descriptive>=0.084:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-IO-TieCombine>=1:../../devel/p5-IO-TieCombine
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Sub-Exporter>=0.975:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/App/Cmd/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
