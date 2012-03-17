# $NetBSD: Makefile,v 1.1.1.1 2012/03/17 16:29:43 taca Exp $

DISTNAME=	sprockets-2.1.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/rack-mount
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0<2:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
