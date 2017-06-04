# $NetBSD: Makefile,v 1.15 2017/06/04 14:46:29 taca Exp $

DISTNAME=	sprockets-3.7.1
PKGREVISION=1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.6<3:../../www/ruby-rack16

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
