# $NetBSD: Makefile,v 1.1.1.1 2002/08/28 19:39:52 seb Exp $
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

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
