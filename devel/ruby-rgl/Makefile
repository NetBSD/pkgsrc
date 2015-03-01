# $NetBSD: Makefile,v 1.6 2015/03/01 15:52:48 taca Exp $

DISTNAME=	rgl-0.5.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rgl.rubyforge.org/
COMMENT=	Framework for graph data structures and algorithms

DEPENDS+=	${RUBY_PKGPREFIX}-algorithms>=0.5.0:../../devel/ruby-algorithms
DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5:../../devel/ruby-stream

OVERRIDE_GEMSPEC+= algorithms>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
