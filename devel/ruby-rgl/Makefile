# $NetBSD: Makefile,v 1.13 2021/01/10 16:20:48 taca Exp $

DISTNAME=	rgl-0.5.7
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5.3:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-lazy_priority_queue>0.1.0<0.2:../../devel/ruby-lazy_priority_queue

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
