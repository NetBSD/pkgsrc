# $NetBSD: Makefile,v 1.8 2015/02/04 15:45:43 taca Exp $

DISTNAME=	sprockets-2.12.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.0:../../textproc/ruby-tilt

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
