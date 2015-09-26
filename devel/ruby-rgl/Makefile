# $NetBSD: Makefile,v 1.8 2015/09/26 15:02:59 taca Exp $

DISTNAME=	rgl-0.5.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms

DEPENDS+=	${RUBY_PKGPREFIX}-algorithms>=0.5.0:../../devel/ruby-algorithms
DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5:../../devel/ruby-stream

OVERRIDE_GEMSPEC+= algorithms>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
