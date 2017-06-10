# $NetBSD: Makefile,v 1.1 2017/06/10 16:25:11 taca Exp $

DISTNAME=	rspec_junit_formatter-0.2.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sj26/rspec_junit_formatter
COMMENT=	RSpec JUnit XML formatter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder<4:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2<4:../../devel/ruby-rspec-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
