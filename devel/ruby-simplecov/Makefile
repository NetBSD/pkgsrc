# $NetBSD: Makefile,v 1.24 2020/02/05 15:22:28 taca Exp $

DISTNAME=	simplecov-0.18.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9+
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.11.0<0.12:../../devel/ruby-simplecov-html
DEPENDS+=	${RUBY_PKGPREFIX}-docile>=1.1.0<2.0:../../devel/ruby-docile

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	docile>=1.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
