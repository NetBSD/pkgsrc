# $NetBSD: Makefile,v 1.52 2015/01/11 20:36:36 wiz Exp $

DISTNAME=	Params-Validate-1.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Validate/
COMMENT=	Validate method/function parameters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{p5-Scalar-List-Utils>=1.0,perl>=5.10.0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
