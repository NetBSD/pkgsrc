# $NetBSD: Makefile,v 1.2 2017/05/04 15:06:18 taca Exp $

DISTNAME=	globalid-0.4.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Reference models by URI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=4.2.0:${RUBY_RAILS42_ACTIVESUPPORT}

RUBY_RAILS_SUPPORTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/rails.mk"
.include "../../mk/bsd.pkg.mk"
