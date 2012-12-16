# $NetBSD: Makefile,v 1.4 2012/12/16 16:50:07 taca Exp $

DISTNAME=	simplecov-0.7.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.7.1<0.8:../../devel/ruby-simplecov-html

RUBY_VERSION_SUPPORTED=	193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
