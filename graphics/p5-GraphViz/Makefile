# $NetBSD: Makefile,v 1.2 2002/10/27 19:34:19 seb Exp $
#

DISTNAME=	GraphViz-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GraphViz/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl interface to the Graphviz tools set

DEPENDS+=	graphviz>=1.8.5:../../graphics/graphviz
DEPENDS+=	p5-Graph>=0.201:../../devel/p5-Graph
DEPENDS+=	p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=	p5-Math-Bezier>=0.01:../../math/p5-Math-Bezier

USE_BUILDLINK2=		yes
USE_X11=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GraphViz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
