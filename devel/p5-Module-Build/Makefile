# $NetBSD: Makefile,v 1.21 2009/03/02 17:22:15 joerg Exp $

DISTNAME=	Module-Build-0.32
PKGNAME=	p5-${DISTNAME}000
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules

PKG_DESTDIR_SUPPORT=	user-destdir

#.include "options.mk"

USE_LANGUAGES=	c	# For the tests
BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/.packlist
# For the tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
