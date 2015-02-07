# $NetBSD: Makefile,v 1.16 2015/02/07 14:43:30 taca Exp $

DISTNAME=	rspec-3.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.2.0<3.3:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.2.0<3.3:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=3.2.0<3.3:../../devel/ruby-rspec-mocks

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
