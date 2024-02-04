# $NetBSD: Makefile,v 1.29 2024/02/04 15:41:34 taca Exp $

DISTNAME=	rspec-3.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.13.0<3.14:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.13.0<3.14:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=3.13.0<3.14:../../devel/ruby-rspec-mocks

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
