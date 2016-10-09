# $NetBSD: Makefile,v 1.9 2016/10/09 15:00:04 taca Exp $

DISTNAME=	rgl-0.5.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-lazy_priority_queue>0.1.0<0.2:../../devel/ruby-lazy_priority_queue

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
