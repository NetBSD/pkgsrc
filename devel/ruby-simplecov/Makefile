# $NetBSD: Makefile,v 1.9 2015/02/02 15:07:34 taca Exp $

DISTNAME=	simplecov-0.9.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.8.0<0.9:../../devel/ruby-simplecov-html
DEPENDS+=	${RUBY_PKGPREFIX}-docile>=1.1.0<1.2:../../devel/ruby-docile

RUBY_VERSION_SUPPORTED=	21 200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
