# $NetBSD: Makefile,v 1.1 2022/09/01 16:15:40 taca Exp $

DISTNAME=	roadie-rails-2.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails/rails2_${RUBY_RAILS}/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie-rails
COMMENT=	Hooks Roadie into your Rails application
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-roadie4>=3.1:../../mail/ruby-roadie4

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	26 27
RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
