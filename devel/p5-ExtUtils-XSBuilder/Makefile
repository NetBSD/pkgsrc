# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	ExtUtils-XSBuilder-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exs
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for automatic XS glue code generation

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/XSBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
