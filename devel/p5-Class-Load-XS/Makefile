# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:09 wiz Exp $

DISTNAME=	Class-Load-XS-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Load-XS/
COMMENT=	XS implementation of parts of Class::Load
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.15:../../devel/p5-Class-Load

BUILD_DEPENDS+=	p5-Module-Implementation>=0.04:../../devel/p5-Module-Implementation
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Load/XS/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
