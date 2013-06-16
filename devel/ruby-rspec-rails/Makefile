# $NetBSD: Makefile,v 1.13 2013/06/16 16:31:05 taca Exp $

DISTNAME=	rspec-rails-2.13.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2.13.0<2.14:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=2.13.0<2.14:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=2.13.0<2.14:../../devel/ruby-rspec-mocks

RUBY_RAILS_SUPPORTED=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
