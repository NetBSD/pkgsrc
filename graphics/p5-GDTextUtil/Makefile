# $NetBSD: Makefile,v 1.9 2004/05/09 00:45:45 snj Exp $
#

DISTNAME=	GDTextUtil-0.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5gdt
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDTextUtil/Text.html
COMMENT=	Perl 5 text utilities for use with the GD drawing package

DEPENDS+=	p5-GD>=1.30:../../graphics/p5-GD

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
