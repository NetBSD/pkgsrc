# $NetBSD: Makefile,v 1.8 2002/10/27 21:20:38 seb Exp $
#

DISTNAME=	GDGraph-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5gdg
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDGraph/Graph.html
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDTextUtil>=0.75:../../graphics/p5-GDTextUtil

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
