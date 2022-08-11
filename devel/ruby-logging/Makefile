# $NetBSD: Makefile,v 1.13 2022/08/11 13:16:02 taca Exp $

DISTNAME=	logging-2.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/logging/
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.14<2:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
