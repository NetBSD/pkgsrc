# $NetBSD: Makefile,v 1.33 2019/06/30 20:14:38 nia Exp $

DISTNAME=	Class-Accessor-Grouped-0.10014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Accessor-Grouped
COMMENT=	Lets you build groups of accessors
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Sub-Name>=0.05:../../devel/p5-Sub-Name

# For test target
BUILD_DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
#BUILD_DEPENDS+=	{perl>=5.12.0,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Class-XSAccessor>=1.15:../../devel/p5-Class-XSAccessor
# for make test
BUILD_DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Accessor/Grouped/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
