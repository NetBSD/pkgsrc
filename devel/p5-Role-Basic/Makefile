# $NetBSD: Makefile,v 1.1 2014/01/01 03:08:30 ryoon Exp $

DISTNAME=	Role-Basic-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/OVID/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Role-Basic/
COMMENT=	Just roles. Nothing else
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Storable>=2.15:../../devel/p5-Storable

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Role/Basic/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
