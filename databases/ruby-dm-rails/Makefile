# $NetBSD: Makefile,v 1.2 2012/03/20 10:17:02 taca Exp $

DISTNAME=	dm-rails-1.2.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-rails
COMMENT=	Use DataMapper with Rails 3
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-active_model>=1.2.0<1.3:../../databases/ruby-dm-active_model
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_SUPPORTED=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
