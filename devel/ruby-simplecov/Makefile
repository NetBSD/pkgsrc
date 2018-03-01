# $NetBSD: Makefile,v 1.21 2018/03/01 00:20:40 taca Exp $

DISTNAME=	simplecov-0.15.1
PKGREVISION=	1
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
