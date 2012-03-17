# $NetBSD: Makefile,v 1.3 2012/03/17 16:42:41 taca Exp $

DISTNAME=	sprockets-2.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/rack-mount
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9]-sprockets>=2.3.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
