# $NetBSD: Makefile,v 1.37 2011/08/14 12:26:28 obache Exp $

DISTNAME=	Params-Validate-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Build>=0.35}:../../devel/p5-Module-Build

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Params/Validate/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
