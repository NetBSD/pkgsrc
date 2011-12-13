# $NetBSD: Makefile,v 1.23 2011/12/13 15:48:12 taca Exp $

DISTNAME=	activerecord-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activerecord/
COMMENT=	Object-relation mapping put on rails
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_SUPPORTED=	2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
