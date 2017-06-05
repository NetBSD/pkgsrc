# $NetBSD: Makefile,v 1.5 2017/06/05 14:24:01 ryoon Exp $

DISTNAME=	SVG-Graph-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVG-Graph
COMMENT=	Visualize your data in Scalable Vector Graphics (SVG) format
LICENSE=	artistic-2.0

DEPENDS+=	p5-Math-Derivative-[0-9]*:../../math/p5-Math-Derivative
DEPENDS+=	p5-Math-Spline-[0-9]*:../../math/p5-Math-Spline
DEPENDS+=	p5-Statistics-Descriptive-[0-9]*:../../math/p5-Statistics-Descriptive
DEPENDS+=	p5-Tree-DAG_Node-[0-9]*:../../devel/p5-Tree-DAG_Node

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/SVG/Graph/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
