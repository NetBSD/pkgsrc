# $NetBSD: Makefile,v 1.2 2019/05/06 05:32:55 taca Exp $

DISTNAME=	rspec-its-1.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rspec/rspec-its
COMMENT=	Provides "its" method formerly part of rspec-core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.0.0:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.0.0:../../devel/ruby-rspec-expectations

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
