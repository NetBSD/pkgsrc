# $NetBSD: Makefile,v 1.39 2021/03/07 08:33:44 taca Exp $

DISTNAME=	rspec-rails-4.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	Test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.10<4:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.10<4:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.10<4:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=3.10<4:../../devel/ruby-rspec-mocks

USE_LANGUAGES=	# empty

RUBY_RAILS_ACCEPTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
