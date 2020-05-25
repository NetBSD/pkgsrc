# $NetBSD: Makefile,v 1.1 2020/05/25 14:09:08 taca Exp $

DISTNAME=	roadie-rails-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails/rails${RUBY_RAILS}/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie-rails
COMMENT=	Hooks Roadie into your Rails application
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-roadie>=3.1:../../mail/ruby-roadie

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
