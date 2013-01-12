# $NetBSD: Makefile,v 1.5 2013/01/12 09:14:59 taca Exp $

DISTNAME=	logging-1.8.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/logging
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3.6:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
