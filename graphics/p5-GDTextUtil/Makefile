# $NetBSD: Makefile,v 1.10 2004/08/05 04:38:24 jlam Exp $

DISTNAME=	GDTextUtil-0.86
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gdt
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDTextUtil/Text.html
COMMENT=	Perl 5 text utilities for use with the GD drawing package

DEPENDS+=	p5-GD>=1.30:../../graphics/p5-GD

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
