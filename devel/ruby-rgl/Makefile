# $NetBSD: Makefile,v 1.10 2017/06/04 16:13:07 taca Exp $

DISTNAME=	rgl-0.5.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-lazy_priority_queue>0.1.0<0.2:../../devel/ruby-lazy_priority_queue

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
