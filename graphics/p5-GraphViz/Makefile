# $NetBSD: Makefile,v 1.19 2006/03/10 21:03:18 rillig Exp $
#

DISTNAME=	GraphViz-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GraphViz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GraphViz/
COMMENT=	Perl interface to the Graphviz tools set

# This is for the 'test' target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

DEPENDS+=	p5-IPC-Run>=0.74:../../devel/p5-IPC-Run
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

PERL5_PACKLIST=		auto/GraphViz/.packlist
INSTALLATION_DIRS=	share/examples/p5-GraphViz

REPLACE_PERL+=	examples/*

post-install:
	cd ${WRKSRC}/examples &&	\
	  ${PAX} -pm -rw . ${PREFIX}/share/examples/p5-GraphViz

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
