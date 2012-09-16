# $NetBSD: Makefile,v 1.3 2012/09/16 15:55:30 taca Exp $

DISTNAME=	sprockets-2.0.4
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/josh/rack-mount
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0<1.4:../../www/ruby-rack13
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
