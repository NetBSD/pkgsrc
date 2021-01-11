# $NetBSD: Makefile,v 1.27 2021/01/11 13:14:29 taca Exp $

DISTNAME=	simplecov-0.21.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9+
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.11.0<1:../../devel/ruby-simplecov-html
DEPENDS+=	${RUBY_PKGPREFIX}-docile>=1.1.0<2:../../devel/ruby-docile
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov_json_formatter>=0.1<1:../../textproc/ruby-simplecov_json_formatter

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
