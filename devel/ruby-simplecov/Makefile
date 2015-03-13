# $NetBSD: Makefile,v 1.11 2015/03/13 14:00:26 taca Exp $

DISTNAME=	simplecov-0.9.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.9.0<0.10:../../devel/ruby-simplecov-html
DEPENDS+=	${RUBY_PKGPREFIX}-docile>=1.1.0<1.2:../../devel/ruby-docile

RUBY_VERSION_SUPPORTED=	21 200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
