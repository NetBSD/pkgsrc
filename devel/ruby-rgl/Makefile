# $NetBSD: Makefile,v 1.15 2022/09/03 14:42:56 taca Exp $

DISTNAME=	rgl-0.5.9
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

#RUBY_VERSIONS_ACCEPTED=	27 30 31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
