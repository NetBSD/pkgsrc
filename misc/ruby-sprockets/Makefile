# $NetBSD: Makefile,v 1.16 2018/09/09 12:27:38 taca Exp $

DISTNAME=	sprockets-3.7.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.6<3:../../www/ruby-rack16

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
