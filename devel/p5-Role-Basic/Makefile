# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:57 wiz Exp $

DISTNAME=	Role-Basic-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/OVID/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Role-Basic
COMMENT=	Just roles. Nothing else
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-Storable>=2.15}:../../devel/p5-Storable

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Role/Basic/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
