# $NetBSD: Makefile,v 1.9 2015/06/08 14:48:23 taca Exp $

DISTNAME=	sprockets-3.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.6<2:../../www/ruby-rack

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
