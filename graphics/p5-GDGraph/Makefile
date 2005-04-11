# $NetBSD: Makefile,v 1.14 2005/04/11 21:46:07 tv Exp $
#

DISTNAME=	GDGraph-1.43
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gdg
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/htdocs/GDGraph/GD/Graph.html
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDTextUtil>=0.75:../../graphics/p5-GDTextUtil

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
