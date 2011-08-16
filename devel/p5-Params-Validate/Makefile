# $NetBSD: Makefile,v 1.39 2011/08/16 09:30:36 obache Exp $

DISTNAME=	Params-Validate-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Params-Validate/
COMMENT=	Validate method/function parameters
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{p5-Attribute-Handlers>=0.79,perl>=5.10.0}:../../devel/p5-Attribute-Handlers
DEPENDS+=	{p5-Scalar-List-Utils>=1.0,perl>=5.10.0}:../../devel/p5-Scalar-List-Utils

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
