# $NetBSD: Makefile,v 1.7 2014/03/14 15:56:37 taca Exp $

DISTNAME=	logging-1.8.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=logging/}
COMMENT=	Flexible logging library for Ruby based on log4j
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-little-plugger>=1.1.3:../../devel/ruby-little-plugger
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3.6:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
