# $NetBSD: Makefile,v 1.12 2005/04/20 08:42:11 seb Exp $
#

DISTNAME=	GraphViz-2.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GraphViz/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GraphViz/
COMMENT=	Perl interface to the Graphviz tools set

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

DEPENDS+=	p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GraphViz/.packlist
INSTALLATION_DIRS=	share/examples/p5-GraphViz

post-install:
	cd ${WRKSRC}/examples &&	\
	  ${PAX} -pm -rw . ${PREFIX}/share/examples/p5-GraphViz

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
