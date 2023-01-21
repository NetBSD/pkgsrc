# $NetBSD: Makefile,v 1.7 2023/01/21 13:57:31 taca Exp $

DISTNAME=	roadie-rails-3.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails/rails${RUBY_RAILS}/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie-rails
COMMENT=	Hooks Roadie into your Rails application
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-roadie>=5.0<6:../../mail/ruby-roadie

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	27 30 31 32
RUBY_RAILS_ACCEPTED=	61

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
