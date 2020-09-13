# $NetBSD: Makefile,v 1.12 2020/09/13 15:52:06 taca Exp $

DISTNAME=	logging-2.3.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=logging/}
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.14<2:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
