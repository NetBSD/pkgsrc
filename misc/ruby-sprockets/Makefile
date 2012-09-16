# $NetBSD: Makefile,v 1.6 2012/09/16 06:46:45 taca Exp $

DISTNAME=	sprockets-2.4.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9]-sprockets>=2.3.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
