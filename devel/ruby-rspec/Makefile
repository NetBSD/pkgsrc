# $NetBSD: Makefile,v 1.10 2012/06/02 00:47:46 taca Exp $

DISTNAME=	rspec-2.10.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2.10.0<2.11:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=2.10.0<2.11:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=2.10.0<2.11:../../devel/ruby-rspec-mocks

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
