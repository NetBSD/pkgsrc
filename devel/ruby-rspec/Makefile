# $NetBSD: Makefile,v 1.9 2012/03/20 13:39:18 taca Exp $

DISTNAME=	rspec-2.9.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2.9.0<2.10:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=2.9.0<2.10:../../devel/ruby-rspec-expectations
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-mocks>=2.9.0<2.10:../../devel/ruby-rspec-mocks

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
