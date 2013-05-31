# $NetBSD: Makefile,v 1.15 2013/05/31 12:40:18 wiz Exp $

DISTNAME=	ExtUtils-XSBuilder-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5exs
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-XSBuilder/
COMMENT=	Perl5 module for automatic XS glue code generation
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/XSBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
