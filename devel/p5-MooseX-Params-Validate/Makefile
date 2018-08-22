# $NetBSD: Makefile,v 1.20 2018/08/22 09:44:23 wiz Exp $
#

DISTNAME=	MooseX-Params-Validate-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?MooseX::Params::Validate
COMMENT=	Extension of Params::Validate for using Moose's types
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Params/Validate/.packlist

DEPENDS+=	p5-Devel-Caller-[0-9]*:../../devel/p5-Devel-Caller
DEPENDS+=	p5-Moose>=0.58:../../devel/p5-Moose
DEPENDS+=	p5-Params-Validate>=0.88:../../devel/p5-Params-Validate
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

# for make test
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
BUILD_DEPENDS+= p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
