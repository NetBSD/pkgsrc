# $NetBSD: Makefile,v 1.6 2022/10/09 07:31:08 taca Exp $

DISTNAME=	rspec_junit_formatter-0.6.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sj26/rspec_junit_formatter
COMMENT=	RSpec JUnit XML formatter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-builder<4:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-core>=2<4:../../devel/ruby-rspec-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
