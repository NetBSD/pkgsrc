# $NetBSD: Makefile,v 1.10 2017/03/13 16:42:32 taca Exp $

DISTNAME=	logging-2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=logging/}
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.10:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
