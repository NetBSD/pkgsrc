# $NetBSD: Makefile,v 1.1 2025/11/03 04:40:04 taca Exp $

DISTNAME=	roadie-rails-3.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails/&32_${RUBY_RAILS}/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie-rails
COMMENT=	Hooks Roadie into your Rails application version 3.2.x
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-roadie>=5.0<6:../../mail/ruby-roadie

CONFLICTS+=	${RUBY_PKGPREFIX}-roadie-rails-3.2.*

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	72

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
