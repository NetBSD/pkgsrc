# $NetBSD: Makefile,v 1.17 2023/02/23 14:57:56 taca Exp $

DISTNAME=	rgl-0.6.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/monora/rgl
COMMENT=	Framework for graph data structures and algorithms
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-stream>=0.5.3:../../devel/ruby-stream
DEPENDS+=	${RUBY_PKGPREFIX}-pairing_heap>=0.3.0:../../devel/ruby-pairing_heap
# Ruby 2.7 and later have rexml 3.2 or later.
#DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=3.2<4:../../textproc/ruby-rexml

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
