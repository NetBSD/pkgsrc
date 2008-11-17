# $NetBSD: Makefile,v 1.17 2008/11/17 03:22:03 he Exp $

DISTNAME=	Module-Build-0.30
PKGNAME=	p5-${DISTNAME}00
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-ExtUtils-CBuilder-[0-9]*:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES=		# empty
BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist
# For the tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
