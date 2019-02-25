# $NetBSD: Makefile,v 1.11 2019/02/25 16:43:23 taca Exp $

DISTNAME=	rgl-0.5.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5.2:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-lazy_priority_queue>0.1.0<0.2:../../devel/ruby-lazy_priority_queue

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
