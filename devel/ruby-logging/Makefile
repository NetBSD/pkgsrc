# $NetBSD: Makefile,v 1.9 2016/03/15 16:54:33 taca Exp $

DISTNAME=	logging-2.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=logging/}
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.10:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
