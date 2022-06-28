# $NetBSD: Makefile,v 1.27 2022/06/28 11:32:54 wiz Exp $

DISTNAME=	MooseX-Role-WithOverloading-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Role-WithOverloading
COMMENT=	Moose extension for roles which support overloading
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.94:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased
DEPENDS+=	p5-namespace-autoclean>=0.12:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
# for make test
BUILD_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/MooseX/Role/WithOverloading/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
