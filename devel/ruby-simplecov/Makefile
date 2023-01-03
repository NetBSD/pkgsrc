# $NetBSD: Makefile,v 1.28 2023/01/03 13:37:11 taca Exp $

DISTNAME=	simplecov-0.22.0
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
