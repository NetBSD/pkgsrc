# $NetBSD: Makefile,v 1.2 2020/02/05 15:19:29 taca Exp $

DISTNAME=	rspec_junit_formatter-0.4.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sj26/rspec_junit_formatter
COMMENT=	RSpec JUnit XML formatter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=3<4:../../devel/ruby-rspec-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
