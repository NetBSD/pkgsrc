# $NetBSD: Makefile,v 1.23 2019/11/02 14:51:05 taca Exp $

DISTNAME=	simplecov-0.17.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9+
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.10.0<0.11:../../devel/ruby-simplecov-html
DEPENDS+=	${RUBY_PKGPREFIX}-docile>=1.1.0:../../devel/ruby-docile

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	docile>=1.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
