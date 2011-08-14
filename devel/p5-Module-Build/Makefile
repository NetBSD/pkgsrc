# $NetBSD: Makefile,v 1.30 2011/08/14 12:26:17 obache Exp $

DISTNAME=	Module-Build-0.3607
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-ExtUtils-CBuilder>=0.27:../../devel/p5-ExtUtils-CBuilder
DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:../../devel/p5-ExtUtils-ParseXS
DEPENDS+=	{perl>=5.10.1,p5-PathTools>=3.30}:../../devel/p5-PathTools

.include "options.mk"

USE_LANGUAGES=	c	# For the tests
#BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist
# For the tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
