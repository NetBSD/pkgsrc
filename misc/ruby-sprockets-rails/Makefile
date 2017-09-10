# $NetBSD: Makefile,v 1.2 2017/09/10 14:59:15 taca Exp $

DISTNAME=	sprockets-rails-3.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets-rails
COMMENT=	Sprockets Rails integration
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=3.0.0:../../misc/ruby-sprockets
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

RUBY_RAILS_SUPPORTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
