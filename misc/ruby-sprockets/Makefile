# $NetBSD: Makefile,v 1.1.1.1 2011/12/15 14:44:06 taca Exp $

DISTNAME=	sprockets-2.0.3
CATEGORIES=	www

# Note: there are some problem with 2.1.0, it might be solved on 2.1.2.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/rack-mount
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
