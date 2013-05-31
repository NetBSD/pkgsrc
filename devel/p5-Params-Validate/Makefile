# $NetBSD: Makefile,v 1.43 2013/05/31 12:40:38 wiz Exp $

DISTNAME=	Params-Validate-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Validate/
COMMENT=	Validate method/function parameters
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{p5-Attribute-Handlers>=0.79,perl>=5.10.0}:../../devel/p5-Attribute-Handlers
DEPENDS+=	{p5-Scalar-List-Utils>=1.0,perl>=5.10.0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
