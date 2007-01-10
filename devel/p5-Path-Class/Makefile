# $NetBSD: Makefile,v 1.1.1.1 2007/01/10 21:58:19 bad Exp $
#

DISTNAME=	Path-Class-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWILLIAMS/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://search.cpan.org/~kwilliams/Path-Class-0.16/
COMMENT=	Cross-platform path specification manipulation 

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/Path/Class/.packlist

DEPENDS+=	p5-PathTools>=3.19:../../devel/p5-PathTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
