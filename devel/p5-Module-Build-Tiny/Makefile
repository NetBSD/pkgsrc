# $NetBSD: Makefile,v 1.24 2023/08/31 23:34:16 wen Exp $

DISTNAME=	Module-Build-Tiny-0.046
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build-Tiny
COMMENT=	Tiny replacement for Module::Build to build and install Perl modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config>=0.003:../../devel/p5-ExtUtils-Config
DEPENDS+=	p5-ExtUtils-Helpers>=0.020:../../devel/p5-ExtUtils-Helpers
DEPENDS+=	p5-ExtUtils-InstallPaths>=0.002:../../devel/p5-ExtUtils-InstallPaths

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Module/Build/Tiny/.packlist
# For the tests:
USE_TOOLS+=		perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
