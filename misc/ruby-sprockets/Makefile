# $NetBSD: Makefile,v 1.14 2017/04/22 16:41:13 taca Exp $

DISTNAME=	sprockets-3.7.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.6<3:../../www/ruby-rack

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
