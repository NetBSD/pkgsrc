# $NetBSD: Makefile,v 1.2 2012/04/29 05:50:47 taca Exp $

DISTNAME=	simplecov-0.6.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby 1.9
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-simplecov-html>=0.5.3<0.6:../../devel/ruby-simplecov-html

OVERRIDE_GEMSPEC+=	:files simplecov-0.6.2.gem=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
