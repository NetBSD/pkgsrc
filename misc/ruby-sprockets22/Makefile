# $NetBSD: Makefile,v 1.4 2015/02/04 15:37:58 taca Exp $

DISTNAME=	sprockets-2.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sprockets/sprockets22/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hike>=1.2<2:../../devel/ruby-hike
DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.4<2:../../www/ruby-rack14
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.1<2:../../textproc/ruby-tilt

OVERRIDE_GEMSPEC=	:executables sprockets=sprockets22 \
			:files bin/sprockets=bin/sprockets22
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${TEST} -f ${WRKSRC}/bin/sprockets22 || \
		${MV} ${WRKSRC}/bin/sprockets ${WRKSRC}/bin/sprockets22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
