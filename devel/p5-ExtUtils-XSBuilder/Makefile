# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:25 jlam Exp $

DISTNAME=	ExtUtils-XSBuilder-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exs
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for automatic XS glue code generation

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/XSBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
