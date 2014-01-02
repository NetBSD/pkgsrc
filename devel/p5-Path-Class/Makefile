# $NetBSD: Makefile,v 1.19 2014/01/02 16:34:59 schmonz Exp $

DISTNAME=	Path-Class-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWILLIAMS/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-Class/
COMMENT=	Cross-platform path specification manipulation
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Path/Class/.packlist

DEPENDS+=	{perl>=5.10.0,p5-PathTools>=3.19}:../../devel/p5-PathTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
