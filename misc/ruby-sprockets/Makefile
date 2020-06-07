# $NetBSD: Makefile,v 1.20 2020/06/07 08:37:12 taca Exp $

DISTNAME=	sprockets-4.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0<3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
