# $NetBSD: Makefile,v 1.8 2003/07/28 12:34:02 seb Exp $
#

DISTNAME=	GraphViz-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GraphViz/}

MAINTAINER=	seb@NetBSD.org
COMMENT=	Perl interface to the Graphviz tools set

DEPENDS+=	p5-Graph>=0.201:../../devel/p5-Graph
DEPENDS+=	p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=	p5-Math-Bezier>=0.01:../../math/p5-Math-Bezier
DEPENDS+=	p5-Math-Bezier>=0.01:../../math/p5-Math-Bezier
DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_BUILDLINK2=		yes
USE_X11=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GraphViz/.packlist

.include "../../graphics/graphviz/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
