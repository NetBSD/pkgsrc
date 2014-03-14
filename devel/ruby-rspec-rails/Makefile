# $NetBSD: Makefile,v 1.15 2014/03/14 16:43:43 taca Exp $

DISTNAME=	rspec-rails-2.14.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2.14.0<2.15:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=2.14.0<2.15:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=2.14.0<2.15:../../devel/ruby-rspec-mocks

RUBY_RAILS_SUPPORTED=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
