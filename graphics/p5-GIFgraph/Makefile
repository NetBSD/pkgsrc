# $NetBSD: Makefile,v 1.7 2005/04/11 21:46:07 tv Exp $
#

DISTNAME=	GIFgraph-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5gig
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GIFgraph/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=GIFgraph
COMMENT=	GIFgraph is a package to generate graphs, using GD::Graph

DEPENDS+=       p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-PerlMagick>=5.3.9:../../graphics/p5-PerlMagick

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GIFgraph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
