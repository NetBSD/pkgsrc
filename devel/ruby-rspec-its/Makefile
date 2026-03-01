# $NetBSD: Makefile,v 1.4 2026/03/01 07:45:54 taca Exp $

DISTNAME=	rspec-its-2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rspec/rspec-its
COMMENT=	Provides "its" method formerly part of rspec-core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3.13.0:../../devel/ruby-rspec-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-expectations>=3.13.0:../../devel/ruby-rspec-expectations

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
