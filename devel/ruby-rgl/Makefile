# $NetBSD: Makefile,v 1.16 2023/01/03 05:56:21 taca Exp $

DISTNAME=	rgl-0.5.10
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5.3:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-lazy_priority_queue>0.1.0<0.2:../../devel/ruby-lazy_priority_queue
# Ruby 2.7 and later have rexml 3.2 or later.
#DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=3.2<4:../../textproc/ruby-rexml

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
