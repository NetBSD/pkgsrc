# $NetBSD: Makefile,v 1.34 2023/07/06 09:40:38 wiz Exp $

DISTNAME=	GDTextUtil-0.86
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
#HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDTextUtil/Text.html
COMMENT=	Perl 5 text utilities for use with the GD drawing package

DEPENDS+=	p5-GD>=1.30:../../graphics/p5-GD

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/GD/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
