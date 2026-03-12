# $NetBSD: Makefile,v 1.59 2026/03/12 15:48:07 taca Exp $

DISTNAME=	rspec-rails-8.0.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rspec/rspec-rails
COMMENT=	Test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.13<4:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.13<4:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.13<4:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=3.13<4:../../devel/ruby-rspec-mocks

USE_LANGUAGES=	# empty

RUBY_RAILS_ACCEPTED=	72 80

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
