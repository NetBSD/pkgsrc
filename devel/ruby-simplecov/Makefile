# $NetBSD: Makefile,v 1.3 2012/06/02 00:51:30 taca Exp $

DISTNAME=	simplecov-0.6.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.5.3<0.6:../../devel/ruby-simplecov-html

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
