# $NetBSD: Makefile,v 1.7 2017/07/30 22:32:13 wiz Exp $

DISTNAME=	dm-rails-1.2.1
PKGREVISION=	3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-rails
COMMENT=	DataMapper for Rubu on Rails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-dm-active_model>=1.2.0<1.3:../../databases/ruby-dm-active_model
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
